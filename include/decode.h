#include <stdio.h>
#include <stdlib.h>

struct tree_node* final_root;

/*rebuilding Huffman optimized binary tree 
        using the sequence of the tree*/
struct tree_node* build_tree(char c);
void decode();

struct tree_node* build_tree(char c){
    if(/*c == TEOF ||*/c == NULL_CHAR) return NULL;
    struct tree_node* t = (struct tree_node*)malloc(sizeof(struct tree_node));
    t->data = c;
    if(c == ROOT_CHAR) t->type = ROOT;
    else t->type = LEAF;
    char l = fgetc(given_file);
    t->left_child = build_tree(l);
    char r = fgetc(given_file);
    t->right_child = build_tree(r);
    return t;
}

void decode(){
    char c = fgetc(given_file);
    final_root = build_tree(c);
    //c = fgetc(given_file);      // get TEOF
    int i = 0;
    encode(final_root, code, i);
}