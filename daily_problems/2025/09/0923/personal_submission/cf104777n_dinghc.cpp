#include <bits/stdc++.h>

using namespace std;
constexpr int A = 19;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n - 1);
    vector<array<int, 2>> trie{{-1, -1}};
    auto add = [&] (int x) {
        int cur = 0;
        for (int i = A; i >= 0; i--) {
            int j = x >> i & 1;
            if (trie[cur][j] == -1) {
                trie[cur][j] = trie.size();
                trie.push_back({-1, -1});
            }
            cur = trie[cur][j];
        }
    };
    for (int i = 0, xor_ = 0; i < n - 1; i++) {
        scanf("%d", &a[i]);
        xor_ ^= a[i];
        add(xor_);
    }
    for (int x = 0; x < n; x++) {
        int cur = 0, mx = 0;
        for (int i = A; i >= 0; i--) {
            int j = x >> i & 1;
            if (trie[cur][j ^ 1] != -1) {
                cur = trie[cur][j ^ 1];
                mx |= 1 << i;
            } else {
                cur = trie[cur][j];
            }
        }
        if (mx < n) {
            int b = x;
            printf("%d ", b);
            for (int i = 0; i < n - 1; i++) {
                b ^= a[i];
                printf("%d ", b);
            }
            printf("\n");
            break;
        }
    }
    return 0;
}

