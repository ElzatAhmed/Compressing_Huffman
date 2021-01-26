/**
 * Functions for building Huffman tree :
 *      1) init_forest: define a tree node for each different character 
 *                   in the file,and record its frequency.
 *      2) build_HuffmanTree: the function for building Huffman optimized
 *                   binary tree.
 */

#include "tree.h"
#include "file_data.h"
#include <stdlib.h>

struct tree_node* final_root;


int isLeaf(struct tree_node* t);
void init_forest();

void build_HuffmanTree(){
    init_forest();
    while(1){
        if(Forest.tree_count <= 1) break;
        struct tree_node* t1 = pop();
        struct tree_node* t2 = pop();
        struct tree_node* t = (struct tree_node*)malloc(sizeof(struct tree_node));
        t->frequency = t1->frequency + t2->frequency;
        t->left_child = t1;
        t->right_child = t2;
        t->type = ROOT;
        if(isLeaf(t1)) t1->type = LEAF;
        if(isLeaf(t2)) t2->type = LEAF;
        Insert2Forest(t);
    }
    final_root = Forest.trees[0];
}


void init_forest(){
    int i; Forest.tree_count = 0;
    for(i = 0; i < char_count; i++){
        struct tree_node* t = (struct tree_node*)malloc(sizeof(struct tree_node));
        t->data = frequency_map[i].data;
        t->frequency = frequency_map[i].frequency;
        t->left_child = NULL;
        t->right_child = NULL;
        t->type = NORMAL;
        Insert2Forest(t);
    }
}
int isLeaf(struct tree_node* t){
    if(t->left_child == NULL && t->right_child == NULL) return 1;
    return 0;
}