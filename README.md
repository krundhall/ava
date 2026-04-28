# C++ Template

## After cloning

1. Rename the project in `CMakeLists.txt`:
   ```cmake
   project(YourProjectName)
   ```

2. Build:
   ```bash
   cmake --preset asan
   cmake --build --preset asan
   ```

3. Run:
   ```bash
   ./build/asan/bin/YourProjectName
   ```
