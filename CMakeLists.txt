cmake_minimum_required(VERSION 3.12)
project(vielsprachig)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXECUTABLE_SUFFIX ".html")

file(GLOB_RECURSE pugixml_sources ${CMAKE_SOURCE_DIR}/pugixml/src/*.cpp)
add_library(pugixml STATIC ${pugixml_sources})

include_directories(pugixml/src/)
include_directories(libarchive/libarchive/)


set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -sUSE_ZLIB=1 -sTOTAL_MEMORY=128MB -sALLOW_MEMORY_GROWTH=1 -sEXPORTED_FUNCTIONS=_main,_malloc,_free -sEXPORTED_RUNTIME_METHODS=ccall,cwarp")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -sTOTAL_MEMORY=128MB -sALLOW_MEMORY_GROWTH=1 -sEXPORTED_FUNCTIONS=_main,_malloc,_free -sEXPORTED_RUNTIME_METHODS=ccall,cwarp")

set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -sEXPORTED_FUNCTIONS=_main,_malloc,_free -sALLOW_MEMORY_GROWTH=1 -sEXPORTED_RUNTIME_METHODS=ccall,cwarp")

add_subdirectory(libarchive)

link_directories(libarchive)

# Prepare hello_imgui during configure time
##########################################################
include(FetchContent)

FetchContent_Declare(
    imgui_bundle
    GIT_REPOSITORY https://github.com/pthom/imgui_bundle
    # Enter the desired git tag below
    GIT_TAG main
)
FetchContent_MakeAvailable(imgui_bundle)
# Make cmake function `hello_imgui_add_app` available
list(APPEND CMAKE_MODULE_PATH ${IMGUIBUNDLE_CMAKE_PATH})
include(imgui_bundle_add_app)




##########################################################
# Build your app
##########################################################

imgui_bundle_add_app(vielsprachig main.cpp lexicon.cpp lexi_find.cpp)

target_link_libraries(vielsprachig PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/libarchive/libarchive/libarchive.a)

target_link_libraries(vielsprachig PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/libpugixml.a)
