struct Node {
    int ID;
    Node *left, *right;
    Node(int id) { ID = id; left = right = nullptr;  }
};

Node* gRoot = nullptr;

bool areSisters(const Node* t, const Node* s1, const Node* s2) {
    if (!t) return false;
    
    return (
           (t->left == s1 && t->right == s2) 
        || (t->left == s2 && t->right == s1)
        || areSisters(t->left, s1, s2)
        || areSisters(t->right, s1, s2)
    );
}


void cutTreTo(Node* t, const int value) {
    if (t->left) {
        if (t->left->ID >= value) {
            t->left = nullptr;
        } else {
            cutTreTo(t->left, value);
        }
    }

    if (t->right) {
        if (t->right->ID >= value) {
            t->right = nullptr;
        } else {
            cutTreTo(t->right, value);
        }
    }
}

int main() {
    areSisters(gRoot, nullptr, nullptr);
    return 0;
}