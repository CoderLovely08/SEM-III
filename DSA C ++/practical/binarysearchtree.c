#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;
int insert_leaf_node(int data, Node **root)
{
    Node *head;

    if ((head = malloc(sizeof *head)) == NULL)
        return -1;

    head->data = data;
    head->left = NULL;
    head->right = NULL;
    *root = head;
    return 0;
}
int insert_node(int data, Node **root)
{
    Node *Node = *root;

    if (Node == NULL)
    {
        return insert_leaf_node(data, root);
    }
    else if (data <= Node->data)
    {
        return insert_node(data, &Node->left);
    }
    else
    {
        return insert_node(data, &Node->right);
    }
}
void pre_order(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    pre_order(root->left);
    pre_order(root->right);
}
void in_order(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    in_order(root->left);
    printf("%d ", root->data);
    in_order(root->right);
}
void post_order(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    post_order(root->left);
    post_order(root->right);
    printf("%d ", root->data);
}
int main()
{
    Node *root = NULL;
    insert_node(5, &root);
    insert_node(1, &root);
    insert_node(3, &root);
    insert_node(4, &root);
    insert_node(2, &root);
     printf("pre order\n");
     pre_order(root);
     printf("\nin order\n");
     in_order(root);
     printf("\npost order\n");
    post_order(root);
    return 0;
}
