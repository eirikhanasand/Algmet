#include <iostream>
#include <vector>

enum Color { RED, BLACK }

/**
 *  Node with ID / key / data and left / right pointers to children
 */
struct Node {
    char ID;
    Node *left, *right;
    Node(char id)  {  ID = id;  left = right = nullptr;  };
    Color color;
}

class TwoThreeFour {
    private:
        Node* root;

    public:
        TwoThreeFourTree() : root(nullptr) {};

        void insert(int value) {
            Node* newNode = new Node{value, RED, nullptr, nullptr, nullptr};
            if (root == nullptr) {
                root = newNode;
                root->color = BLACK;
            } else {
                Node* parent = nullptr;
                Node* current = root;

                while (current != nullptr) {
                    parent = current;
                    if (newNode->data < current->data) {
                        current = current->left;
                    } else {
                        current = current->right;
                    }
                }

                newNode->parent = parent;
                if (newNode->data < parent->data) {
                    parent->left = newNode;
                } else {
                    parent->right = newNode;
                }

                // TODO: Perform necessary Red-Black Tree balancing (fix violations)
            }
        }
}

int main() {

    return 0
}