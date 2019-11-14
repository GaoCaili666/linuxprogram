1、1-1.c:探究_exit()的作用
编译运行结果：
[root@localhost code]# gcc _exit.c -o _exit
[root@localhost code]# ./_exit 
[root@localhost code]# cat test.txt
[root@localhost code]# 
test.txt的内容为空，说明执行_exit()函数并没有刷新缓冲区的数据，而是直接终止进程的

2、1-2.c:探究exit()的作用
编译运行结果：
[root@localhost code]# gcc exit.c -o exit
[root@localhost code]# ./exit
[root@localhost code]# cat test.txt
hello world[root@localhost code]# 
说明exit()函数结束进程的时候，对缓存进行了处理，把缓存的数据写到了磁盘文件中

3、1-3.c是测试_exit()、exit()以及return的作用
编译运行结果：
[root@localhost code]# gcc 1-3.c -o 1-3
[root@localhost code]# ./1-3
bar says bye.
foo says bye.
Oops~~~~~~~~forget a newline[root@localhost code]# ./1-3 exit
bar says bye.
foo says bye.
Oops~~~~~~~~forget a newline[root@localhost code]# ./1-3 _exit
[root@localhost code]# 

执行return(n)等同于执行exit(n)，因为调用main()的运行时函数会将main的返回值当作exit的参数。
无论是调用return返回还是调用exit返回，缓冲区里的数据都会被冲刷，“Oops...forgot a newline！”都会被输出。说明exit()函数会执行用户通过调用atexit函数的清理函数麻将缓冲的数据均被写入(flush)，而_exit()并不会

4、1-4.c是测试使用vfork()函数时，子进程如果返回，则不要调用return，而应该使用_exit函数。如果使用return，就会出现诡异的错误，我的centos运行该程序会出现无限循环
查阅资料后，对于该结果做如下解释：
调用子进程，如果使用return返回，就意味着main函数返回了，因为栈是父子进程共享的，所以程序的函数栈发生了变化。main函数return之后，通常会调用exit系的函数，父进程收到子进程的exit之后，就会开始从vfork返回，但是这时整个main函数的栈都已经不复存在了，所以父进程压根无法执行。于是会返回一个诡异的栈地址，对于在某些内核版本中，进程会直接报栈错误然后退出，但是在某些内核版本中，有可能就会再次进出main，于是进入一个无限循环，直到vfork返回错误。




