#include "encode.h"
#include "common/func.h"
#include "decode.h"
#include <sys/syscall.h>
#include <stdio.h>

void data_output();
void output_decompressed();

void output_compressed(){

    given_file = fopen(given_file_path, "r");
    output_file = fopen(compressed_file_path, "w");

    /*output compressing library: 
        the sequence of the Huffman tree*/
    fputc(char_count, output_file);
    tree_output(final_root, output_file);
    fputc(TEOF, output_file);
    // preorder_output(final_root, output_file);
    // inorder_output(final_root, output_file);
    data_output();

    fclose(given_file);
    fclose(output_file);
}


void data_output(){
    char output[8]; int i = 0;
    char c = fgetc(given_file);
    while(c != EOF){
        char* code = find_code(c);
        int code_len = strlen(code), j = 0;
        while(code_len > 0){
            output[i++] = code[j++];
            if(i == 8){
                i = 0;
                int value = bin_string2int(output);
                fputc(value, output_file);
            }
            code_len--;
        }
        c = fgetc(given_file);
    }
}

void output_temp_file(){
    FILE* temp_file; const char* temp_file_name = "temp";
    temp_file_path = (char*)malloc((strlen(file_path) + 5) * sizeof(char));
    int i, j = strlen(file_path);
    for(i = 0; i < j; i++) temp_file_path[i] = file_path[i];
    temp_file_path[j] = '/';
    for(i = j + 1; i < j + 5; i++) temp_file_path[i] = temp_file_name[i - j - 1];
    temp_file = fopen(temp_file_path, "w");

    char c;
    while(c != EOF){
        c = fgetc(given_file);
        char* bin = int2bin_string((int)c);
        fputs(bin, temp_file);
    }
    fclose(temp_file);
    fclose(given_file);
}

void output_decompressed(){

    output_temp_file();
    FILE* temp_file = fopen(temp_file_path, "r");
    output_file = fopen(decompressed_file_path, "w");
    char code[0xff], c; int n = 0;
    while(c != EOF){
        c = fgetc(temp_file);
        code[n++] = c;
        char data = find_data(code, n);
        if(data == -1) continue;
        fputc(data, output_file);
        n = 0;
    }
    
    fclose(output_file);
    fclose(temp_file);
    remove("temp");
}