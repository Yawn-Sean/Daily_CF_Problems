#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);

        vector<int> deg(n);
        set<pair<int, int>> st;
        DSU d(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            --a[i];
            int x = i, y = a[i];
            if (x > y) {
                swap(x, y);
            }
            if (st.find({x, y}) == st.end()) {
                st.insert({x, y});
                deg[x]++;
                deg[y]++;
                d.merge(x, y);
            }
        }
        
        map<int,int> cnt;
        for (int i = 0; i < n; i++) {
            int fi = d.find(i);
            ++cnt[fi];
        }

        int ans_max = cnt.size();
        for (int i = 0; i < n; ++i) {
            int fi = d.find(i);
            if (deg[i] < 2) {
                cnt[fi] = 0;
            }   
        }

        int diff = 0;
        for (auto& [k, v] : cnt) {
            if (v == 0) {
                diff++;
            }
        }
        cout << ans_max - max(0, diff - 1) << ' ' << ans_max << '\n';
    }
    return 0;
}
