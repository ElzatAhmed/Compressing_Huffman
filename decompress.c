#include <stdio.h>
#include "include/file_data.h"
#include "include/decode.h"

void read_data();

int main(int argc, char* argv[]){

    if(argc == 2){
        file_path = argv[1];
        read_data();
    }

    return 0;
}

void read_data(){
    given_file = fopen(file_path, "r");

    char_count = fgetc(given_file);

    preorder = (char*)malloc(char_count * sizeof(char));
    inorder = (char*)malloc(char_count * sizeof(char));

    int i;
    for(i = 0; i < char_count; i++) preorder[i] = fgetc(given_file);
    for(i = 0; i < char_count; i++) inorder[i] = fgetc(given_file);
}