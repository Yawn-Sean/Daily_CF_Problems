#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;


void solve(){
    int n;
    cin >> n;
    vector<int> nums(n + 5);
    ll sum = 0;
    for (int i = 1; i <= n; i++) cin >> nums[i];
    for (int i = 1; i <= n; i++) sum += nums[i];
    if (n == 1) cout << nums[1] << endl;
    else if (n == 2) cout << ((nums[1] + nums[2]) ^ nums[1] ^ nums[2]) << endl;
    else cout << (sum ^ (sum - nums[1]) ^ (sum - nums[n]) ^ (sum - nums[1] - nums[n])) << endl;
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _T = 1;
    cin >> _T;
    while (_T--){ 
        solve();
    }
    return 0;
}
