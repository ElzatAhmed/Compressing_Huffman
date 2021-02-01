#include <string.h>
#include <stdio.h>

#define NULL_CHAR 0

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
void preorder_output(struct tree_node* t, FILE* output_file){
    if(t == NULL) return;
    if(t->type == LEAF) fputc(t->data, output_file);
    else fputc(NULL_CHAR, output_file);
    preorder_output(t->left_child, output_file);
    preorder_output(t->right_child, output_file);
}
void inorder_output(struct tree_node* t, FILE* output_file){
    if(t == NULL) return;
    inorder_output(t->left_child, output_file);
    if(t->type == LEAF) fputc(t->data, output_file);
    else fputc(NULL_CHAR, output_file);
    inorder_output(t->right_child, output_file);
}
char* int2bin_string(int n){
    char* ret = (char*)malloc(8 * sizeof(char));
    int i = 7;
    while(n){
        ret[i--] = (n % 2 == 1 ? '1' : '0');
        n /= 2;
    }
    while(i >= 0) ret[i--] = '0';
}