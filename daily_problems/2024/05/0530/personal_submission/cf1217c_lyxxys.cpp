#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Pii = pair<int,int>;

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    vector <int> f(n+1);
    for (int i = 1; i <= n; ++ i)
        if (s[i] == '0') f[i] = f[i-1] + 1;
        else f[i] = 0;

    ll res = 0;
    for (int i = 1, left, sum; i <= n; ++ i){
        left = max(1, i-18), sum = 0;
        for (int j = i; j >= left; -- j){
            if (s[j] == '1'){
                sum += 1 << i-j;
                if (f[j-1] + (i-j+1) >= sum) ++ res;  //如果长度大于等于当前值，统计这个到答案
            }
        }
    }
    cout << res << "\n";
}
