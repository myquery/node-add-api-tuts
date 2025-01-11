cmake_minimum_required(VERSION 3.16)

project(node-api-tuts)

# Include CMake.js and addon directories
include_directories(${CMAKE_JS_INC})
include_directories(${CMAKE_SOURCE_DIR}/addons)

# Specify the path to the node-addon-api headers
include_directories(${CMAKE_SOURCE_DIR}/node_modules/node-addon-api)

# Gather all addon source files
file(GLOB ADDON_SOURCES "addons/*.cpp")

# Add the shared library target for Node.js
add_library(${PROJECT_NAME} SHARED ${ADDON_SOURCES})

# Link Node-Addon-API library
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/node_modules/node-addon-api)

# Set properties for .node output
set_target_properties(${PROJECT_NAME} PROPERTIES
    PREFIX ""
    SUFFIX ".node"
)
