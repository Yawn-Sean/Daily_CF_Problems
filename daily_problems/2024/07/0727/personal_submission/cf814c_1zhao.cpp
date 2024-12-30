#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    unordered_map<int, int> cache;

    int q;
    cin >> q;
    while(q --) {
        int m;
        char c;
        cin >> m >> c;
        int hc = (m << 10) + c;
        if(cache.count(hc)) {
            cout << cache[hc] << endl;
            continue;
        }

        int mx = 0, cnt = 0;
        for(int l=0, r=0; r<n; r++) {
            if(s[r] != c) {
                cnt ++;
            }
            while(cnt > m) {
                if(s[l] != c) {
                    cnt --;
                }
                l ++;
            }
            mx = max(mx, r-l+1);
        }
        cache[hc] = mx;
        cout << mx << endl;
    }
}
