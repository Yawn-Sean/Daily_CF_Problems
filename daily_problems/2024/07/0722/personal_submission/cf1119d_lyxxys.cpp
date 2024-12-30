#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = unsigned long long;
const int N = 30, mod = 1070777777, inf = 1e9;

void solve(){
    int n;
    cin >> n;
    vector <ll> nums(n+1), d(n+1), Pre(n+1);
    for (int i = 1; i <= n; ++ i) cin >> nums[i];
    sort(nums.begin()+1, nums.end());
    for (int i = 1; i <= n; ++ i) d[i] = nums[i]-nums[i-1];

    sort(d.begin()+2, d.end());
    for (int i = 2; i <= n; ++ i) Pre[i] = Pre[i-1] + d[i];
    int q;
    cin >> q;
    while (q--){
        ll l, r;
        cin >> l >> r;
        int pos = upper_bound(d.begin()+2, d.end(), r-l) - d.begin();
        -- pos;
        ll res = 1ll*(n-pos+1)*(r-l+1) + Pre[pos];
        cout << res << " ";
    }
    cout << "\n";
}
