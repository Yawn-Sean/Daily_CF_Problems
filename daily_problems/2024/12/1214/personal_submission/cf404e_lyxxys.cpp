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
    const int inf = 1e9;

    string s;
    cin >> s;
    int n = s.size();
    
    auto chk = [&](int L)->bool{
        int l = 0, r = 0, cur = 0, sig = s[n-1] == 'L' ? 1 : -1;
        int bound = sig * L;
        for (int i = 0; i < n-1; ++ i){
            int v = s[i] == 'R' ? 1 : -1;
            if (sig == 1){
                if (cur+v < bound) cur += v;
            } else {
                if (cur+v > bound) cur += v;
            }
            fmin(l, cur);
            fmax(r, cur);
        }
        cur += s[n-1] == 'R' ? 1 : -1;
        if (cur < l || cur > r) return true;
        else return false;
    };

    if (chk(inf)){
        cout << 1 << "\n";
        return;
    }

    int lo = 0, hi = n;
    while (lo < hi){
        int mid = (lo+hi+1) >> 1;
        if (chk(mid)) lo = mid;
        else hi = mid-1;
    }

    cout << hi << "\n";
}
