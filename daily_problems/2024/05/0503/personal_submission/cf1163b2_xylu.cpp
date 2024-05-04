#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, ans = 1;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    unordered_map<int, int> mp, cnt;
    for (int i = 0; i < n; i++) {
        mp[a[i]]++;
        if (mp[a[i]] > 1) {
            cnt[mp[a[i]]-1]--;
            if (cnt[mp[a[i]]-1] == 0) cnt.erase(mp[a[i]]-1);
        }
        cnt[mp[a[i]]]++;
        if (cnt.size() == 2) {
            auto it = cnt.begin();
            int x = it->first, y = it->second;
            it++;
            int z = it->first, w = it->second;
            if ((x == 1 || x - z == 1) && y == 1 || (z == 1 || z - x == 1) && w == 1) ans = i+1;
        } else if (cnt.size() == 1) {
            auto it = cnt.begin();
            int x = it->first, y = it->second;
            if (x == 1 || y == 1) ans = i+1;
        }
    }
    cout << ans << endl;

    return 0;
}
