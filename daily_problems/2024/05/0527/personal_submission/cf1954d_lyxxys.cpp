#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5050, inf = 0x3f3f3f3f, P = 998244353;

void solve(){
    int n;
    cin >> n;
    vector <int> a(n+1), f(N);  //记f[x]为当前总数为x的方案数
    f[0] = 1;
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    sort(a.begin()+1, a.end());

    int res = 0;
    for (int i = 1, sum = 0; i <= n; ++ i){
        int num = a[i];
        for (int j = sum; j >= 0; -- j)  //从sum开始枚举，一定可以遍历所有的集合
            if (f[j]){
                res += 1ll*f[j] * max((j+num+1)/2, num)%P, res %= P;
                f[j+num] += f[j], f[j+num] %= P;
            }
        sum += num;
    }

    cout << res << "\n";
}
