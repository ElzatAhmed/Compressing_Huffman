/**
 * tree node for building huffman tree:
 *      1.each tree node has a character type data;
 *      2.each tree node has an integer type value stands for the frequency of data;
 *      3.each tree node has a left and a right child node;
*/

#define ROOT 0x33
#define LEAF 0x66
#define NORMAL 0x99

typedef int node_type;

struct tree_node{
    char data;
    int frequency;
    node_type type;
    tree_node* left_child;
    tree_node* right_child;
};

tree_node* forest[];
tree_node* RootOfHuffmanTree;