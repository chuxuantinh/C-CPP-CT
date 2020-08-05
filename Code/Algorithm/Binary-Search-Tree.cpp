/* Code by KingNNT */
#include <bits/stdc++.h>

#define pathio "/mnt/Learning And Working/Code/C-CPP/GNU-Compiler/In-Out/"
// #define pathio "E:/Code/C-CPP/GNU-Compiler/In-Out/"
#define lfi pathio"input.txt","r",stdin
#define lfo pathio"output.txt","w",stdout

using namespace std;

typedef struct Node
{
	int data;
	Node *left;
	Node *right;
} node_t;

void Free(node_t *root)
{
	if (root == NULL)
		return;

	Free(root->left);
	Free(root->right);
	free(root);
}

int LeftOf(const int value, const node_t *root)
{
	return value < root->data;
	//    return value <= root->data;
}

int RightOf(const int value, const node_t *root)
{
	return value > root->data;
}

node_t *Insert(node_t *root, const int value)
{
	if (root == NULL)
	{
		node_t *node = new node_t;
		node->left = NULL;
		node->right = NULL;
		node->data = value;
		return node;
	}
	if (LeftOf(value, root))
		root->left = Insert(root->left, value);
	else if (RightOf(value, root))
		root->right = Insert(root->right, value);
	return root;
}

bool Search(const node_t *root, int value)
{
	if (root == NULL)
		return false;
	if (root->data == value)
	{
		return true;
	}
	else if (LeftOf(value, root))
	{
		return Search(root->left, value);
	}
	else if (RightOf(value, root))
	{
		return Search(root->right, value);
	}
}

int LeftMostValue(const node_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return root->data;
}

node_t *Delete(node_t *root, int value)
{
	if (root == NULL)
		return root;
	if (LeftOf(value, root))
		root->left = Delete(root->left, value);
	else if (RightOf(value, root))
		root->right = Delete(root->right, value);
	else
	{
		// root->data == value, delete this node
		if (root->left == NULL)
		{
			node_t *newRoot = root->right;
			free(root);
			return newRoot;
		}
		if (root->right == NULL)
		{
			node_t *newRoot = root->left;
			free(root);
			return newRoot;
		}
		root->data = LeftMostValue(root->right);
		root->right = Delete(root->right, root->data);
	}
	return root;
}

void PreOrder(node_t *root)
{
	if (root != NULL)
	{
		cout << root->data << " ";
		PreOrder(root->left);
		PreOrder(root->right);
	}
}

void InOrder(node_t *root)
{
	if (root != NULL)
	{
		InOrder(root->left);
		cout << root->data << " ";
		InOrder(root->right);
	}
}

void PostOrder(node_t *root)
{
	if (root != NULL)
	{
		PostOrder(root->left);
		PostOrder(root->right);
		cout << root->data << " ";
	}
}

void print(node_t *root)
{
	cout << endl
		 << "PreOrder: ";
	PreOrder(root);
	cout << endl
		 << "InOrder: ";
	InOrder(root);
	cout << endl
		 << "PostOrder: ";
	PostOrder(root);
}

int main()
{
	freopen(lfi);
	freopen(lfo);
	// ios_base :: sync_with_stdio (0);
	cin.tie(0);

	node_t *root = NULL;

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;
		root = Insert(root, temp);
	}

	print(root);

	cout << endl
		 << endl
		 << "--> Add 15 to Tree" << endl;
	Insert(root, 15);
	print(root);
	cout << endl
		 << endl
		 << "--> Delete 50 from Tree" << endl;
	Delete(root, 50);
	print(root);

	Free(root);
	root = NULL;

	fclose(stdin);
	fclose(stdout);
	return 0;
}