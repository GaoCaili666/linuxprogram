1、test1.c测试结果：
Running before main
test1:pid= 13137,ppid= 12349
1:Running after main
1:Running after main
1:Running after main

2、test2.c和test1.c代码一样，就是再最后加了一个死循环，

3、call1.c用system函数执行test2
运行结果：
call1:pid=13199, ppid=12349
Running before main
test2:pid= 13200,ppid= 13199
^Cafter calling! ret=2
因为是Ctrl+C退出的，所以ret=2，不正常退出.正常是0

4、call2.c用execvp函数执行test2
没将当前路径添加到PATH，运行结果：
call1:pid=3044, ppid=3011
after calling! ret=-1

ret=-1，调用test2失败，没有执行
将当前路径添加到PATH中，PATH=$PATH:/root/Desktop/linux/第9周/Tuesday，重启系统之后会删除
运行结果：
call1:pid=3074, ppid=3011
Running before main
test2:pid= 3074,ppid= 3011
^C
调用成功

5、memtest.c是测试内存问题的
valgrind --track-fds=yes --leak-check=full --undef-value-errors=yes ./memtest

6、longjmp1.c是测试longjmp函数的
运行结果：
Normal flow
Enter func1
Enter func2
long jump flow

7、longjmp2.c
gcc longjmp2.c -o longjmp2编译，运行，无任何编译优化
运行结果：
Normal flow
1:a=1, b=2, c=3
Enter func1
func1:a=2, b=3, c=4
long jump flow
2:a=2, b=3, c=4

gcc longjmp2.c -o longjmp21 -Wall -O2编译，运行，第二级优化
Normal flow
1:a=1, b=2, c=3
Enter func1
func1:a=2, b=3, c=4
long jump flow
2:a=1, b=2, c=3












