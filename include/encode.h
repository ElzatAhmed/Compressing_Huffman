/*
*   encoding functions (using Huffman optimized binary tree)
**/

#include "common/HuffmanTree.h"
#include <stdlib.h>

char code[0xff];

void code_assign(char* c, int n);
char* find_code(char data);
int isEqual(char* s1, char* s2, int n);

void encode(struct tree_node* t , char* code, int i){
    if(t == NULL) return;
    else if(t->type == LEAF){
        encode_map[code_count].data = t->data;
        code_assign(encode_map[code_count].code, i);
        encode_map[code_count++].code_len = i;
    }
    else if(t->type == ROOT){    
        code[i] = '0';
        encode(t->left_child, code, i + 1);
        code[i] = '1';   
        encode(t->right_child, code, i + 1);
    }      
}
void code_assign(char* c, int n){
    int i;
    for(i = 0; i < n; i++) c[i] = code[i];
}
int isEqual(char* s1, char* s2, int n){
    int i;
    for(i = 0; i < n; i++) 
        if(s1[i] != s2[i]) return 0;
    return 1; 
}
char* find_code(char data){
    int i;
    for(i = 0; i < code_count && encode_map[i].data != data; i++);
    if(i == code_count) return NULL;
    return encode_map[i].code; 
}
char find_data(char* code, int n){
    int i, j;
    for(i = 0; i < code_count; i++){
        if(n == encode_map[i].code_len){
            if(isEqual(code, encode_map[i].code, n)) return encode_map[i].data;
        }
    }
    return -1;
}