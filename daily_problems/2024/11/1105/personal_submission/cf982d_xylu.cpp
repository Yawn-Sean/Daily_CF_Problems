#include <bits/stdc++.h>
using namespace std;

void solveD() {
    int n;
    cin >> n;
    vector<int> a(n), idx(n), fa(n), sz(n, 1);
    for (int i = 0; i < n; i++) cin >> a[i];
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j) { return a[i] < a[j]; });
    iota(fa.begin(), fa.end(), 0);
    unordered_map<int, int> mp;

    auto find = [&](auto self, int x) -> int {
        return fa[x] == x ? x : fa[x] = self(self, fa[x]);
    };

    auto merge = [&](int x, int y) {
        x = find(find, x);
        y = find(find, y);
        if (x != y) {
            mp[sz[x]]--;
            if (mp[sz[x]] == 0) mp.erase(sz[x]);
            mp[sz[y]]--;
            if (mp[sz[y]] == 0) mp.erase(sz[y]);
            fa[x] = y;
            sz[y] += sz[x];
            mp[sz[y]]++;
        }
    };

    int cnt = 0, ans = 0;
    for (int i : idx) {
        mp[1]++;
        if (i && a[i-1] <= a[i]) merge(i-1, i);
        if (i < n-1 && a[i] >= a[i+1]) merge(i, i+1);
        if (mp.size() == 1 && mp.begin()->second > cnt) {
            cnt = mp.begin()->second;
            ans = a[i] + 1;
        }
    }
    cout << ans << '\n';
}

int main() {
    solveD();
    return 0;
}
