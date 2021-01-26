#include "encode.h"
#include <stdio.h>



void output_compressed(){

    FILE* given_file;
    FILE* output_file;

    given_file = fopen(given_file_path, "r");
    output_file = fopen(compressed_file_path, "w");

    char c;
    while(c != EOF){
        c = fgetc(given_file);
        char* code = find_code(c);
    }

    fclose(given_file);
    fclose(output_file);
}