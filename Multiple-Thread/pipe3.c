/**
 * 数据进入管道后成为无主数据。也就是通过read函数先读取数据的进程将得到数据
 * 即使该进程将数据传到了管道。因此子进程将直接读回自己向管道发送的数据。
 * 结果父进程调用read函数后将无限期等待数据进入管道
 * 所以进行双向通信的方法: 创建2个管道
 * 
 */

#include <stdio.h>
#include <unistd.h>
#define BUF_SIZE 30

int main(int argc, char *argv[])
{
    int fds1[2], fds2[2];
    char str1[] = "Who are you?";
    char str2[] = "Thank you for your message";
    char buf[BUF_SIZE];
    pid_t pid;

    pipe(fds1), pipe(fds2);
    pid = fork();
    if(pid == 0)
    {
        write(fds1[1], str1, sizeof(str1));
        read(fds2[0], buf, BUF_SIZE);
        printf("Child proc output: %s \n", buf);
    }
    else
    {
        read(fds1[0], buf, BUF_SIZE);
        printf("Parent proc output: %s \n", buf);
        write(fds2[1], str2, sizeof(str2));
        sleep(3);
    }
    return 0;
}

