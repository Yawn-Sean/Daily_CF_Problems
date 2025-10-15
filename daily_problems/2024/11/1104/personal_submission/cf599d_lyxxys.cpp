
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long double Pi = acos(-1.0);
template <class T> void fmax(T &a, T b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}

void solve(){
    long long x;
    cin >> x;
    const int limi = cbrt(6*x)+1;

    vector <array<long long,2>> ans1;
    long long all = x*6;
    for (long long i = 1; i <= min(1ll*limi, x); ++ i){
        long long cur = i*i + i;
        if (all%cur == 0){
            cur = all/cur;
            cur += i-1;
            if (cur%3 == 0){
                if (i > cur/3) break;
                ans1.push_back({i, cur/3});
            }
        }
    }

    vector <array<long long,2>> ans2;
    for (auto it : ans1){
        if (it[0]==it[1]) continue;
        swap(it[0], it[1]);
        ans2.push_back(it);
    }
    cout << (ans1.size()+ans2.size()) << "\n";

    reverse(ans2.begin(), ans2.end());

    for (auto &it : ans1) cout << it[0] << " " << it[1] << "\n";
    for (auto &it : ans2) cout << it[0] << " " << it[1] << "\n";
}

