
/**
 * tree node for building huffman tree:
 *      1.each tree node has a character type data;
 *      2.each tree node has an integer type value stands for the frequency of data;
 *      3.each tree node has a left and a right child node;
*/

typedef int node_type;

#define NORMAL 0x33
#define ROOT 0x66
#define LEAF 0x99

struct tree_node{
    char data;
    int frequency;
    node_type type;
    struct tree_node* left_child;
    struct tree_node* right_child;
};

struct{
    struct tree_node* trees[256];      // Max value of a byte is 256
    int tree_count;
}Forest;        // queue structure

void Insert2Forest(struct tree_node* t){
    int i;
    for(i = Forest.tree_count - 1; i >= 0 && t->frequency > Forest.trees[i]->frequency; i--) 
        Forest.trees[i + 1] = Forest.trees[i];
    Forest.trees[i + 1] = t;
    Forest.tree_count++;
}
struct tree_node* pop(){
    struct tree_node* t =  Forest.trees[Forest.tree_count - 1];
    int i;
    for(i = Forest.tree_count; i >= 0; i--) Forest.trees[i + 1] = Forest.trees[i];
    Forest.tree_count--;
    return t;
}