cmake_minimum_required(VERSION 3.12)
project(vielsprachig)
set(CMAKE_CXX_STANDARD 17)
set(ENABLE_WERROR, FALSE)
set(CMAKE_COMPILE_WARNING_AS_ERROR FALSE)
set(CMAKE_BUILD_TYPE Release)


file(GLOB_RECURSE pugixml_sources ${CMAKE_SOURCE_DIR}/pugixml/src/*.cpp)
add_library(pugixml STATIC ${pugixml_sources})
# -Wl,--max-memory=134217728  
set(CMAKE_C_FLAGS "-Wno-error -w ${CMAKE_C_FLAGS} -O3  -Wno-unused-command-line-argument ")
set(CMAKE_CXX_FLAGS "-Wno-error -w ${CMAKE_CXX_FLAGS} -O3 -Wno-unused-command-line-argument ")
set(CMAKE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -O3 ")

if(EMSCRIPTEN)
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -sEXPORTED_RUNTIME_METHODS=ccall -sEXPORTED_FUNCTIONS=_main,_malloc,_free")
	set(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} -sEXPORTED_RUNTIME_METHODS=ccall -sEXPORTED_FUNCTIONS=_main,_malloc,_free -sALLOW_MEMORY_GROWTH=1  --shell-file=shell.emscripten.html ")
	
	set(CMAKE_EXECUTABLE_SUFFIX ".html")
	set(LIBARCHIVE_INCLUDE_DIR "/usr/lib")
	include_directories(libarchive/libarchive/)
	add_subdirectory(libarchive)
	
	link_directories(libarchive)

else()
	find_package(libarchive)
endif()



include_directories(pugixml/src/)


set(IMGUI_BUNDLE_DISABLE_IMMVISION ON CACHE BOOL "" FORCE) 
set(IMGUI_BUNDLE_DISABLE_IMGUIZMO ON CACHE BOOL "" FORCE) 

# Prepare hello_imgui during configure time
##########################################################
if (NOT TARGET imgui_bundle)
    message(STATUS "Fetching imgui_bundle...")
    include(FetchContent)
    Set(FETCHCONTENT_QUIET FALSE)
    FetchContent_Declare(imgui_bundle GIT_REPOSITORY https://github.com/pthom/imgui_bundle.git GIT_TAG main)
    FetchContent_MakeAvailable(imgui_bundle)

    # Uncomment the next line if you which to also automatically fetch and compile OpenCV for immvision support
    # set(IMMVISION_FETCH_OPENCV ON)
endif()


  #  FetchContent_Declare(imfiledialog GIT_REPOSITORY https://github.com/aiekick/ImGuiFileDialog GIT_TAG master)
   # FetchContent_MakeAvailable(imfiledialog)

set(ENABLE_WERROR, FALSE)
set(CMAKE_COMPILE_WARNING_AS_ERROR FALSE)

##########################################################
# Build your app
##########################################################

imgui_bundle_add_app(vielsprachig main.cpp lexicon.cpp lexi_find.cpp
	lexi_conjugator.cpp emscripten_spec.cpp phono.cpp pos.cpp pos_reged.cpp)

if (EMSCRIPTEN)
	target_link_libraries(vielsprachig PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/libarchive/libarchive/libarchive.a)
else()
	target_link_libraries(vielsprachig PUBLIC archive)
endif()

target_link_libraries(vielsprachig PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/libpugixml.a)
