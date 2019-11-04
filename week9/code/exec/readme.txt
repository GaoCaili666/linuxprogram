execl,execle,execv,execve函数
可执行文件必须给出绝对路径，比如：/root/Desktop/linux/第9周/exec/test

execlp,execvp函数
直接给出文件名，可执行文件到PATH中去查询，直接传入test就好了

l:运行参数直接写在函数当中，最后一个参数为NULL
v:运行参数写在数组当中，数组最后一个参数为NULL
e:可修改环境变量


call可执行文件运行结果：
call:pid=10585,ppid=7096
test:pid=10585,ppid=7096
test
hello
world

说明exec是用被调用者的代码替代调用者，没有派生新进程，因为是将被调用者的代码替代调用者，所以after calling也没有输出
