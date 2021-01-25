/*
*   encoding functions (using Huffman optimized binary tree)
**/

#include "HuffmanTree.h"
#include <stdlib.h>

struct{
    char data;
    char code[0xff];
    int code_len;
}encode_map[256]; int count = 0;

char code[0xff];

void code_assign(char* c, int n){
    int i;
    for(i = 0; i < n; i++) c[i] = code[i];
}

void encode(struct tree_node* t , char* code, int i){
    if(t == NULL) return;
    else if(t->type == LEAF){
        encode_map[count].data = t->data;
        code_assign(encode_map[count].code, i);
        encode_map[count++].code_len = i;
    }
    else if(t->type == ROOT){    
        code[i] = '0';
        encode(t->left_child, code, i + 1);
        code[i] = '1';   
        encode(t->right_child, code, i + 1);
    }      
}