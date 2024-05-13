#include <bits/stdc++.h>
using namespace std;

int n, m, cnt;
vector<int> fa(1010), height(1010);

void init(int n) {
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        height[i] = 1;
    }
}

int find(int x) {
    if (fa[x]!= x) {
        fa[x] = find(fa[x]);
    }
    return fa[x];
}

void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx == fy) {
        cnt++;
        return;
    }
    fa[fx] = fy;
    height[fy] += height[fx];
    return;
}

int main() {
    cin >> n >> m;
    init(n);
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        merge(x, y);
        vector<int> sums;
        for (int i = 1; i <= n; i++) {
            if (i == find(i)) {
                sums.push_back(height[i]);
            }
        }
        int ans = 0;
        sort(sums.begin(), sums.end(), greater<int>());
        for (int i = 0; i <= cnt; i++) {
            ans += sums[i];
        }
        cout << ans-1 << endl;
    }
    return 0;
}