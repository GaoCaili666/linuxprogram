test.c和call.c是测试system()方法调用可执行文件是派生新进程还是用被调用者的代码替代调用者。
如果是派生新进程两个输出的pid和ppid是不一样的
如果是替代，test的pid、ppid是和call的pid、ppid一样，并且不会输出after calling

输出结果：
call:pid=10148,ppid=7096
test:pid=10149,ppid=10148
after calling


所以system()会派生新进程
