1、test_vfork.c是测试vfork()，退出子进程时，不同的方式对父进程的影响
	1）_exit()
		运行结果：
		child pid=23772
		&g=0x80498ac &s=0xbfdb7a58 &k=0x80498b0
		child after g=100,s=200,k=300
		parent pid=23771
		&g=0x80498ac &s=0xbfdb7a58 &k=0x80498b0
		parent after g=100,s=200,k=300

		解释：vfork是子进程一定是先于父进程执行，并且正常退出

	2）exit()
		运行结果：
		child pid=26167
		&g=0x80498ac &s=0xbfc871d8 &k=0x80498b0
		child after g=100,s=200,k=300
		parent pid=26166
		&g=0x80498ac &s=0xbfc871d8 &k=0x80498b0
		parent after g=100,s=200,k=300

		正常退出

	3）return
		运行进入一个无限循环

	解释：调用子进程，如果使用return返回，就意味着main函数返回了，因为栈是父子进程共享的，所以程序的函数栈发生了变化。main函数return之后，通常会调用exit系的函数，父进程收到子进程的exit之后，就会开始从vfork返回，但是这时整个main函数的栈都已经不复存在了，所以父进程压根无法执行。于是会返回一个诡异的栈地址，对于在某些内核版本中，进程会直接报栈错误然后退出，但是在某些内核版本中，有可能就会再次进出main，于是进入一个无限循环，直到vfork返回错误。

2、test_deadlock.c是测试vfork可能会陷入死锁
vfork已经决定了子进程先于父进程，父进程阻塞，如果子进程还一直等待父进程的值，就会产生死锁

3、son_exec.c和test.c是测试子进程使用exec()来覆盖调用者，对程序的影响



