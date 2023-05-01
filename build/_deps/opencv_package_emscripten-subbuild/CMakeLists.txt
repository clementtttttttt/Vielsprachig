# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.26.3)

# We name the project and the target for the ExternalProject_Add() call
# to something that will highlight to the user what we are working on if
# something goes wrong and an error message is produced.

project(opencv_package_emscripten-populate NONE)



include(ExternalProject)
ExternalProject_Add(opencv_package_emscripten-populate
                     "UPDATE_DISCONNECTED" "False" "DOWNLOAD_EXTRACT_TIMESTAMP" "ON" "URL" "https://github.com/pthom/imgui_bundle/releases/download/v0.7.2/opencv_4.7.0_emscripten_install.tgz" "URL_MD5" "3e109af66b4938959f1d7a1db0ea13da"
                    SOURCE_DIR          "/home/clement/Desktop/vielsprachig/build/_deps/opencv_package_emscripten-src"
                    BINARY_DIR          "/home/clement/Desktop/vielsprachig/build/_deps/opencv_package_emscripten-build"
                    CONFIGURE_COMMAND   ""
                    BUILD_COMMAND       ""
                    INSTALL_COMMAND     ""
                    TEST_COMMAND        ""
                    USES_TERMINAL_DOWNLOAD  YES
                    USES_TERMINAL_UPDATE    YES
                    USES_TERMINAL_PATCH     YES
)


