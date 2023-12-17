set -e

cd "/cygdrive/d/CLionProjects/Flight management system/cmake-build-debug"
/cygdrive/c/Users/carlo/AppData/Local/JetBrains/CLion2023.2/cygwin_cmake/bin/cmake.exe --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
