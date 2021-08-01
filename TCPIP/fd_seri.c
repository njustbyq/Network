#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>

int main(){
    int fd1, fd2, fd3;
    fd1 = socket(PF_INET, SOCK_STREAM, 0);
    fd2 = open("test.dat", O_CREAT | O_WRONLY | O_TRUNC);
    fd3 = socket(PF_INET, SOCK_STREAM, 0);

    printf("file descriptor 1: %d\n", fd1);
    printf("file descriptor 2: %d\n", fd2);
    printf("file descriptor 3: %d\n", fd3); 

    //描述符从3开始由小到大进行顺序编号，因为0，1，2是分配给I/O的描述符

    close(fd1);
    close(fd2);
    close(fd3);
}