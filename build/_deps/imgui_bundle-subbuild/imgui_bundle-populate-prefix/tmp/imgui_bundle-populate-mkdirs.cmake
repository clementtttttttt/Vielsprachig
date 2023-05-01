# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/clement/Desktop/vielsprachig/build/_deps/imgui_bundle-src"
  "/home/clement/Desktop/vielsprachig/build/_deps/imgui_bundle-build"
  "/home/clement/Desktop/vielsprachig/build/_deps/imgui_bundle-subbuild/imgui_bundle-populate-prefix"
  "/home/clement/Desktop/vielsprachig/build/_deps/imgui_bundle-subbuild/imgui_bundle-populate-prefix/tmp"
  "/home/clement/Desktop/vielsprachig/build/_deps/imgui_bundle-subbuild/imgui_bundle-populate-prefix/src/imgui_bundle-populate-stamp"
  "/home/clement/Desktop/vielsprachig/build/_deps/imgui_bundle-subbuild/imgui_bundle-populate-prefix/src"
  "/home/clement/Desktop/vielsprachig/build/_deps/imgui_bundle-subbuild/imgui_bundle-populate-prefix/src/imgui_bundle-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/clement/Desktop/vielsprachig/build/_deps/imgui_bundle-subbuild/imgui_bundle-populate-prefix/src/imgui_bundle-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/clement/Desktop/vielsprachig/build/_deps/imgui_bundle-subbuild/imgui_bundle-populate-prefix/src/imgui_bundle-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
