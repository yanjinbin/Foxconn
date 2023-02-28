cmake_minimum_required(VERSION 3.15)
project(Foxconn)

set(CMAKE_CXX_STANDARD 14)
include_directories(
        "./QuikTemplate.cpp"
)

# 遍历项目根目录下所有的 .cpp 文件
# 如果你只有两层目录的话
file(GLOB files *.cpp */*.cpp)
# 同理，三层的话
file(GLOB files *.cpp */*.cpp */*/*.cpp)
foreach (file ${files})
    string(REGEX REPLACE ".+/(.+)/(.+)\\..*" "\\1-\\2" exe ${file})
    message(STATUS ${file})
    add_executable(${exe} ${file})
    message(\ \ \ \ --\ src/${exe}.cpp\ will\ be\ compiled\ to\ bin/${exe})
endforeach ()

#附录参考: ⚠️ 如果main左边没有出现执行按钮 记得点击cmake栏的reload！！！！！
#1. https://tinyurl.com/y4rmyful
#2. https://tinyurl.com/y3vkjbaq

