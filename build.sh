#!/bin/bash

# Clean previous build if exists
if [ -d "build" ]; then
    rm -rf build
fi

# Create build directory
mkdir -p build
cd build || exit 1

# Configure and build with CMake
cmake ..
make

echo "Build complete. Run with: ./build/centrality"

# Return to the original directory
cd ..

# Make the script executable
chmod +x build.sh 