#include <string.h>
#include <stdio.h>

#define NULL_CHAR -1
#define ROOT_CHAR -2
#define TEOF 3

int bin_string2int(char* s, int n){
    int i = 0, res = 0;
    for(; i < n; i++){
        if(s[i] == '1') res += power_of_2(n - 1 - i);
    }
    return res;
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
// void preorder_output(struct tree_node* t, FILE* output_file){
//     if(t == NULL) return;
//     if(t->type == LEAF) fputc(t->data, output_file);
//     else fputc(t->frequency, output_file);
//     preorder_output(t->left_child, output_file);
//     preorder_output(t->right_child, output_file);
// }
// void inorder_output(struct tree_node* t, FILE* output_file){
//     if(t == NULL) return;
//     inorder_output(t->left_child, output_file);
//     if(t->type == LEAF) fputc(t->data, output_file);
//     else fputc(NULL_CHAR, output_file);
//     inorder_output(t->right_child, output_file);
// }
char* int2bin_string(int n){
    int isNegative = 0;
    if(n < 0) {
        isNegative = 1; n = -n;
    }
    char* ret = (char*)malloc(8 * sizeof(char));
    int i = 7;
    while(n){
        ret[i--] = (n % 2 == 1 ? '1' : '0');
        n /= 2;
    }
    while(i >= 0) ret[i--] = '0';
    if(isNegative){
        for(i = 0; i < 8; i++) ret[i] = (ret[i] == '1' ? '0' : '1');
        for(i = 7; i >= 0; i--){
            if(ret[i] == '0'){
                ret[i] = '1'; break;
            }
            ret[i] = '0';
        }
    }
    if(i == -1 && isNegative) return NULL;
    return ret;
}
void tree_output(struct tree_node* t, FILE* output_file){
    if(t == NULL){
        fputc(NULL_CHAR, output_file);
        return;
    }
    else{
        if(t->type == ROOT) fputc(ROOT_CHAR, output_file);
        else fputc(t->data, output_file);
        tree_output(t->left_child, output_file);
        tree_output(t->right_child, output_file);
    }
}