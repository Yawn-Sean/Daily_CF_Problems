#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, q;
    cin >> n >> q;
    long long f1 = 0, f2 = 0;
    // 对 两种 不同的 交换 分类讨论
    bool cur = 0;
    auto mods = [&](long long x)->int{
        return (x%n + n)%n;
    };

    while (q--){
        int opt, x;
        cin >> opt;
        if (opt == 1){
            cin >> x;
            f1 += x, f2 += x;
            cur ^= bool(x%2);
        } else {
            if (cur){
                f2 += 1, f1 -= 1;
            } else {
                f2 -= 1, f1 += 1;
            }
            cur ^= 1;
        }
    }
    
    vector <int> ans(n);
    for (int i = 0; i < n; ++ i){
        if (i%2==0){
            ans[mods(i+f1)] = i+1;
        } else {
            ans[mods(i+f2)] = i+1;
        }
    }

    for (auto &x : ans) cout << x << " ";
    cout << "\n";
}
 
