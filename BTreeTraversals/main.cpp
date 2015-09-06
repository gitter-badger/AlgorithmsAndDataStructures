#include <iostream>
#include <stack>
#include <queue>


//----------------------------------------------------------------------------------------------------------------------------------------------
struct Node
{
    char  data;
    Node* left;
    Node* right;

    Node(int data) : data(data)
    {
        left = right = nullptr;
    }
};

//----------------------------------------------------------------------------------------------------------------------------------------------
Node* createBinaryTree()
{
    Node* a = new Node('A');
    Node* b = new Node('B');
    Node* c = new Node('C');
    Node* d = new Node('D');
    Node* e = new Node('E');
    Node* f = new Node('F');
    Node* g = new Node('G');
    Node* h = new Node('H');

    e->left  = d;
    e->right = h;
    d->left  = b;
    b->left  = a;
    b->right = c;
    h->right = f;
    f->right = g;

    return e;
}

//----------------------------------------------------------------------------------------------------------------------------------------------
void view_preorder(Node* n)
{
    if (!n) return;

    std::cout << " " << n->data;
    view_preorder(n->left);
    view_preorder(n->right);
}

//----------------------------------------------------------------------------------------------------------------------------------------------
void view_inorder(Node* n)
{
    if(!n) return;

    view_inorder(n->left);
    std::cout << " " << n->data;
    view_inorder(n->right);
}

//----------------------------------------------------------------------------------------------------------------------------------------------
void view_postorder(Node* n)
{
    if(!n) return;

    view_postorder(n->left);
    view_postorder(n->right);
    std::cout << " " << n->data;
}

//----------------------------------------------------------------------------------------------------------------------------------------------
void view_preorder_stack(Node* n)
{
    std::stack<Node*> stack;

    stack.push(n);

    while (!stack.empty())
    {
        Node* n = stack.top();
        stack.pop();
        std::cout << " " << n->data;

        if (n->right) stack.push(n->right);
        if (n->left)  stack.push(n->left);
    }
}

//----------------------------------------------------------------------------------------------------------------------------------------------
void view_level(Node* n)
{
    std::queue<Node*> stack;

    stack.push(n);

    while(!stack.empty())
    {
        Node* n = stack.front();
        stack.pop();
        std::cout << " " << n->data;

        if(n->left)  stack.push(n->left);
        if(n->right) stack.push(n->right);
    }
}

//----------------------------------------------------------------------------------------------------------------------------------------------
void print_node(char x, int h)
{
    for (int i = 0; i < h; i++)
    {
        std::cout << "   ";
    }

    std::cout << x << std::endl;
}


/*

/home/test/bin/x64/debug/win32/../../release/./././test//doc//sample//../../../../

*/


//----------------------------------------------------------------------------------------------------------------------------------------------
void show(Node *n, int h)
{
    if (!n)
    {
        print_node('*', h);
        return;
    }

    show(n->right, h+1);
    print_node(n->data, h);
    show(n->left, h+1);
}


//----------------------------------------------------------------------------------------------------------------------------------------------
int main()
{
    auto tree = createBinaryTree();

    std::cout << std::endl << "Preorder: ";
    view_preorder(tree);
    std::cout << std::endl << "Preorder: ";
    view_preorder_stack(tree);

    std::cout << std::endl << "Inorder: ";
    view_inorder(tree);

    std::cout << std::endl << "Postorder: ";
    view_postorder(tree);

    std::cout << std::endl << "Level: ";
    view_level(tree);

    std::cout << std::endl;
    show(tree, 3);

    std::cout << std::endl << "\n\n";
    return 0;
}