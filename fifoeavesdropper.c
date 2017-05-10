#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char const *argv[]) {

    int fd;
    const int MAX_BUF = 1024;
    char buf[MAX_BUF];
    const char path[] = "/home/qngapparat/Desktop/fifo2";


    fd = open(path, O_RDONLY);

    read(fd, buf, MAX_BUF);
    printf("received: %s", buf);
    memset(buf, 0, MAX_BUF);

    close(fd);
    return EXIT_SUCCESS;
}
