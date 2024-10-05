#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int limi = 1e9;

void solve(){
    long long n, k;
    cin >> n >> k;
    if (k > 1e7){
        cout << "No\n";
        return;
    }
    unordered_map <int,int> mps;

    bool jg = 1;
    for (int i = 1; i <= k; ++ i){
        if (mps[n/i * i]){
            jg = 0;
            break;
        }
        mps[n/i * i] = 1;
    }
    cout << (jg ? "Yes\n" : "No\n");
}
 
