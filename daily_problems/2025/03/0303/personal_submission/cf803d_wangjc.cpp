#include <bits/stdc++.h>
#define int long long
using namespace std;


void solve(){
    int n;
    cin >> n;
    cin.ignore();
    string s;
    getline(cin, s);
    int ans = INT_MAX;
    int len = s.size();
    int l = 1, r = INT_MAX;
    vector<int> pos;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '-' || s[i] == ' ') pos.push_back(i);
    }
    pos.push_back(s.size());

    while (l <= r) {
        vector<int> tem;
        int cnt = 1;
        int now = -1;
        int mid = l + r >> 1;
        int p = 0;
        while (p < pos.size()) {
            if ((p < pos.size() - 1 && pos[p] - now > mid) || (p == pos.size() - 1 && pos[p] - now > mid + 1)) {
                cnt++;
                tem.push_back(pos[p - 1]);
                if (p > 0) now = pos[p - 1];
                else now = -1;
                if (cnt > n) break;
            } else {
                p++;
            }
        }

        if (cnt > n) {
            l = mid + 1;
        } else {
            r = mid - 1;
            ans = min(ans, mid);
        }
    }
    cout << ans << endl;

}
signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);
    int t = 1;
    while (t--) {
       solve();
    }
    return 0;
}
