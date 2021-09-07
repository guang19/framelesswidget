#!/bin/sh

Build_Type=$1
Debug="debug"
Release="release"

if [[ "$Build_Type" != "$Debug" && "$Build_Type" != "$Release" ]];then
  echo "请指定构造类型run type（debug或release）"
  exit 1
fi

echo "正在创建build目录..."
if [ -d "build" ];then
   if [ ! -d "$Build_Type" ]; then
      mkdir -p build/$Build_Type
   fi
else
   mkdir -p build/$Build_Type
fi
echo "创建build目录完成"

echo "正在复制lib文件..."
if [ ! -d "lib" ];then
  mkdir lib
fi

cp -f ../src/build/$Build_Type/shared/*.so lib
if [ "$?" != "0" ]; then
    echo "复制lib文件失败：找不到相应的库文件"
    exit 1
fi
echo "复制lib文件完成"


#进入编译目录
cd build/$Build_Type

echo "开始编译..."
cmake ../../
echo "编译完成"

echo "开始制作链接库文件..."
make
echo "链接库文件制作完成"

echo "开始执行sample"
cd bin
./sample
