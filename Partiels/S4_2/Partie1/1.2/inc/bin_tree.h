#ifndef C_BIN_TREE
#define C_BIN_TREE

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct bin_node
{
    int value;
    struct bin_node *left;
    struct bin_node *right;
} bin_node_struct;

typedef bin_node_struct *bin_tree;


bin_tree empty_tree(void);

int is_empty(bin_tree t);

bin_tree build_tree(int n, bin_tree left_son, bin_tree right_son);

void infix_print(bin_tree t);

bin_tree insert(int n, bin_tree t);

bin_tree rm_integer(int n, bin_tree t);


#endif