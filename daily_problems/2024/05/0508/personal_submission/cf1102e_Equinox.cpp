#include <bits/stdc++.h>
using i64 = long long;
const int N = 2e5 + 10, mod = 998244353;
int n, a[N], diff[N];
std::map<int, int> pre, suf;    //防止卡哈希
 
int main(){
    std::cin >> n;
    for(int i = 0; i < n; i ++ ) { 
        std::cin >> a[i], suf[a[i]] = i;
        if (!pre.count(a[i]))
            pre[a[i]] = i;
    }
    for(auto [x, i] : pre){
            diff[i] ++, diff[suf[x]] --;
    }
    i64 tot = 1;
    for(int i = 0; i < n - 1; i ++) {
        diff[i + 1] += diff[i];
        if (!diff[i])
            tot = tot * 2 % mod;
    }
    std::cout << tot;
    return 0;
}