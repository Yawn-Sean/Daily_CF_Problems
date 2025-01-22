#include <bits/stdc++.h>
using namespace std;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}

void solve(){
    int n;
    cin >> n;
    vector <int> ans(n+1);
    
    for (int i = n; i >= 1; -- i){
        if (ans[i]) continue;
        int d = 32 - __builtin_clz(i);
        int cur = 0;
        for (int j = 0; j < d; ++ j){
            if (!((i>>j)&1)){
                cur += 1 << j;
            }
        }
        ans[cur] = i;
        ans[i] = cur;
    }

    long long res = 0;
    for (int i = 0; i <= n; ++ i){
        res += i^ans[i];
    }
    cout << res << "\n";
    for (int i = 0; i <= n; ++ i){
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << "\n";
}
