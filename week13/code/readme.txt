13-1.c：signal()绑定信号处理函数
13-2.c：sigaction()绑定信号处理函数
13-3.c和13-4.c：信号可靠性的实验
13-5.c：本例中的信号处理函数中，info->si_pid记录着信号发送者的PID，info->si_value.sival_int是信号发送进程时额外发送的int值。发送进程和接收进程约定好，发送者使用sigqueue发送信号，同时带上int型的额外信息，接收进程就能获得发送进程的PID及int型的额外信息
13-6.c：
编译： gcc -o 13-6 -DUSE_SIGACTION 13-6.c
chmod +x ./13-6.sh
./13-6.sh

tkill是发给具体线程的，信号会挂在线程私有的挂起信号队列上，所以会优先递送，因此44号信号应该第一个被递送；其他的信号中4=SIGILL、5=SIGTRAP、7=SIGBUS、8=SIGFPE、11=SIGSEGV、31=SIGSYS，这些都属于同步信号集合；紧随44号信号之后，按照从小到大的顺序递送；2、3、10、12、24作为非实时信号，再随其后被递送；最后是实时信号，按照从小到大的顺序（即36、37、38、39），依次递送给进程。

输出结果
[root@localhost code]# ./test_order.sh
./sigaction_delivery_order:PID is 21897
sigaction for signo(32) failed (Invalid argument)
sigaction for signo(33) failed (Invalid argument)
I will sleep 30 second
[root@localhost code]# #0: signo=44
#1: signo=4
#2: signo=5
#3: signo=7
#4: signo=8
#5: signo=11
#6: signo=31
#7: signo=2
#8: signo=3
#9: signo=10
#10: signo=12
#11: signo=24
#12: signo=36
#13: signo=37
#14: signo=38
#15: signo=39