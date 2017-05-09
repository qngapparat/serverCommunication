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
    const char* path = "/home/qngapparat/Desktop/fifo";
    const char* msg = "daaank memes lol aber auch\n";

    mkfifo(path, 0666);

    fd = open(path, O_WRONLY);

    write(fd, msg, strlen(msg)+1); //to also account for \0 EOF char

    close(fd);
    unlink(path);

    return EXIT_SUCCESS;

}
