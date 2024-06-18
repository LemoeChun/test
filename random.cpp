#include <random>
#include <iostream>

int main() {
    std::random_device seed;
    std::mt19937_64 gen{seed()}; // seed the generator
    std::uniform_int_distribution<> dist{10, 11}; // set min and max
    int guess = dist(gen); // generate number
    std::cout << "Computer guess: " << guess << '\n';
          }
