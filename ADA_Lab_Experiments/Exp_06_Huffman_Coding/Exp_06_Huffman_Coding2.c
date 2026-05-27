#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    int freq;
    struct Node *left, *right;
};

// Create a new node
struct Node* createNode(char data, int freq) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->freq = freq;
    newNode->left = NULL;
	newNode->right = NULL;
    return newNode;
}

// MinHeap structure
#define MAX_SIZE 256
struct MinHeap {
    int size;
    struct Node* array[MAX_SIZE];
};

// Swap helper
void swapNodes(struct Node** a, struct Node** b) {
    struct Node* temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify (bubble down)
void heapify(struct MinHeap* heap, int i) {
    int smallest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left < heap->size && heap->array[left]->freq < heap->array[smallest]->freq)
        smallest = left;

    if (right < heap->size && heap->array[right]->freq < heap->array[smallest]->freq)
        smallest = right;

    if (smallest != i) {
        swapNodes(&heap->array[i], &heap->array[smallest]);
        heapify(heap, smallest);
    }
}

// Insert into heap (bubble up)
void insertHeap(struct MinHeap* heap, struct Node* node) {
    int i = heap->size;
    heap->array[i] = node;
    heap->size++;

    while (i != 0 && heap->array[(i - 1) / 2]->freq > heap->array[i]->freq) {
        swapNodes(&heap->array[i], &heap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Extract minimum node
struct Node* extractMin(struct MinHeap* heap) {
    if (heap->size <= 0) return NULL;
    if (heap->size == 1) {
        heap->size--;
        return heap->array[0];
    }

    struct Node* root = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    heapify(heap, 0);

    return root;
}

// Build Huffman Tree
struct Node* buildHuffmanTree(char data[], int freq[], int n) {
    struct MinHeap heap;
    heap.size = 0;

    // Step 1: Insert all characters into heap
    for (int i = 0; i < n; i++) {
        insertHeap(&heap, createNode(data[i], freq[i]));
    }

    // Step 2: Repeat until only one node remains
    while (heap.size > 1) {
        struct Node* left = extractMin(&heap);
        struct Node* right = extractMin(&heap);

        struct Node* internal = createNode('$', left->freq + right->freq);
        internal->left = left;
        internal->right = right;

        insertHeap(&heap, internal);
    }

    // Final node is root
    return extractMin(&heap);
}

// Print Huffman codes by traversing the tree
void printCodes(struct Node* root, int arr[], int top) {
    // If left child exists, assign 0 and recurse
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    // If right child exists, assign 1 and recurse
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    // If leaf node, print character and its code
    if (!root->left && !root->right) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e'};
    int freq[] =  {20,   15,  10,  15,  15};
    int n = sizeof(data) / sizeof(data[0]);

    struct Node* root = buildHuffmanTree(data, freq, n);

    int arr[MAX_SIZE], top = 0;
    printf("Huffman Codes:\n");
    printCodes(root, arr, top);

    return 0;
}
