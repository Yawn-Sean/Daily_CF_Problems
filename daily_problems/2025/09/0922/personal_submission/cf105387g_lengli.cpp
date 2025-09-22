#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int64 MOD = 1000000007LL;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, kr, kg, kb;
    if (!(cin >> n >> kr >> kg >> kb)) return 0;

    vector<int64> dpR(n+1,0), dpG(n+1,0), dpB(n+1,0), total(n+1,0);
    vector<int64> AR(n+1,0), AG(n+1,0), AB(n+1,0);
    vector<int64> sAR(n+1,0), sAG(n+1,0), sAB(n+1,0);

    total[0] = 1;
    dpR[0] = dpG[0] = dpB[0] = 0;
    AR[0] = AG[0] = AB[0] = 1; 
    sAR[0] = AR[0]; sAG[0] = AG[0]; sAB[0] = AB[0];

    for (int i = 1; i <= n; ++i) {
        int L = min(kr, i);
        int l = i - L, r = i - 1;
        int64 sum = sAR[r];
        if (l - 1 >= 0) sum = (sum - sAR[l-1] + MOD) % MOD;
        dpR[i] = sum % MOD;
        L = min(kg, i);
        l = i - L; r = i - 1;
        sum = sAG[r];
        if (l - 1 >= 0) sum = (sum - sAG[l-1] + MOD) % MOD;
        dpG[i] = sum % MOD;
        L = min(kb, i);
        l = i - L; r = i - 1;
        sum = sAB[r];
        if (l - 1 >= 0) sum = (sum - sAB[l-1] + MOD) % MOD;
        dpB[i] = sum % MOD;

        total[i] = (dpR[i] + dpG[i] + dpB[i]) % MOD;
        AR[i] = (total[i] - dpR[i] + MOD) % MOD;
        AG[i] = (total[i] - dpG[i] + MOD) % MOD;
        AB[i] = (total[i] - dpB[i] + MOD) % MOD;

        sAR[i] = (sAR[i-1] + AR[i]) % MOD;
        sAG[i] = (sAG[i-1] + AG[i]) % MOD;
        sAB[i] = (sAB[i-1] + AB[i]) % MOD;
    }

    cout << total[n] % MOD << "\n";
    return 0;
}
