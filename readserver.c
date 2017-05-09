#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 1024

int main(int argc, char const *argv[]) {

    int fd1, fd2, fd3; //TODO set those
    int ndfs;
    fd_set readfds;
    char buf1[BUF_SIZE], buf2[BUF_SIZE], buf3[BUF_SIZE];
    int selectStatus = 0;

    const char path1[] = "/home/qngapparat/Desktop/fifo1";
    const char path2[] = "/home/qngapparat/Desktop/fifo2";
    const char path3[] = "/home/qngapparat/Desktop/fifo3";

    fd1 = open(path1, O_RDONLY);
    fd2 = open(path2, O_RDONLY);
    fd3 = open(path3, O_RDONLY);

    //clear our set
    FD_ZERO(&readfds);

    FD_SET(fd1, &readfds);
    FD_SET(fd2, &readfds);
    FD_SET(fd3, &readfds);

    //ndfs is "greatest" fd plus 1
    ndfs = fd3 + 1;
    int loop = 0;

    while(1){

        selectStatus = select(ndfs, &readfds, NULL, NULL, NULL);
        if(selectStatus == -1){
            perror("select");
            exit(EXIT_FAILURE);
        }

        else{ //if there is data

            printf("loop: %d   ", loop);
            if(FD_ISSET(fd1, &readfds)){
                read(fd1, buf1, BUF_SIZE);
                printf("buf1: %s\n", buf1);
                //memset(buf1, 0, BUF_SIZE);
            }
            if(FD_ISSET(fd2, &readfds)){
                read(fd2, buf2, BUF_SIZE);
                printf("buf2: %s\n", buf2);
                //memset(buf2, 0, BUF_SIZE);
            }
            if(FD_ISSET(fd3, &readfds)){
                read(fd3, buf3, BUF_SIZE);
                printf("buf3: %s\n", buf3);
                //memset(buf3, 0, BUF_SIZE);
            }
        }

        sleep(1);
        loop++;

    }

    close(fd1);
    close(fd2);
    close(fd3);
    return EXIT_SUCCESS;
}
