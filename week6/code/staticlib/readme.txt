练习静态库，使用静态库在同一目录下生成可执行文件

mylib.h是头文件
aoprand.c：里面有max()和sum()函数，分别求数组的最大值和总和
base.c：里面有两个函数：init()使用随机函数生成随机数初始化数组；show()用于显示数组

aoprand.o和base.o分别是使用aoprand.c和base.c生成的

libmytest.a是使用aoprand.o和base.o两个文件生成的静态库
localstatictest.c是测试文件，简单的对init()、show()、max()、sum()这些函数进行了调用

localstatictest是和静态库在同一目录下，使用静态库生成的可执行文件

