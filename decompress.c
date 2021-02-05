#include <stdio.h>
#include "include/output.h"

void read_data();

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