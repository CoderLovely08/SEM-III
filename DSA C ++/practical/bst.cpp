#include <iostream>
using namespace std;
struct node
{
	int data;
	node *left;
	node *right;
	node(int val)
	{
		data = val;
		left = NULL;
		right = NULL;
	}
};
node *inserted(node *root, int val)
{
	if (root == NULL)
	{
		return new node(val);
	}
	if (val < root->data)
	{
		root->left = inserted(root->left, val);
	}
	else
	{
		root->right = inserted(root->right, val);
	}
	return root;
}
void show(node *root)
{
	if (root == NULL)
	{
		return;
	}
	cout << root->data << " ";
	show(root->left);
	show(root->right);
}
void show1(node *root)
{
	if (root == NULL)
	{
		return;
	}

	show1(root->left);
	cout << root->data << " ";
	show1(root->right);
}
void show2(node *root)
{
	if (root == NULL)
	{
		return;
	}
	show2(root->left);
	show2(root->right);
	cout << root->data << " ";
}
int main()
{
	node *root = NULL;
	root = inserted(root, 5);
	inserted(root, 1);
	inserted(root, 3);
	inserted(root, 4);
	inserted(root, 2);
	cout << "pre order" << endl;
	show(root);
	cout<<"\n";
	cout << "in order" << endl;
	show1(root);
		cout<<"\n";
	cout << "post order" << endl;
	show2(root);
	cout << endl;

	return 0;
}