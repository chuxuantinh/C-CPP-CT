/* Code by KingNNT */
#include <bits/stdc++.h>

#define pathio "/mnt/Learning And Working/Code/C-CPP/GNU-Compiler/In-Out/"
#define lfi pathio "input.txt", "r", stdin
#define lfo pathio "output.txt", "w", stdout

using namespace std;

class book
{
private:
    string id, name;
    int publishingYear, price;

public:
    book()
    {
        this->id = this->name = "";
        this->publishingYear = this->price = 0;
    }
    book(string id, string name, int publishingYear, int price)
    {
        this->id = id;
        this->name = name;
        this->publishingYear = publishingYear;
        this->price = price;
    }

    ~book()
    {
        this->id = this->name = "";
        this->publishingYear = this->price = 0;
    }

    void enter()
    {
        cin.ignore();
        cout << "ID: ";
        getline(cin, this->id);
        cout << "Name: ";
        getline(cin, this->name);
        cout << "Publishing Year: ";
        cin >> this->publishingYear;
        cout << "Price: ";
        cin >> this->price;
    }

    void getInfo()
    {
        cout << "ID = " << this->id << endl;
        cout << "Name = " << this->name << endl;
        cout << "Publishing Year = " << this->publishingYear << endl;
        cout << "Price = " << this->price << endl;
    }

    int getPrice()
    {
        return this->price;
    }
};

typedef struct Node
{
    book data;
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

bool LeftOf(book value, node_t *root)
{
    if (value.getPrice() < root->data.getPrice())
    {
        return true;
    }
    else {
        return false;
    }
}

bool RightOf(book value, node_t *root)
{
    if (value.getPrice() > root->data.getPrice())
    {
        return true;
    }
    else
    {
        return false;
    }
}

node_t *Insert(node_t *root, const book value)
{
    if (root == NULL)
    {
        node_t *node = (node_t *)malloc(sizeof(node_t));
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

bool Search(node_t *root, book value)
{
    if (root == NULL)
        return false;
    if (root->data.getPrice() == value.getPrice())
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

book LeftMostValue(const node_t *root)
{
    while (root->left != NULL)
        root = root->left;
    return root->data;
}

node_t *Delete(node_t *root, book value)
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
        root->data.getInfo();
        cout << endl;
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void InOrder(node_t *root)
{
    if (root != NULL)
    {
        InOrder(root->left);
        root->data.getInfo();
        cout << endl;
        InOrder(root->right);
    }
}

void PostOrder(node_t *root)
{
    if (root != NULL)
    {
        PostOrder(root->left);
        PostOrder(root->right);
        root->data.getInfo();
        cout << endl;
    }
}

void print(node_t *root)
{
    cout << endl << "PreOrder: " << endl; PreOrder(root);
    cout << endl << "InOrder: " << endl; InOrder(root);
    cout << endl << "PostOrder: " << endl; PostOrder(root);
}

int main()
{
    freopen(lfi);
    freopen(lfo);
    // ios_base ::sync_with_stdio(0);
    cin.tie(0);

    node_t *root = NULL;

    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        book temp;
        temp.enter();
        root = Insert(root,temp);
    }

    print(root);

    cout << "Add a book: " << endl;
    book adaptableBook("ID005","Sach 5", 2016, 40000); Insert(root, adaptableBook); print(root);
    cout << "Delete a book: " << endl;

    book deleteBook("ID002","Sach 2", 2003, 50000);
    Delete(root, deleteBook); print(root);

    Free(root);
    root = NULL;

    fclose(stdin);
    fclose(stdout);
    return 0;
}