#include <stdio.h>
#include "include/output.h"

void read_data();
int contain(int n);

int main(int argc, char* argv[]){

    if(argc == 2){
        status = DECOMPRESSING;
        extract_fileName_filePath(argv[1]);
        read_data();
        decode();
        output_decompressed();
    }

    return 0;
}

void read_data(){
    given_file = fopen(given_file_path, "r");

    char_count = fgetc(given_file);
    
}

int contain(int n){
    int i;
    for(i = 0; i < code_count && encode_map[i].data != n; i++);
    if(i == code_count) return 0;
    return 1;
}