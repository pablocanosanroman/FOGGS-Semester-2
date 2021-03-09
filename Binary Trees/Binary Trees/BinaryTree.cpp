#include "structures.h"

treenode* makeNode(char data);
treenode* makeTree();
treenode* depthFirstSearch(treenode* tree, char nodeToSearch);
void preOrderTraverse(treenode* tree);
void inOrderTraverse(treenode* tree);
void postOrderTraverse(treenode* tree);
void deleteTree(treenode* tree);

int main()
{
    treenode* tree = makeTree();

    preOrderTraverse(tree);
    std::cout << std::endl;

    inOrderTraverse(tree);
    std::cout << std::endl;

    postOrderTraverse(tree);
    std::cout << std::endl;

    depthFirstSearch(tree, 'R');

    deleteTree(tree);
}

treenode* makeNode(char data)
{
    treenode* newNode;
    newNode = new treenode();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;

    return newNode;
}

treenode* makeTree()
{
    treenode* head = makeNode('P');
    head->left = makeNode('J');
    head->right = makeNode('X');
    head->left->left = makeNode('D');
    head->left->left->right = makeNode('F');
    head->left->right = makeNode('L');
    head->right->left = makeNode('S');
    head->right->left->left = makeNode('R');
    head->right->right = makeNode('C');
    head->left->left->left = makeNode('T');
    return head;

}

void preOrderTraverse(treenode* tree)
{
    std::cout << tree->data;

    if (tree->left != nullptr)
    {
        preOrderTraverse(tree->left);
    }

    if (tree->right != nullptr)
    {
        preOrderTraverse(tree->right);
    }


}

void inOrderTraverse(treenode* tree)
{
    if (tree->left != nullptr)
    {
        inOrderTraverse(tree->left);
    }

    std::cout << tree->data ;

    if (tree->right != nullptr)
    {
        inOrderTraverse(tree->right);
    }
}

void postOrderTraverse(treenode* tree)
{
    if (tree->left != nullptr)
    {
        inOrderTraverse(tree->left);
    }

    if (tree->right != nullptr)
    {
        inOrderTraverse(tree->right);
    }

    std::cout << tree->data;
}

treenode* depthFirstSearch(treenode* tree, char nodeToSearch)
{
    treenode* answer = nullptr;

    std::cout << tree->data;

    if (tree->data == nodeToSearch)
    {
        return tree;
    }

    if (tree->left != nullptr)
    {
        answer = depthFirstSearch(tree->left, nodeToSearch);

    }
    
    if (answer == nullptr && tree->right != nullptr)
    {
        answer = depthFirstSearch(tree->right, nodeToSearch);
    }

    return answer;
}

void deleteTree(treenode* tree)
{
    delete tree;
}
