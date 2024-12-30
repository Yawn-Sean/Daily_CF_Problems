#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, const T &b){
    if (b < a) a = b;
}

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    map <int,int> mps;
    for (int i = 0; i < n; ++ i){
        int x;
        cin >> x;
        mps[x] += 1;
    }
    for (int i = 0; i < m; ++ i){
        int x;
        cin >> x;
        mps[x] -= 1;
    }

    int lst = 0;
    for (auto it = mps.rbegin(); it != mps.rend(); ++ it){
        assert(lst <= 0);
        if (it->second > 0 && it->second > abs(lst)){
            cout << "YES\n";
            return;
        }
        lst += it->second;
    }
    cout << "NO\n";
}
