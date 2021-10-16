/**
 * 调用pipe函数创建管道，fds数组中保存用于I/O的文件描述符
 * 调用fork函数。子进程将同时拥有通过调用pipe函数获取的2个文件描述符
 * 子进程通过write函数向管道传递字符串。父进程通过read函数从管道接受字符串
 * 
 */
#include <stdio.h>
#include <unistd.h>
#define BUF_SIZE 30

int main(int argc, char *argv[])
{
    int fds[2];
    char str[] = "Who are you?";
    char buf[BUF_SIZE];
    pid_t pid;

    pipe(fds);
    pid = fork();
    if(pid == 0)
    {
        write(fds[1], str, sizeof(str));
    }
    else
    {
        read(fds[0], buf, BUF_SIZE);
        puts(buf);
    }
    return 0;
}