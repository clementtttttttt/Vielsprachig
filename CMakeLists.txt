cmake_minimum_required(VERSION 3.12)
project(vielsprachig)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXECUTABLE_SUFFIX ".html")
set(ENABLE_WERROR, FALSE)
set(CMAKE_COMPILE_WARNING_AS_ERROR FALSE)
set(CMAKE_BUILD_TYPE Release)

set(LIBARCHIVE_INCLUDE_DIR "/usr/lib")

file(GLOB_RECURSE pugixml_sources ${CMAKE_SOURCE_DIR}/pugixml/src/*.cpp)
add_library(pugixml STATIC ${pugixml_sources})

set(CMAKE_C_FLAGS "-Wno-error -w -sTOTAL_MEMORY=134217728 ${CMAKE_C_FLAGS} -O3 -sUSE_ZLIB=1  -Wno-unused-command-line-argument ")
set(CMAKE_CXX_FLAGS "-Wno-error -w ${CMAKE_CXX_FLAGS} -O3 -Wno-unused-command-line-argument -Wl,--max-memory=134217728 -sEXPORTED_RUNTIME_METHODS=ccall,cwarp,spoof_event -sEXPORTED_FUNCTIONS=_main,_malloc,_free")
set(CMAKE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -O3 -sTOTAL_MEMORY=134217728 -sMAXIMUM_MEMORY=134217728 -sEXPORTED_FUNCTIONS=_main,_malloc,_free -sALLOW_MEMORY_GROWTH=1 -sEXPORTED_RUNTIME_METHODS=ccall,cwarp,spoof_event --shell-file=shell.emscripten.html -sTOTAL_MEMORY=134217728 -sMAXIMUM_MEMORY=134217728 ")

include_directories(pugixml/src/)
include_directories(libarchive/libarchive/)

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

set(ENABLE_WERROR, FALSE)
set(CMAKE_COMPILE_WARNING_AS_ERROR FALSE)

##########################################################
# Build your app
##########################################################

imgui_bundle_add_app(vielsprachig main.cpp lexicon.cpp lexi_find.cpp
	lexi_conjugator.cpp phono.cpp pos.cpp pos_reged.cpp)

target_link_libraries(vielsprachig PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/libarchive/libarchive/libarchive.a)

target_link_libraries(vielsprachig PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/libpugixml.a)
