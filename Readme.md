Qt实现的跨平台无边框窗口，目前支持Liunx（x11），windows

开发环境：
1. Linux5.13.x
3. Compiler： GCC/Clang
4. Maker: CMake/Make
2. WM/DE： PLASMA/KDE/X11


在编译时请将CMakeLists的CMAKE_BUILD_TYPE选项改为当前环境DEBUG/RELEASE

Linux：
````
chmod +x build.sh
./build.sh debug/release
cd sample
chmod +x run.sh
./run.sh debug/release
````

Windows：
请先指定CMakeLists的编译器目录和cmake目录再执行以下命令。
````
1.在src下创建build目录，并在build目录下新建debug或release目录
2.进入src/build/debug或release目录，先执行 cmake -G "MinGW Makefiles" ../../，
  再执行mingw32-make
3.在sample目录下新建build目录和lib目录，并在build目录下新建debug或release目录
4.将src/build/debug(release)/shared下编译好的所有的库文件复制到sample/lib下
5.进入sample/build/debug或release目录先执行cmake -G "MinGW Makefiles" ../../
  再执行mingw32-make
6.在sample/build/debug(release)/bin下执行 sample
````