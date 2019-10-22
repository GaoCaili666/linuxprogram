在和库文件不同的目录下实现使用静态库或动态库生成可执行文件

remotestatictest.c：在和静态库文件不同目录下，测试静态库中的函数
remotedytest1.c：在和动态库文件不同目录下，测试动态库中的函数
remotedytest2.c：在该文件中直接打开动态库，调用动态库中的函数，来测试动态库中的函数

remotestatictest、remotedytest1、remotedytest2分别是对应的可执行文件