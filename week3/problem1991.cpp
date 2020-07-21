#include <iostream>
#include <vector>

using namespace std;

struct node {
    struct node *left;
    struct node *right;
    char value;
};

struct node* createNode(char value) {
    struct node* node = new struct node();
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct node* bt;
vector<struct node*> list;

// 전위 순회
void preorder(struct node* root) {
    if(root != NULL && root->value != '.') {
        cout << root->value;
        preorder(root->left);
        preorder(root->right);
    }
}

// 중위 순회
void inorder(struct node* root) {
    if(root != NULL && root->value != '.') {
        inorder(root->left);
        cout << root->value;
        inorder(root->right);
    }
}

// 후위 순회
void postorder(struct node* root) {
    if(root != NULL && root->value != '.') {
        postorder(root->left);
        postorder(root->right);
        cout << root->value;
    }
}

int main() {
    char root, left, right;
    int N;

    cin >> N;

    // Tree 자료구조 생성
    for(int i = 0; i < N; i++) {
        cin >> root >> left >> right;

        if(i == 0) {            
            struct node* root_node = createNode(root);
            struct node* left_node = createNode(left);
            struct node* right_node = createNode(right);
            root_node->left = left_node;
            root_node->right = right_node;

            list.push_back(root_node);
            list.push_back(left_node);
            list.push_back(right_node);
            
            bt = root_node;
        } else {
            struct node* node;
            for(int j = 0; j < list.size(); j++) {
                if(list[j]->value == root) {
                    node = list[j];
                    break;
                }
            }

            struct node* left_node = createNode(left);
            struct node* right_node = createNode(right);
            node->left = left_node;
            node->right = right_node;

            list.push_back(left_node);
            list.push_back(right_node);
        }
    }

    preorder(bt); cout << endl;
    inorder(bt); cout << endl;
    postorder(bt); cout << endl;

    return 0;
}