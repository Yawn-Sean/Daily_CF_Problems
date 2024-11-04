#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 998244353;

void solve(){
    int n, k;
    cin >> n >> k;
    vector <int> need(n+1), A(n+1), B(n+1), C(n+1), p(n+1);
    iota(p.begin(), p.end(), 0);
    long long all = 0, ans = 0;
    for (int i = 0; i < n; ++ i){
        cin >> need[i] >> A[i] >> B[i];
        C[i] = B[i] - A[i];
        all += need[i];
        ans += 1ll*need[i] * A[i];
    }
    need[n] = (k - all % k) % k;
    sort(p.begin(), p.end(), [&](int x, int y){
        return C[x] > C[y];
    });
    long long c = 0, cur = 0;
    // 先全部选第一个，然后 按差值排序，贪心选第二个，每 k 份 k 份 来贪心
    for (auto &x : p){
        if (need[x] >= k-c){
            cur += 1ll*C[x] * (k - c), need[x] -= k - c;
            if (cur < 0) break;
            ans += cur;
            long long t = (1ll*need[x] / k) * k * C[x];
            if (t < 0) break;
            ans += t;
            c = need[x] % k, cur = 1ll * c * C[x];
        } else {
            c += need[x];
            cur += 1ll*need[x] * C[x];
            if (cur < 0) break;
        }
    }


    cout << ans << "\n";
}
 
