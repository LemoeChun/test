#include <uWebSockets/App.h>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <filesystem> // C++17 文件系统操作
#include <random>     // 随机数生成
#include <chrono>     // 用于随机数种子

// 指定图片文件夹路径
const std::string IMAGE_DIRECTORY = "setu/"; // <-- 请确保这个文件夹存在且包含图片

// 辅助函数，用于读取文件内容到内存
std::vector<char> read_file(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary | std::ios::ate);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return {};
    }

    // 获取文件大小
    std::streamsize size = file.tellg();
    if (size == -1) {
         std::cerr << "Error getting file size: " << filename << std::endl;
         return {};
    }

    std::vector<char> buffer(size);

    // 移动文件指针到文件开头并读取
    file.seekg(0, std::ios::beg);
    if (!file.read(buffer.data(), size)) {
        std::cerr << "Error reading file: " << filename << std::endl;
        return {};
    }

    return buffer;
}

// 辅助函数，根据文件扩展名获取 Content-Type
std::string get_content_type(const std::string& filename) {
    std::filesystem::path file_path(filename);
    std::string ext = file_path.extension().string();
    // 将扩展名转为小写进行比较
    for (char &c : ext) {
        c = std::tolower(c);
    }

    if (ext == ".jpg" || ext == ".jpeg") {
        return "image/jpeg";
    } else if (ext == ".png") {
        return "image/png";
    } else if (ext == ".gif") {
        return "image/gif";
    } else if (ext == ".bmp") {
        return "image/bmp";
    } else if (ext == ".webp") {
        return "image/webp";
    }
    // 可以根据需要添加更多图片类型
    return "application/octet-stream"; // 默认二进制流
}

// 辅助函数，列出指定目录中的图片文件路径
std::vector<std::string> list_image_files(const std::string& directory_path) {
    std::vector<std::string> image_files;
    try {
        if (std::filesystem::exists(directory_path) && std::filesystem::is_directory(directory_path)) {
            for (const auto& entry : std::filesystem::directory_iterator(directory_path)) {
                if (std::filesystem::is_regular_file(entry.path())) {
                    std::string filename = entry.path().string();
                    std::string content_type = get_content_type(filename);
                    // 检查 Content-Type 是否为图片类型
                    if (content_type.rfind("image/", 0) == 0) { // 检查是否以 "image/" 开头
                        image_files.push_back(filename);
                    }
                }
            }
        } else {
            std::cerr << "Directory not found or is not a directory: " << directory_path << std::endl;
        }
    } catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "Filesystem error: " << e.what() << std::endl;
    }
    return image_files;
}

int main() {
    // 初始化随机数生成器
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine rng(seed);

    uWS::App()
    .get("/random_image", [&rng](auto *res, auto *req) {
        // 每次请求时获取图片文件列表
        std::vector<std::string> image_files = list_image_files(IMAGE_DIRECTORY);

        if (image_files.empty()) {
            std::cerr << "No image files found in directory: " << IMAGE_DIRECTORY << std::endl;
            res->writeStatus("404 Not Found");
            res->end("No images available.");
            return;
        }

        // 随机选择一个文件
        std::uniform_int_distribution<size_t> dist(0, image_files.size() - 1);
        size_t random_index = dist(rng);
        const std::string& selected_image_path = image_files[random_index];

        // 读取选中的图片文件内容
        std::vector<char> image_data = read_file(selected_image_path);

        if (image_data.empty()) {
            std::cerr << "Failed to read image data from: " << selected_image_path << std::endl;
            res->writeStatus("500 Internal Server Error");
            res->end("Error reading image file.");
            return;
        }

        // 获取 Content-Type
        std::string content_type = get_content_type(selected_image_path);

        // 设置响应头
        res->writeStatus("200 OK");
        res->writeHeader("Content-Type", content_type);
        res->writeHeader("Content-Length", std::to_string(image_data.size()));

        // 发送图片数据
        res->end(std::string_view(image_data.data(), image_data.size()));
    })
    .listen(3000, [](auto *listenSocket) {
        if (listenSocket) {
            std::cout << "Listening on port 3000" << std::endl;
        } else {
            std::cerr << "Failed to listen on port 3000" << std::endl;
        }
    })
    .run();

    std::cout << "Server stopped." << std::endl;

    return 0;
}
