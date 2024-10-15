#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 5050, mod = 1e9 + 7, inf = 1e9;
/*
    枚举第一轮和第二轮的差，将其方案数相乘
    预处理出两轮和的差
    枚举最后一轮的差，求小于前两轮和的差
*/
ll cnt1[N], cnt2[N];
void solve(){
    int n;
    cin >> n;
    vector <int> nums(n+1);
    for (int i = 1; i <= n; ++ i) cin >> nums[i];
    // 不重复枚举前两轮
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j < i; ++ j){
            ++ cnt1[abs(nums[i]-nums[j])];
        }
    }

    for (int i = 1; i < 5000; ++ i){
        for (int j = 1; j <= 5000-i; ++ j){
            cnt2[i+j] += cnt1[i]*cnt1[j];
        }
    }

    for (int i = 2; i <= 5000; ++ i){
        cnt2[i] += cnt2[i-1];
    }
    ll tot = 0;
    // 最后一轮的差 * (前两轮 小于最后一轮的差 的 前缀和)
    for (int i = 2; i <= 5000; ++ i)
        tot += cnt1[i] * cnt2[i-1];
    double deno = n*(n-1)/2;
    cout << (tot / (deno*deno*deno)) << "\n";
}
