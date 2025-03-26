#!/bin/bash

# Set the output directory
BUILD_DIR="build"
EXECUTABLE="book_db"

# Compiler options
CC="gcc"
CFLAGS="-O -W -Wall"
DEBUG=0  # Set to 1 for debugging mode

# Enable debugging if set
if [ "$DEBUG" -eq 1 ]; then
  CFLAGS="$CFLAGS -g"
fi 

# Create the build directory if it doesn't exist
mkdir -p "$BUILD_DIR"

# Find all .c files
SOURCES=$(find . -name "*.c")

# Compile the program
echo "⚙  Compiling..."
$CC $CFLAGS $SOURCES -o "$BUILD_DIR/$EXECUTABLE"

# Check if compilation was successful
if [ $? -eq 0 ]; then 
  echo "✔  Build successful 👍 ! Executable at: $BUILD_DIR/$EXECUTABLE 🚀 ."
else 
  echo "❌ Build failed 😞 !"
  exit 1
fi 


