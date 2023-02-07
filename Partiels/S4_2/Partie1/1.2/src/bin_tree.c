#include "../inc/bin_tree.h"

bin_tree empty_tree(void)
{
    return NULL;
}

int is_empty(bin_tree t)
{
    return (t == empty_tree());
}

bin_tree build_tree(int n, bin_tree left_son, bin_tree right_son)
{
    bin_tree t = (bin_tree)malloc(1 * sizeof(bin_node_struct));
    assert(t != NULL);
    t->value = n;
    t->left = left_son;
    t->right = right_son;
    return t;
}

void infix_print(bin_tree t)
{
    if (!is_empty(t))
    {
        infix_print(t->left);
        printf("%d", t->value);
        infix_print(t->right);
    }
}

bin_tree insert(int n, bin_tree t)
{
    if (is_empty(t))
        t->value = n;
    else if (n <= t->value)
        insert(n, t->left);
    else
        insert(n, t->right);
    return t;
}

bin_tree rm_integer(int n, bin_tree t)
{
    if (is_empty(t))
    {
        fprintf(stderr, "This tree is empty !\n");
        exit(EXIT_FAILURE);
    }
    if (t->value == n)
    {
        t = empty_tree();
    }
    else if (n <= t->value)
        rm_integer(n, t->left);
    else
        rm_integer(n, t->right);
    return t;
}

int main(void)
{
    printf("Hello World\n");
    return 0;
}