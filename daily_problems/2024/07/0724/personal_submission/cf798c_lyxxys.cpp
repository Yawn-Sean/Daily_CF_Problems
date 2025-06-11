#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = unsigned long long;
const int N = 100050, mod = 998244353, inf = 1e9;

void solve(){
    int n;
    cin >> n;
    vector <int> nums(n);
    int d = 0;
    for (auto &x : nums){
        cin >> x;
        d = __gcd(d, x);
    }
    cout << "YES\n";
    if (d > 1){
        cout << 0 << "\n";
        return;
    }
    int res = 0;
    {
        int cnt = 0;
        for (auto &x: nums) {
            if (x%2) ++ cnt;
            else {
                res += cnt/2 + (cnt%2) * 2;
                cnt = 0;
            }
        }
        res += cnt/2 + (cnt%2) * 2;
    }
    cout << res << "\n";
}
