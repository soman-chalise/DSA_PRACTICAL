#include <iostream>
using namespace std;

class Node {
public:
    int info;
    Node *left, *right;
    Node(int val) : info(val), left(nullptr), right(nullptr) {}
};

class BST {
public:
    Node *root;

    BST() : root(nullptr) {}

    void insert(int val) {
        Node *newNode = new Node(val);
        if (root == nullptr) {
            root = newNode;
            cout << "Root Node is Added" << endl;
            return;
        }
        Node *current = root, *parent = nullptr;
        while (current != nullptr) {
            parent = current;
            if (val == current->info) {
                cout << "Element already in the tree" << endl;
                delete newNode;
                return;
            }
            current = (val < current->info) ? current->left : current->right;
        }
        if (val < parent->info) {
            parent->left = newNode;
            cout << "Node Added To Left" << endl;
        } else {
            parent->right = newNode;
            cout << "Node Added To Right" << endl;
        }
    }

    void display(Node *ptr, int level) {
        if (ptr != nullptr) {
            display(ptr->right, level + 1);
            cout << endl;
            for (int i = 0; i < level; ++i) cout << "       ";
            cout << ptr->info;
            display(ptr->left, level + 1);
        }
    }

    int min(Node *node) {
        if (node == nullptr) {
            cout << "Tree is empty" << endl;
            return -1;
        }
        while (node->left != nullptr) node = node->left;
        return node->info;
    }

    int height(Node *node) {
        if (node == nullptr) return 0;
        return max(height(node->left), height(node->right)) + 1;
    }

    void mirror(Node *node) {
        if (node) {
            swap(node->left, node->right);
            mirror(node->left);
            mirror(node->right);
        }
    }

    void preorder(Node *node) {
        if (node) {
            cout << node->info << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    void inorder(Node *node) {
        if (node) {
            inorder(node->left);
            cout << node->info << " ";
            inorder(node->right);
        }
    }

    void postorder(Node *node) {
        if (node) {
            postorder(node->left);
            postorder(node->right);
            cout << node->info << " ";
        }
    }

    bool search(Node *node, int val) {
        while (node != nullptr) {
            if (val == node->info) {
                cout << "Element Found..." << endl;
                return true;
            }
            node = (val < node->info) ? node->left : node->right;
        }
        cout << "Element not found..." << endl;
        return false;
    }
};

int main() {
    BST bst;
    int choice, val;

    while (true) {
        cout << "\n-----------------\nOperations on BST\n-----------------" << endl;
        cout << "1. Insert Element\n2. Display\n3. Min value\n4. Height\n5. Mirror\n"
                "6. Preorder\n7. Inorder\n8. Postorder\n9. Longest Path Nodes\n10. Search\n11. Quit"
             << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the number to insert: ";
                cin >> val;
                bst.insert(val);
                break;
            case 2:
                cout << "BST Display:\n";
                bst.display(bst.root, 1);
                cout << endl;
                break;
            case 3:
                cout << "Min value: " << bst.min(bst.root) << endl;
                break;
            case 4:
                cout << "Height of tree: " << bst.height(bst.root) << endl;
                break;
            case 5:
                cout << "Mirror Tree:\n";
                bst.mirror(bst.root);
                bst.display(bst.root, 1);
                cout << endl;
                break;
            case 6:
                cout << "Preorder: ";
                bst.preorder(bst.root);
                cout << endl;
                break;
            case 7:
                cout << "Inorder: ";
                bst.inorder(bst.root);
                cout << endl;
                break;
            case 8:
                cout << "Postorder: ";
                bst.postorder(bst.root);
                cout << endl;
                break;
            case 9:
                cout << "Nodes in longest path from root: " << bst.height(bst.root) << endl;
                break;
            case 10:
                cout << "Enter value to search: ";
                cin >> val;
                bst.search(bst.root, val);
                break;
            case 11:
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
