forktest1.c：printf函数中有换行符，printf输出到终端时是以行缓存的方式进行的，在遇到换行符后就会清空缓冲区，只会输出一次“printf”
forktest2.c：printf函数中没有换行符，不会清空缓冲区，所以会输出两次“printf”
simplefork.c：跟forktest1.c、forktest2.c测试的目的一样
setvbufTest.c：设置了一下标准stdin的缓冲方式
