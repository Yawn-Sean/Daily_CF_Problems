#include <bits/stdc++.h>
#define int long long
using namespace std;


void solve(){
    int n, q;
    cin >> n >> q;
    vector<int> x;
    int ans = 0;
    vector<int> num(n + 1);
    int last = 0;
    vector<int> end(n + 1);

    while (q--) {
        int k, a;
        cin >> k >> a;
        if (k == 1) {
            ans++;
            x.push_back(a);
            num[a]++;
        } else if (k == 2) {
            ans -= num[a];
            num[a] = 0;
            end[a] = x.size();
        } else {
            if (a > last) {
                for (int i = last; i < a; i++) {
                    if (i >= end[x[i]]) {
                        num[x[i]]--;
                        ans--;
                    }
                }
                last = a;
            }
        }
        cout << ans << endl;
    }
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
