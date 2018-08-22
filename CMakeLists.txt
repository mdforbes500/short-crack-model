# Set the name of the project and target:
SET(TARGET "scmod")

# Include headers
INCLUDE_DIRECTORIES(include)

# Include sources
FILE(GLOB_RECURSE TARGET_SRC  "src/*.cc")
FILE(GLOB_RECURSE TARGET_INC  "include/*.h")
SET(TARGET_SRC ${TARGET_SRC}  ${TARGET_INC})

#Minimum required CMake Version
CMAKE_MINIMUM_REQUIRED(VERSION 2.8.12)
# Declare project
PROJECT(${TARGET})

# Create Executables
# Main Porgram Executable
ADD_EXECUTABLE(${TARGET} src/main.cc)

# Move Executables into /bin
INSTALL(TARGETS ${TARGET} DESTINATION ${CMAKE_BINARY_DIR}/../bin)
