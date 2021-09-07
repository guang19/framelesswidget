#!/bin/sh

Build_Type=$1
Debug="debug"
Release="release"

if [[ "$Build_Type" != "$Debug" &&  "$Build_Type" != "$Release" ]];then
  echo "请指定构造类型build type（debug或release）"
  exit 1
fi

cd src

echo "正在创建build目录..."
if [ -d "build" ];then
   if [ ! -d "$Build_Type" ]; then
      mkdir -p build/$Build_Type
   fi
else
   mkdir -p build/$Build_Type
fi
echo "创建build目录完成"

#进入编译目录
cd build/$Build_Type

echo "开始编译..."
cmake ../../
echo "编译完成"

echo "开始制作链接库文件..."
make
echo "链接库文件制作完成"