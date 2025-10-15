#pragma GCC optimize(3, "Ofast", "inline", "unroll-loops")
#include<bits/stdc++.h>
using namespace std;

struct Node {
    Node* c[2] = {nullptr, nullptr};
};

void insert(Node* root, int num) 
{
    Node* cur = root;
    for (int i = 29; i >= 0; --i) {
        int bit = (num >> i) & 1;
        if (!cur->c[bit]) cur->c[bit] = new Node();
        cur = cur->c[bit];
    }
}

// 在Trie中找到与x异或结果最大的数
int findMaxXor(Node* root, int x) {
    if (!root) return 0;
    Node* cur = root;
    int max_xor = 0;
    for (int i = 29; i >= 0; --i) {
        int bit = (x >> i) & 1;
        // 优先选择与当前位相反的子节点（最大化异或结果）
        if (cur->c[1 - bit]) {
            max_xor |= (1 << i); // 该位异或结果为1，计入最大值
            cur = cur->c[1 - bit];
        } else {
            // 若相反位不存在，只能选择相同位
            cur = cur->c[bit];
        }
    }
    return max_xor;
}

void sol() {
    int n;
    cin >> n;
    vector<int> a(n-1), p(n);
    for (int i = 0; i < n-1; ++i) {
        cin >> a[i];
        p[i+1] = p[i] ^ a[i];
    }

    Node* root = new Node();
    for (int val : p) insert(root, val);

    // 寻找合法x：x与Trie中元素的最大异或必须为n-1（因b需包含0~n-1）
    int x = 0;
    for (x = 0; x < n; ++x) {
        if (findMaxXor(root, x) == n - 1) {
            // 进一步验证是否所有x^m都在p中（确保是排列）
            bool valid = true;
            for (int m = 0; m < n && valid; ++m) {
                int t = x ^ m;
                Node* cur = root;
                for (int i = 29; i >= 0; --i) {
                    int bit = (t >> i) & 1;
                    if (!cur->c[bit]) { valid = false; break; }
                    cur = cur->c[bit];
                }
            }
            if (valid) break;
        }
    }

    // 输出b数组
    for (int val : p) {
        cout << (x ^ val) << ' ';
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    sol();
    return 0;
}
