#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+1, limi = N-1, Nmi = 200;
long long cnt1[N], g[201][200];
int cnt2[N], f[201][200];
// cnt1[i] 表示小于等于i的数字的 求和 是多少， cnt2[i] 表示 小于等于i的数字 的个数 是多少
// f[i][j], g[i][j] 分别表示%i意义下， 原来大于等于i的数字 %i为 j 的 个数 于 求和

void solve(){
    int n;
    cin >> n;
    vector <int> nums(n);
    for (auto &x : nums){
        cin >> x;
        cnt1[x] += x, cnt2[x] += 1;
        for (int i = 1; i <= min(200, x); ++ i){
            g[i][x%i] += x, f[i][x%i] += 1;
        }
    }

    for (int i = 1; i <= limi; ++ i){
        cnt1[i] += cnt1[i-1], cnt2[i] += cnt2[i-1];
    }

    long long res = 0;
    for (auto &x : nums){
        long long ans = 0;
        if (x <= Nmi){
            for (long long i = 0; i < x; ++ i){
                ans += g[x][i] - i * f[x][i];
            }
        } else {
            ans = cnt1[limi] - cnt1[x-1];
            for (long long j = 1; j*x <= limi; ++ j){
                int l = j*x-1, r = min((j+1)*x-1, 1ll*limi);
                ans -= (cnt1[r] - cnt1[l]) - j*x * (cnt2[r] - cnt2[l]);
            }
        }
        res = max(res, ans);
    }

    cout << res << "\n";
}
 
