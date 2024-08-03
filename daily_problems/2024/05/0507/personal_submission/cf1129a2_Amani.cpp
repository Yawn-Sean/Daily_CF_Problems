#include<bits/stdc++.h>
using namespace std;

const int N = 5005;
int n, m;
vector<int> cnt(N, 0);
vector<int> num(N, 0);

int len(int u, int v) {
    int len = v - u + n;
    if (len >= n) {
        len -= n;
    }
    return len;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        cnt[u]++;  // u要运送的糖果数
        // 以u为起点，v为终点的最短路长度
        if (num[u]) {
            num[u] = min(num[u], len(u, v));
        } else {
            num[u] = len(u, v);
        }
    }
    for (int i = 1; i <= n; i++) {
        int ans = 0;
        for (int j = 1; j <= n; j++) {
            if (cnt[j]) {
                ans = max(ans, len(i, j) + n * (cnt[j] - 1) + num[j]);
            }
        }
        cout << ans << " ";
    }
    return 0;
}