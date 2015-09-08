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
void inverTree(Node* root)
{
    if (!root) return;

    std::swap(root->left, root->right);

    inverTree(root->left);
    inverTree(root->right);
}

//----------------------------------------------------------------------------------------------------------------------------------------------
Node* createBinaryTree()
{
    Node* n4 = new Node('4');
    Node* n2 = new Node('2');
    Node* n7 = new Node('7');
    Node* n1 = new Node('1');
    Node* n3 = new Node('3');
    Node* n6 = new Node('6');
    Node* n9 = new Node('9');

    n4->left = n2;
    n4->right = n7;
    n2->left = n1;
    n2->right = n3;
    n7->left = n6;
    n7->right = n9;

    return n4;
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
    auto tree  = createBinaryTree();
    std::cout << std::endl << "Level: ";
    view_inorder(tree);

    inverTree(tree);
    std::cout << std::endl << "Level: ";
    view_inorder(tree);

    std::cout << std::endl;
    show(tree, 3);

    std::cout << std::endl << "\n\n";
    return 0;
}