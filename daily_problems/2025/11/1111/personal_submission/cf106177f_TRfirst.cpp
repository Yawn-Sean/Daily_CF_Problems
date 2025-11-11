#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;



void solve(){
    int n;
    cin >> n;
    vector<int> nums(n + 5);
    for (int i = 1; i <= n; i++) cin >> nums[i];
    map<int, int> mp1, mp2;
    int x = 0, y = 0;
    ll ans = 0;
    mp2[0]++;
    for (int i = 1; i <= n; i++) {
        if (nums[i] & 1) x++;
        else y++;
        if (x & 1) {
            mp1[x - y]++;
            ans += mp1[x - y + 1] + mp2[x - y - 1];
        }
        else {
            mp2[x - y]++;
            ans += mp1[x - y - 1] + mp2[x - y + 1];
        }
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int _T = 1;
    cin >> _T;
    while (_T--){ 
        solve();
    }
    return 0;
}