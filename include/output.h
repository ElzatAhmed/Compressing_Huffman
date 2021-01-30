#include "encode.h"
#include <stdio.h>

#define NULL_CHAR '\0'

FILE* given_file;
FILE* output_file;

void preorder_output(struct tree_node* t);
void inorder_output(struct tree_node* t);
void data_output();
int bin_string2int(char* s);
int power_of_2(int i);

void output_compressed(){

    given_file = fopen(given_file_path, "r");
    output_file = fopen(compressed_file_path, "w");

    /*output compressing library: 
        preorder and inorder sequence of the Huffman tree*/
    preorder_output(final_root);
    inorder_output(final_root);
    data_output();

    fclose(given_file);
    fclose(output_file);
}

void preorder_output(struct tree_node* t){
    if(t == NULL) return;
    if(t->type == LEAF) fputc(t->data, output_file);
    else fputc(NULL_CHAR, output_file);
    preorder_output(t->left_child);
    preorder_output(t->right_child);
}
void inorder_output(struct tree_node* t){
    if(t == NULL) return;
    inorder_output(t->left_child);
    if(t->type == LEAF) fputc(t->data, output_file);
    else fputc(NULL_CHAR, output_file);
    inorder_output(t->right_child);
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
int bin_string2int(char* s){
    if(strlen(s) == 8){
        int i = 0, res = 0;
        for(; i < 8; i++){
            if(s[i] == '1') res += power_of_2(7 - i);
        }
        return res;
    }
    return -1;
}
int power_of_2(int i){
    if(i == 0) return 1;
    else{
        int res = 1;
        int j = 0;
        for(; j < i; j++) res *= 2;
        return res;
    }
    return -1;
}