#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

constexpr int M = 1E7;

int trie[M][2], cnt[M];

int tot = 0;
int newNode() {
    int x = ++tot;
    trie[x][0] = trie[x][1] = 0;
    cnt[x] = 0;
    return x;
}

void insert(int x) {
    int p = 1;
    cnt[p]++;
    for (int i = 29; ~i; i--) {
        int u = x >> i & 1;
        if (!trie[p][u]) {
            trie[p][u] = newNode();
        }
        p = trie[p][u];
        cnt[p]++;
    }
}

int query(int x) {
    int p = 1, ret = 0;
    for (int i = 29; ~i; i--) {
        int u = x >> i & 1;
        if (cnt[trie[p][u]]) {
            p = trie[p][u];
            cnt[p]--;
        } else {
            ret |= 1 << i;
            p = trie[p][u ^ 1];
            cnt[p]--;
        }
    }
    return ret;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    newNode();
    std::vector<int> P(N);
    for (int i = 0; i < N; i++) {
        std::cin >> P[i];
        insert(P[i]);
    }

    for (int i = 0; i < N; i++) {
        int x = query(A[i]);
        std::cout << x << " \n"[i == N - 1];
    }

    return 0;
}
