#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_NODES 50

// A Huffman tree node
struct MinHeapNode {
    char data;
    float freq;
    struct MinHeapNode *left, *right;
};

// Function to create a new node
struct MinHeapNode* newNode(char data, float freq) {
    struct MinHeapNode* temp = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

// Simple manual sorting function to keep the list of nodes ordered by frequency
void sortNodes(struct MinHeapNode* array[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (array[j]->freq > array[j + 1]->freq) {
                struct MinHeapNode* temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// Function to print codes from the root of Huffman Tree
void printCodes(struct MinHeapNode* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if (!(root->left) && !(root->right)) {
        printf("  %c: ", root->data);
        for (int i = 0; i < top; ++i)
            printf("%d", arr[i]);
        printf("\n");
    }
}

// Function to decode the encoded string using the Huffman Tree
void decodeSequence(struct MinHeapNode* root, const char* bitStream) {
    struct MinHeapNode* curr = root;
    printf("Decoded String: ");
    for (int i = 0; bitStream[i] != '\0'; i++) {
        if (bitStream[i] == '0') {
            curr = curr->left;
        } else {
            curr = curr->right;
        }

        // Leaf node reached
        if (curr->left == NULL && curr->right == NULL) {
            printf("%c", curr->data);
            curr = root;
        }
    }
    printf("\n");
}

int main() {
	char arr[] = { 'a', 'b', 'c', 'd', 'e' };
    int freq[] = { 50, 15, 25, 40, 35 };
    int size = sizeof(arr) / sizeof(arr[0]);

    struct MinHeapNode* nodes[MAX_TREE_NODES];
    for (int i = 0; i < size; i++) {
        nodes[i] = newNode(arr[i], freq[i]);
    }

    int current_size = size;

    // Build the tree
    while (current_size > 1) {
        sortNodes(nodes, current_size);

        // Take the two lowest nodes
        struct MinHeapNode* left = nodes[0];
        struct MinHeapNode* right = nodes[1];

        // Create an internal parent node
        struct MinHeapNode* top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        // Shift remaining items left in array
        for (int i = 2; i < current_size; i++) {
            nodes[i - 2] = nodes[i];
        }
        nodes[current_size - 2] = top;
        current_size--;
    }

    struct MinHeapNode* root = nodes[0];

    // Print generated codes
    int codeArr[MAX_TREE_NODES], top = 0;
    printf("--- Huffman Codes Generated ---\n");
    printCodes(root, codeArr, top);
    printf("\n");

    // Decode sequence
    const char* bitSequence = "100010111001010";
    printf("Encoded Bit Sequence: %s\n", bitSequence);
    decodeSequence(root, bitSequence);

    return 0;
}
