#!/bin/bash

# Set the build directory
BUILD_DIR="build"

if [ -d "$BUILD_DIR" ]; then
  echo "🤗 Removing build directory ... "

  rm -rf "$BUILD_DIR" 

  echo "✔  Uninstall complete. Removed $BUILD_DIR/ !"
else
  echo "🤔 Build directory does not exist. Nothing to uninstall."
fi 


  
