#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, h;
    cin >> n >> h;
    vector<pair<int, int> > fl(n);
    for(int i=0; i<n; i++) cin >> fl[i].first >> fl[i].second;

    vector<int> s(n+1);
    for(int i=1; i<=n; i++) {
        s[i] = s[i-1] + (fl[i-1].second - fl[i-1].first);
    }

    int res = 0;
    for(int i=0; i<n; i++) {
        int start = fl[i].first;
        int l=i, r=n-1;
        while(l<r) {
            int m = (l + r + 1) / 2;
            int d = fl[m].first - fl[i].second - (s[m] - s[i+1]);
            if(h-d > 0) l = m;
            else r = m-1;
        }
        res = max(res, fl[l].second - start + h - (fl[l].first - fl[i].second - (s[l] - s[i+1])));
    }

    cout << res << endl;
}
