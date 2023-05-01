# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/clement/Desktop/vielsprachig/build/_deps/opencv_package_emscripten-src"
  "/home/clement/Desktop/vielsprachig/build/_deps/opencv_package_emscripten-build"
  "/home/clement/Desktop/vielsprachig/build/_deps/opencv_package_emscripten-subbuild/opencv_package_emscripten-populate-prefix"
  "/home/clement/Desktop/vielsprachig/build/_deps/opencv_package_emscripten-subbuild/opencv_package_emscripten-populate-prefix/tmp"
  "/home/clement/Desktop/vielsprachig/build/_deps/opencv_package_emscripten-subbuild/opencv_package_emscripten-populate-prefix/src/opencv_package_emscripten-populate-stamp"
  "/home/clement/Desktop/vielsprachig/build/_deps/opencv_package_emscripten-subbuild/opencv_package_emscripten-populate-prefix/src"
  "/home/clement/Desktop/vielsprachig/build/_deps/opencv_package_emscripten-subbuild/opencv_package_emscripten-populate-prefix/src/opencv_package_emscripten-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/clement/Desktop/vielsprachig/build/_deps/opencv_package_emscripten-subbuild/opencv_package_emscripten-populate-prefix/src/opencv_package_emscripten-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/clement/Desktop/vielsprachig/build/_deps/opencv_package_emscripten-subbuild/opencv_package_emscripten-populate-prefix/src/opencv_package_emscripten-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
