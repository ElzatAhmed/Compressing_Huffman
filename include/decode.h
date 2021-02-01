#include <stdio.h>
#include <stdlib.h>

struct tree_node* final_root;

/*rebuilding Huffman optimized binary tree 
        using the preorder and inorder sequence of the tree*/
int find(char* a, int size, int value);
struct tree_node* build_tree(char* preorder, char* inorder, int size);
void decode();

struct tree_node* build_tree(char* preorder, char* inorder, int size){
    if(size < 0) return NULL;
    struct tree_node* root = (struct tree_node*)malloc(sizeof(struct tree_node));
    root->data = preorder[0];
    if(size == 0) return root;
    int left_size = find(inorder, size, root->data);
    /*incomplete*/
}
int find(char* a, int size, int value){
    int i;
    for(i = 0; i < size; i++){
        if(a[i] == value) return i;
    }
    return -1;
}

void decode(){
    final_root = build_tree(preorder, inorder, char_count);
    int i = 0;
    encode(final_root, code, i);
}