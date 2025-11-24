#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;


void solve(){
    int n;
    cin >> n;
    vector<ll> nums(n + 5);
    int cnt1 = 0, cnt2 = 0;
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
        sum += nums[i];
        if (nums[i]) cnt1++;
        if (nums[i] >= 2) cnt2++;
    }
    if (!cnt2) cout << 0 << endl;
    else if (n == 2) {
        ll ans = 0;
        int a = nums[1], b = nums[2];
        while (a > 1 || b > 1) {
            int da = a / 2, db = b / 2;
            ans += da + db;
            a %= 2, b %= 2;
            a += db, b += da;
        }
        cout << ans << endl;
    }
    else if (sum == 3 && cnt2 == 1 && cnt1 == 1) cout << 1 << endl;
    else cout << sum - 1 << endl;
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