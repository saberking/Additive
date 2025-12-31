# DISTRHO Plugin Framework (DPF)
# Copyright (C) 2021 Jean Pierre Cimalando <jp-dev@inbox.ru>
# Copyright (C) 2021-2025 Filipe Coelho <falktx@falktx.com>
# SPDX-License-Identifier: ISC

cmake_minimum_required(VERSION 3.7...3.31)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_BUILD_TYPE Debug)

set(NAME Additive)

# Allow toolchain file to be specified via -DCMAKE_TOOLCHAIN_FILE=
if(NOT CMAKE_TOOLCHAIN_FILE AND DEFINED ENV{CMAKE_TOOLCHAIN_FILE})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{CMAKE_TOOLCHAIN_FILE}" CACHE FILEPATH "Toolchain file")
endif()
project(${NAME})

find_package(Python3)



# Read the list of files to process with Cog
file(GLOB_RECURSE COG_FILES
    "src/*"
)

# Define a stamp file that will be touched when Cog finishes
set(COG_STAMP "${CMAKE_CURRENT_BINARY_DIR}/cog.stamp")
set(PYTHON_EXECUTABLE python3)

# Custom command that runs Cog and creates the stamp file
add_custom_command(
    OUTPUT ${COG_STAMP}
    COMMAND ${PYTHON_EXECUTABLE} -m cogapp -r ${COG_FILES}
    COMMAND ${CMAKE_COMMAND} -E touch ${COG_STAMP}  # Create/update stamp
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    DEPENDS ${COG_FILES} files_to_cog.txt               # Re-run if list or sources change
    COMMENT "Running Cog - generating code before compile..."
    VERBATIM
)

# Optional: make it part of the default build (ALL) so it always runs when building anything
# Remove ALL if you want to trigger it manually sometimes
add_custom_target(cog ALL DEPENDS ${COG_STAMP})

# Add your real source files to the target
target_sources(cog PRIVATE ${COG_FILES})

# CRITICAL: Make the sources depend on the stamp file
# This forces Cog to run before any of these files are compiled
target_sources(cog PRIVATE ${COG_STAMP})

set_property(TARGET cog APPEND PROPERTY ADDITIONAL_CLEAN_FILES ${COG_STAMP})

# add_compile_definitions(BOOST_USE_WINDOWS_H)
# add_compile_definitions(WIN32_LEAN_AND_MEAN)
add_subdirectory(dpf)

set(TARGETS_LIST "vst3")

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    list(APPEND TARGETS_LIST "jack")
endif()

foreach(tgt IN LISTS TARGETS_LIST)
    if(TARGET ${tgt})
        add_dependencies(${tgt} cog)
    endif()
endforeach()

dpf_add_plugin(${NAME}
  TARGETS ${TARGETS_LIST}
  FILES_DSP
      src/Additive.cpp
  FILES_UI
      src/AdditiveUI.cpp
      ImGuiFileDialog/ImGuiFileDialog.cpp
      dpf-widgets/opengl/DearImGui.cpp)

target_include_directories(${NAME} PUBLIC src)
target_include_directories(${NAME} PUBLIC dpf-widgets/generic)
target_include_directories(${NAME} PUBLIC dpf-widgets/opengl)
target_include_directories(${NAME} PUBLIC dpf-widgets/opengl/DearImGui)

