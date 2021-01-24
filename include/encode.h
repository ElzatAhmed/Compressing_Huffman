#include "HuffmanTree.h"

struct Map{
    char data;
    char* code;
    int code_len;
}encode_map[256]; int count = 0;

char code[0xff];

void encode(struct tree_node* t , char* code, int i){
    if(t == NULL) return;
    else if(t->type == LEAF){
        struct Map m = {t->data, code, i};
        encode_map[count].data = t->data;
        encode_map[count].code = code;
        encode_map[count++].code_len = i;
    }
    else{    
        code[i] = '0';
        encode(t->left_child, code, i + 1);
        code[i] = '1';   
        encode(t->right_child, code, i + 1);
    }      
}

void display(){
    int i;
    for(i = 0; i < char_count; i++){
        printf("%c   %d   %s\n", encode_map[i].data, encode_map[i].code_len, encode_map[i].code);
    }
}