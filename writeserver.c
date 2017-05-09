#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

//TODO select is hooked at initial stream

int main(int argc, char const *argv[]) {

    int fd1, fd2, fd3;
    const char* path1 = "/home/qngapparat/Desktop/fifo1";
    const char* path2 = "/home/qngapparat/Desktop/fifo2";
    const char* path3 = "/home/qngapparat/Desktop/fifo3";


    const char* msg1 = "ping! im the webserver :)\n";
    const char* msg2 = "ping! im the middleware :-))\n";
    const char* msg3 = "ping! im the database :^)\n";

    mkfifo(path1, 0666);
    mkfifo(path2, 0666);
    mkfifo(path3, 0666);

    fd1 = open(path1, O_WRONLY);
    fd2 = open(path2, O_WRONLY);
    fd3 = open(path3, O_WRONLY);

    write(fd1, msg1, strlen(msg1)+1); //to also account for \0 EOF char
    write(fd2, msg2, strlen(msg2)+1); //to also account for \0 EOF char
    write(fd3, msg3, strlen(msg3)+1); //to also account for \0 EOF char

    close(fd1);
    close(fd2);
    close(fd3);

    unlink(path1);
    unlink(path2);
    unlink(path3);

    return EXIT_SUCCESS;

}
