#include <bits/stdc++.h>

using namespace std;
constexpr int A = 30;

struct node : public array<int, 2> {
    int cnt;
    node() : cnt(0) { this->fill(-1); }
};

const node empty_node{};
vector<node> trie {empty_node};
void add(int x) {
    int curr = 0;
    for (int i = A; i >= 0; i--) {
        int b = (x >> i) & 1;
        if (trie[curr][b] == -1) {
            trie[curr][b] = trie.size();
            trie.push_back(empty_node);
        }
        curr = trie[curr][b];
        trie[curr].cnt += 1;
    }
}

constexpr int N = 300'000;
int a[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0, x; i < n; i++) {
        scanf("%d", &x);
        add(x);
    }
    for (int i = 0; i < n; i++) {
        int x = a[i];
        int res = 0, curr = 0;
        for (int i = A; i >= 0; i--) {
            int b = (x >> i) & 1;
            if (trie[curr][b] == -1 || trie[trie[curr][b]].cnt == 0) {
                res |= 1 << i;
                curr = trie[curr][b ^ 1];
            } else {
                curr = trie[curr][b];
            }
            trie[curr].cnt -= 1;
        }
        printf("%d ", res);
    }
    return 0;
}

