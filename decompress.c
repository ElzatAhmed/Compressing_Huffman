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

    preorder = (char*)malloc(char_count * sizeof(char));
    inorder = (char*)malloc(char_count * sizeof(char));

    int i;
    for(i = 0; i < char_count; i++) preorder[i] = fgetc(given_file);
    for(i = 0; i < char_count; i++) inorder[i] = fgetc(given_file);
}