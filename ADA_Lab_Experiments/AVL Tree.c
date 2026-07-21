#include <stdio.h>
#include <stdlib.h>

// Structure for an AVL Tree Node
typedef struct Node {
    int data;
    struct Node* leftChild;
    struct Node* rightChild;
    int height;
} Node;

// Helper function to get the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Helper function to safely get the height of a node (handles NULL pointers)
int Height(Node* n) {
    if (n == NULL) return -1; // -1 for edge-count height definition
    return n->height;
}

// Creates a new node with given data
Node* createNode(int x) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = x;
    node->leftChild = NULL;
    node->rightChild = NULL;
    node->height = 0; // Single node has a height of 0
    return node;
}

// Left-Left (LL) Rotation: Right rotation around parent
Node* LL_Rotate(Node* parent) {
    Node* child = parent->leftChild;
    parent->leftChild = child->rightChild;
    child->rightChild = parent;

    // Update heights
    parent->height = max(Height(parent->leftChild), Height(parent->rightChild)) + 1;
    child->height = max(Height(child->leftChild), Height(child->rightChild)) + 1;

    return child;
}

// Right-Right (RR) Rotation: Left rotation around parent
Node* RR_Rotate(Node* parent) {
    Node* child = parent->rightChild;
    parent->rightChild = child->leftChild;
    child->leftChild = parent;

    // Update heights
    parent->height = max(Height(parent->leftChild), Height(parent->rightChild)) + 1;
    child->height = max(Height(child->leftChild), Height(child->rightChild)) + 1;

    return child;
}

// Left-Right (LR) Rotation: Double rotation (Left then Right)
Node* LR_Rotate(Node* parent) {
    parent->leftChild = RR_Rotate(parent->leftChild);
    return LL_Rotate(parent);
}

// Right-Left (RL) Rotation: Double rotation (Right then Left)
Node* RL_Rotate(Node* parent) {
    parent->rightChild = LL_Rotate(parent->rightChild);
    return RR_Rotate(parent);
}

// Recursive AVL Tree Insertion
Node* Insert(Node* Tree, int x) {
    // Base Case
    if (Tree == NULL) {
        return createNode(x);
    }

    // Standard BST Insertion
    if (x < Tree->data) {
        Tree->leftChild = Insert(Tree->leftChild, x);
        
        // Rebalance Check
        if (Height(Tree->leftChild) - Height(Tree->rightChild) == 2) {
            if (x < Tree->leftChild->data)
                Tree = LL_Rotate(Tree);
            else
                Tree = LR_Rotate(Tree);
        }
    } 
    else if (x > Tree->data) {
        Tree->rightChild = Insert(Tree->rightChild, x);
        
        // Rebalance Check
        if (Height(Tree->rightChild) - Height(Tree->leftChild) == 2) {
            if (x > Tree->rightChild->data)
                Tree = RR_Rotate(Tree);
            else
                Tree = RL_Rotate(Tree);
        }
    }
    else {
        return Tree; // Duplicate keys are not allowed in this implementation
    }

    // Update parent height
    Tree->height = max(Height(Tree->leftChild), Height(Tree->rightChild)) + 1;
    return Tree;
}

// Standard Inorder Traversal to print and verify the tree structure
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->leftChild);
        printf("Node: %d (Height: %d)\n", root->data, root->height);
        inorder(root->rightChild);
    }
}

int main() {
    Node* root = NULL;

    // Elements inserted to trigger balances:
    // Inserting 10, 20, 30 will trigger an RR rotation
    printf("Inserting elements into AVL Tree...\n");
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 30); // Triggers RR rotation at 10
    root = Insert(root, 40);
    root = Insert(root, 50); // Triggers RR rotation at 30
    root = Insert(root, 25); // Triggers RL rotation at 20

    printf("\nInorder Traversal of the balanced AVL Tree:\n");
    inorder(root);

    printf("\nRoot element is: %d\n", root->data);

    return 0;
}
