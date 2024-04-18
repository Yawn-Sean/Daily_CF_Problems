#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

class Node {

public:
    std::string op;
    Node* left;
    Node* right;
    int val;      // 值
    int idx;      // 第idx个节点
    int rev  = 0; // 是否反转

    Node(std::string op, Node* left, Node* right, int idx) : op(op), left(left), right(right), val(-1), idx(idx) {}
};

std::unordered_map<int, Node*> m;
Node* root;

void dfs(Node* root) {
    if (root->op == "IN") return;
    if (root->op == "AND") {
        dfs(root->left);
        dfs(root->right);
        root->val = root->left->val & root->right->val;
    } else if (root->op == "OR") {
        dfs(root->left);
        dfs(root->right);
        root->val = root->left->val | root->right->val;
    } else if (root->op == "XOR") {
        dfs(root->left);
        dfs(root->right);
        root->val = root->left->val ^ root->right->val;
    } else if (root->op == "NOT") {
        dfs(root->left);
        root->val = !root->left->val;
    } 
}

void f(Node* root) {
    if(root == nullptr) return;
    if(!root->rev || root->op == "IN")  return;
    if (root->op == "AND") {
        if (root->right->val == 1) {
            root->left->rev = 1;
        }
        if (root->left->val == 1) {
            root->right->rev = 1;
        }
    } else if (root->op == "OR") {
        if (root->right->val == 0) {
            root->left->rev = 1;
        }
        if (root->left->val == 0) {
            root->right->rev = 1;
        }
    } else if (root->op == "XOR") {
        root->right->rev = root->left->rev = 1;
    } else if (root->op == "NOT") {
        root->left->rev = 1;
    }
    f(root->left);
    f(root->right);
    return ;
}

int main() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        m[i] = new Node("", nullptr, nullptr, i);
    }
    for (int i = 1; i <= n; ++i) {
        std::string s;
        std::cin >> s;
        if (s == "IN"){
            int val;
            std::cin >> val;
            m[i]->op = s;
            m[i]->val = val;
        }
        if (s == "AND" || s == "OR" || s == "XOR") {
            int leftIdx, rightIdx;
            std::cin >> leftIdx >> rightIdx;
            m[i]->op = s;
            m[i]->left = m[leftIdx];
            m[i]->right = m[rightIdx];
        } else if (s == "NOT") {
            int leftIdx;
            std::cin >> leftIdx;
            m[i]->op = s;
            m[i]->left = m[leftIdx];
        } 
    }
    root = m[1];
    root->rev = 1;
    dfs(root);
    f(root);
    
    int flg = root->val;
    for (int i = 1; i <= n; ++i) {
        if (m[i]->op == "IN") {
            std::cout <<((m[i]->rev) ^ flg);
        }
    }
   
    return 0;
}