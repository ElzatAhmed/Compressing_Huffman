#include "encode.h"
#include "common/func.h"
#include "decode.h"
#include <sys/syscall.h>
#include <stdio.h>

void data_output();
void output_decompressed();
void count_bit();

void output_compressed(){

    given_file = fopen(given_file_path, "r");
    output_file = fopen(compressed_file_path, "w");

    /*output compressing library: 
        the sequence of the Huffman tree*/
    fputc(char_count, output_file);
    tree_output(final_root, output_file);
    // display_tree(final_root); printf("\n");
    //fputc(TEOF, output_file);
    // preorder_output(final_root, output_file);
    // inorder_output(final_root, output_file);
    count_bit();
    data_output();

    fclose(given_file);
    fclose(output_file);
}

void count_bit(){
    char c = fgetc(given_file);
    while(c != EOF){
        char* code = find_code(c);
        bit_count += strlen(code);
        c = fgetc(given_file);
    }
    int i;
    for(i = 0; i < 4; i++){
        int v = bit_count >> (8 * (3 - i));
        fputc(v, output_file);
    }
    fclose(given_file);
    given_file = fopen(given_file_path, "r");
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
                int value = bin_string2int(output, 8);
                fputc(value, output_file);
            }
            code_len--;
        }
        c = fgetc(given_file);
    }
    if(i > 0){
        int n;
        for(n = i; n < 8; n++) output[n] = '1';
        int value = bin_string2int(output, 8);
        fputc(value, output_file);
    }
}

void read_bit_count(){
    int tmp = 0, i;
    for(i = 0; i < 4; i++){
        int v = fgetc(given_file);
        tmp <<= 8; tmp += v;
    }
    bit_count = tmp;
}

void output_temp_file(){

    read_bit_count();

    FILE* temp_file; const char* temp_file_name = "temp";
    temp_file_path = (char*)malloc((strlen(file_path) + 5) * sizeof(char));
    int i, j = strlen(file_path);
    for(i = 0; i < j; i++) temp_file_path[i] = file_path[i];
    temp_file_path[j] = '/';
    for(i = j + 1; i < j + 5; i++) temp_file_path[i] = temp_file_name[i - j - 1];
    temp_file = fopen(temp_file_path, "w");

    char c = fgetc(given_file); int bit = 0; char *bin;
    while(1){
        bin = int2bin_string((int)c);
        if(bit + strlen(bin) > bit_count) break;
        bit += strlen(bin);
        fputs(bin, temp_file);
        c = fgetc(given_file);
    }
    if(bit + strlen(bin) > bit_count && bit < bit_count){
        int rest = bit_count - bit;
        for(i = 0; i < rest; i++) fputc(bin[i], temp_file);
    }
    fclose(temp_file);
    fclose(given_file);
}

void output_decompressed(){

    // display_tree(final_root); printf("\n");
    output_temp_file();
    FILE* temp_file = fopen(temp_file_path, "r");
    // FILE* origin_file = fopen("testcases/hello", "r");
    output_file = fopen(decompressed_file_path, "w");
    char code[0xff], c = fgetc(temp_file); int n = 0;
    while(c != EOF){
        code[n++] = c;
        c = fgetc(temp_file);
        char data = find_data(code, n);
        if(data == -1) continue;
        /*char judge =  fgetc(origin_file);
        if(judge != data){
            printf("%c %c ERROR\n", judge, data);
            exit(-1);
        }*/
        fputc(data, output_file);
        n = 0;
    }
    
    fclose(output_file);
    fclose(temp_file);
    remove("temp");
}