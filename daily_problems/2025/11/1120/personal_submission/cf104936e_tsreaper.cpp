#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define MAXP 30
using namespace std;

int n, K, A[MAXN + 5];

struct Node {
    int cnt, ch[2];
};
vector<Node> trie;

int newNode() {
    int ret = trie.size();
    trie.push_back(Node {0, -1, -1});
    return ret;
}

void add(int x) {
    int now = 0;
    for (int p = MAXP - 1; p >= 0; p--) {
        trie[now].cnt++;
        int b = x >> p & 1;
        if (trie[now].ch[b] < 0) trie[now].ch[b] = newNode();
        now = trie[now].ch[b];
    }
    trie[now].cnt++;
}

void del(int x) {
    int now = 0;
    for (int p = MAXP - 1; p >= 0; p--) {
        trie[now].cnt--;
        int b = x >> p & 1;
        now = trie[now].ch[b];
    }
    trie[now].cnt--;
}

int query(int x) {
    if (trie.size() == 1) return 1 << MAXP;
    int now = 0, ret = 0;
    for (int p = MAXP - 1; p >= 0; p--) {
        int b = x >> p & 1;
        int nxt = trie[now].ch[b];
        if (nxt >= 0 && trie[nxt].cnt > 0) now = nxt, ret = ret << 1;
        else now = trie[now].ch[b ^ 1], ret = ret << 1 | 1;
    }
    return ret;
}

long long gao(int K) {
    trie.clear();
    newNode();

    long long ret = 0;
    for (int i = 1, j = 1; i <= n; i++) {
        while (j < i && query(A[i]) < K) {
            del(A[j]);
            j++;
        }
        add(A[i]);
        ret += i - j + 1;
    }
    return ret;
}

int main() {
    scanf("%d%d", &n, &K);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    printf("%lld\n", gao(K) - gao(K + 1));
    return 0;
}
