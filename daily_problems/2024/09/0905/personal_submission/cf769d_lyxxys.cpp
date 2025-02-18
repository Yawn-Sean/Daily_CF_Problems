#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    vector <long long> cnts(10001);
    cin >> n >> k;
    for (int i = 0, x; i < n; ++ i){
        cin >> x;
        ++ cnts[x];
    }
    const int up = 10000;
    long long res = 0;
    for (int i = 0; i <= up; ++ i){
        for (int j = i; j <= up; ++ j){
            if (__builtin_popcount(i^j) == k && cnts[i] && cnts[j]){
                if (i == j) res += (cnts[i])*(cnts[i]-1)/2;
                else res += cnts[i]*cnts[j];
            }
        }
    }

    cout << res << "\n";
}
