1、1-5.c测试exit()、_exit()、return执不执行构造函数、析构函数、atexit()函数，刷不刷新缓冲区
	1）exit()
		运行结果：
		--------constructor--------
		printf: data from line buffer--------callback2--------
		--------callback1--------
		--------desstructor--------

		test data from full buffer  被写入test.txt
	2）_exit()
		运行结果：
		--------constructor--------

		test data from full buffer  没有被写入test.txt
	3）return
		运行结果：
		--------constructor--------
		printf: data from line buffer--------callback2--------
		--------callback1--------
		--------desstructor--------

		test data from full buffer  被写入test.txt

结论：exit()和return执行构造函数、析构函数、atexit()函数，刷新缓冲区，而_exit()不会执行构造函数、atexit()函数，不刷新缓冲区


2、vfork文件夹是测试vfork的一些实验




