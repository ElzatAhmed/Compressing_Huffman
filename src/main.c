#include <stdio.h>
#include <sys/syscall.h>
#include <data/file_data.c>

int main(int argc, char* args[]){
    if(argc != 1) exit(-1);
    file_name = args[0];
}