# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION ${CMAKE_VERSION}) # this file comes with cmake

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "/home/lemoechun/code/test/slint-cpp-template-main/_deps/slint-src")
  file(MAKE_DIRECTORY "/home/lemoechun/code/test/slint-cpp-template-main/_deps/slint-src")
endif()
file(MAKE_DIRECTORY
  "/home/lemoechun/code/test/slint-cpp-template-main/_deps/slint-build"
  "/home/lemoechun/code/test/slint-cpp-template-main/_deps/slint-subbuild/slint-populate-prefix"
  "/home/lemoechun/code/test/slint-cpp-template-main/_deps/slint-subbuild/slint-populate-prefix/tmp"
  "/home/lemoechun/code/test/slint-cpp-template-main/_deps/slint-subbuild/slint-populate-prefix/src/slint-populate-stamp"
  "/home/lemoechun/code/test/slint-cpp-template-main/_deps/slint-subbuild/slint-populate-prefix/src"
  "/home/lemoechun/code/test/slint-cpp-template-main/_deps/slint-subbuild/slint-populate-prefix/src/slint-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/lemoechun/code/test/slint-cpp-template-main/_deps/slint-subbuild/slint-populate-prefix/src/slint-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/lemoechun/code/test/slint-cpp-template-main/_deps/slint-subbuild/slint-populate-prefix/src/slint-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
