#include <iostream>
#include <cstring>
using namespace std;

class avl {
    char word[20], mean[50];
    avl *left, *right;
    int ht;

public:
    avl() {
        left = right = nullptr;
        ht = 0;
        word[0] = mean[0] = '\0';
    }

    avl* create(avl *root) {
        int n;
        char w[20], m[50];
        cout << "\n Enter the number of words:\t";
        cin >> n;
        for (int i = 0; i < n; i++) {
            cout << "\n Enter word " << i + 1 << ": ";
            cin >> w;
            cout << "Enter the meaning: ";
            cin >> m;
            root = insert(root, w, m);
        }
        return root;
    }

    avl* insert(avl *root, char w[], char m[]) {
        if (root == nullptr) {
            root = new avl;
            strcpy(root->word, w);
            strcpy(root->mean, m);
            return root;
        }

        if (strcmp(w, root->word) > 0) {
            root->right = insert(root->right, w, m);
            if (BF(root) == -2) {
                if (strcmp(w, root->right->word) >= 0)
                    root = rotateLeft(root);
                else
                    root = RL(root);
            }
        } else if (strcmp(w, root->word) < 0) {
            root->left = insert(root->left, w, m);
            if (BF(root) == 2) {
                if (strcmp(w, root->left->word) <= 0)
                    root = rotateRight(root);
                else
                    root = LR(root);
            }
        }
        root->ht = height(root);
        return root;
    }

    void display(avl* root) {
        if (root != nullptr) {
            display(root->left);
            cout << "\n" << root->word << " :: " << root->mean << " (BF = " << BF(root) << ")";
            display(root->right);
        }
    }

    int height(avl* root) {
        if (!root) return 0;
        int lh = root->left ? 1 + root->left->ht : 0;
        int rh = root->right ? 1 + root->right->ht : 0;
        return max(lh, rh);
    }

    int BF(avl* root) {
        if (!root) return 0;
        int lh = root->left ? 1 + root->left->ht : 0;
        int rh = root->right ? 1 + root->right->ht : 0;
        return lh - rh;
    }

    avl* rotateLeft(avl* x) {
        avl* y = x->right;
        x->right = y->left;
        y->left = x;
        x->ht = height(x);
        y->ht = height(y);
        return y;
    }

    avl* rotateRight(avl* x) {
        avl* y = x->left;
        x->left = y->right;
        y->right = x;
        x->ht = height(x);
        y->ht = height(y);
        return y;
    }

    avl* RR(avl* T) {
        return rotateLeft(T);
    }

    avl* LL(avl* T) {
        return rotateRight(T);
    }

    avl* LR(avl* T) {
        T->left = rotateLeft(T->left);
        return rotateRight(T);
    }

    avl* RL(avl* T) {
        T->right = rotateRight(T->right);
        return rotateLeft(T);
    }

    avl* Delete(avl* T, char* w) {
        if (!T) {
            cout << "\nWord not found.";
            return T;
        }

        if (strcmp(w, T->word) > 0) {
            T->right = Delete(T->right, w);
            if (BF(T) == 2) {
                if (BF(T->left) >= 0)
                    T = LL(T);
                else
                    T = LR(T);
            }
        } else if (strcmp(w, T->word) < 0) {
            T->left = Delete(T->left, w);
            if (BF(T) == -2) {
                if (BF(T->right) <= 0)
                    T = RR(T);
                else
                    T = RL(T);
            }
        } else {
            if (T->right) {
                avl* p = T->right;
                while (p->left) p = p->left;
                strcpy(T->word, p->word);
                strcpy(T->mean, p->mean);
                T->right = Delete(T->right, p->word);
                if (BF(T) == 2) {
                    if (BF(T->left) >= 0)
                        T = LL(T);
                    else
                        T = LR(T);
                }
            } else {
                return T->left;
            }
        }

        T->ht = height(T);
        return T;
    }

    avl* mirror(avl* temp) {
        if (!temp) return nullptr;
        avl* p = new avl;
        strcpy(p->word, temp->word);
        strcpy(p->mean, temp->mean);
        p->left = mirror(temp->right);
        p->right = mirror(temp->left);
        return p;
    }

    avl* update(avl* root) {
        char w[20], m[50];
        cout << "\nEnter the word to update: ";
        cin >> w;
        cout << "Enter the new meaning: ";
        cin >> m;

        avl* temp = root;
        while (temp != nullptr) {
            if (strcmp(w, temp->word) == 0) {
                strcpy(temp->mean, m);
                break;
            }
            temp = (strcmp(w, temp->word) < 0) ? temp->left : temp->right;
        }
        return root;
    }
};

int main() {
    avl d, *root = nullptr, *root1;
    int ch;
    char z, w[20], m[50];

    cout << "CREATION OF AVL";
    do {
        cout << "\n1. Create\n2. Insert\n3. Delete\n4. Display\n5. Update\n6. Descending Order\n7. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                root = d.create(root);
                break;
            case 2:
                cout << "\nEnter word: ";
                cin >> w;
                cout << "Enter meaning: ";
                cin >> m;
                root = d.insert(root, w, m);
                break;
            case 3:
                cout << "\nEnter word to delete: ";
                cin >> w;
                root = d.Delete(root, w);
                break;
            case 4:
                cout << "\nWords in ascending order:";
                d.display(root);
                break;
            case 5:
                root = d.update(root);
                break;
            case 6:
                cout << "\nWords in descending order:";
                root1 = d.mirror(root);
                d.display(root1);
                break;
            case 7:
                cout << "Exit.\n";
                return 0;
        }
        cout << "\nDo you want to continue? (Y/N): ";
        cin >> z;
    } while (z == 'Y' || z == 'y');

    return 0;
}
