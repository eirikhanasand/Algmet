#include <iostream>
#include <iomanip>

enum Color { RED, BLACK };

struct Node {
    int location;
    char value;
    Color color;
    Node* parent;
    Node* left;
    Node* right;
};

void printTwoThreeFourTree(Node* node);
void printTwoThreeFourTreeWithVisual(Node* node);
void printTwoThreeFourTreeInlineNumbers(Node* node);
void printTwoThreeFourTreeInlineValues(Node* node);

class RedBlackTree {
private:
    Node* root;
    int members = 0;

    // Function to perform left rotation
    void leftRotate(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        if (y->left != nullptr) {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            root = y;
        } else if (x == x->parent->left) {
            x->parent->left = y;
        } else {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }

    // Function to perform right rotation
    void rightRotate(Node* y) {
        Node* x = y->left;
        y->left = x->right;

        if (x->right != nullptr) {
            x->right->parent = y;
        }

        x->parent = y->parent;

        if (y->parent == nullptr) {
            root = x;
        } else if (y == y->parent->left) {
            y->parent->left = x;
        } else {
            y->parent->right = x;
        }

        x->right = y;
        y->parent = x;
    }

public:
    // Constructor
    RedBlackTree() : root(nullptr) {}

    // Insert a value into the Red-Black Tree
    void insert(char value) {
        members++;
        Node* newNode = new Node{members, value, RED, nullptr, nullptr, nullptr};
        if (root == nullptr) {
            root = newNode;
            root->color = BLACK;
        } else {
            Node* parent = nullptr;
            Node* current = root;

            while (current != nullptr) {
                parent = current;
                if (newNode->value < current->value) {
                    current = current->left;
                } else {
                    current = current->right;
                }
            }

            newNode->parent = parent;

            if (newNode->value < parent->value) {
                parent->left = newNode;
            } else {
                parent->right = newNode;
            }
        }
    }

    Node* getRoot() {
        return root;
    }
};

int main() {
    RedBlackTree rbTree;

    char text[] = "STRAFFESAKADVOKATEN";

    for (char letter : text) {
        rbTree.insert(letter);
    }

    printTwoThreeFourTree(rbTree.getRoot());

    return 0;
}

// Function to print a 2-3-4 Tree in-order
void printTwoThreeFourTree(Node* node) {
    printTwoThreeFourTreeInlineNumbers(node);
    std::cout << std::endl;
    printTwoThreeFourTreeInlineValues(node);
    std::cout << std::endl;
}

// Function to print a 2-3-4 Tree in-order
void printTwoThreeFourTreeInlineNumbers(Node* node) {
    if (node == nullptr) return;
    printTwoThreeFourTreeInlineNumbers(node->left);
    printTwoThreeFourTreeInlineNumbers(node->right);
}

// Function to print a 2-3-4 Tree in-order
void printTwoThreeFourTreeInlineValues(Node* node) {
    if (node == nullptr) return;
    printTwoThreeFourTreeInlineValues(node->left);
    printTwoThreeFourTreeInlineValues(node->right);
    std::cout << std::setw(3) << node->location << ": ";
}

// Function to print a 2-3-4 Tree in-order
void printTwoThreeFourTreeWithVisual(Node* node) {
    if (node == nullptr) return;
    printTwoThreeFourTreeWithVisual(node->left);
    printTwoThreeFourTreeWithVisual(node->right);
    std::cout << std::setw(3) << node->location << ": " << node->value << "\n";
}