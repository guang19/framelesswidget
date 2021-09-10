Qt实现的Linux平台下的无边框窗口组件，支持x11

开发环境：
1. Linux 5.13.x
3. Compiler： GCC 11.1.0
4. Maker: CMake/Make
2. WM/DE： PLASMA/KDE/X11


在编译时请将CMakeLists的CMAKE_BUILD_TYPE选项改为当前环境DEBUG/RELEASE

````
chmod +x build.sh
./build.sh debug/release
cd sample
chmod +x run.sh
./run.sh debug/release
````