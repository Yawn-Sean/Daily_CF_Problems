#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1e9 + 7;

const int MAX_BITS = 30;
struct TrieNode {
    TrieNode* ch[2];
    int count;
    TrieNode() {
        ch[0] = ch[1] = nullptr;
        count = 0;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(int num) {
        TrieNode* node = root;
        for (int i = MAX_BITS - 1; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->ch[bit]) {
                node->ch[bit] = new TrieNode();
            }
            node = node->ch[bit];
            node->count++;
        }
    }

    int findMinXor(int num) {
        TrieNode* node = root;
        int minXor = 0;
        for (int i = MAX_BITS - 1; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->ch[bit] && node->ch[bit]->count > 0) {
                node = node->ch[bit];
                node->count--;
            } else {
                minXor |= (1 << i);
                node = node->ch[bit ^ 1];
                node->count--;
            }
        }
        return minXor;
    }

private:
    TrieNode* root;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    /*
        01前缀树
        1. 寻找min-xor就是找最长的01前缀
        2. 删除一个元素就是把01前缀树的叶子节点的个数减1
    */
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto& x: a) {
        cin >> x;
    }

    Trie t;
    vector<int> p(n);
    for (auto&x: p) {
        cin >> x;
        t.insert(x);
    }


    vector<int> ans;
    for (int i = 0; i < n; i++) {
        int x = t.findMinXor(a[i]);
        ans.emplace_back(x);
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }

    return 0;
}
