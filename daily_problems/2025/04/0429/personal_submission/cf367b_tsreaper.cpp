#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, m, K, A[MAXN + 5];

unordered_map<int, int> mp;
int bad;

void add(int x) {
    int t = ++mp[x];
    if (t == 0) bad--;
    else if (t == 1) bad++;
}

void del(int x) {
    int t = --mp[x];
    if (t == 0) bad--;
    else if (t == -1) bad++;
}

int main() {
    scanf("%d%d%d", &n, &m, &K);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    
    for (int i = 1; i <= m; i++) {
        int x; scanf("%d", &x);
        add(x);
    }

    vector<int> ans;
    for (int t = 1; t <= K && t <= n; t++) {
        long long r = t + 1LL * (m - 1) * K;
        if (r > n) continue;
        for (int i = t; i <= r; i += K) del(A[i]);
        for (int i = r, j = t; ; i += K, j += K) {
            if (bad == 0) ans.push_back(j);
            if (i + K > n) {
                for (; j <= i; j += K) add(A[j]);
                break;
            }
            add(A[j]);
            del(A[i + K]);
        }
    }

    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for (int x : ans) printf("%d ", x);
    printf("\n");
    return 0;
}
