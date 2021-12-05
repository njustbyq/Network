/* readv & writev函数的功能可概括如下:
 * 对数据进行整合传输及发送的函数
 * 通过writev函数可以将分散保存在多个缓冲中的数据
 * 一并发送,通过readv函数可以由多个缓冲分别接受
 * 因此适当使用这两个函数可以减少IO函数的调用次数。
*/
#include <stdio.h>
#include <sys/uio.h>

int main(int argc, char *argv[])
{
    struct iovec vec[2];
    char buf1[] = "ABCDEFG";
    char buf2[] = "1234567";
    int str_len;

    vec[0].iov_base = buf1;
    vec[0].iov_len  = 3;
    vec[1].iov_base = buf2;
    vec[1].iov_len  = 4;

    str_len = writev(1, vec, 2);
    puts(" ");
    printf("Write bytes : %d \n", str_len);
    return 0;
}