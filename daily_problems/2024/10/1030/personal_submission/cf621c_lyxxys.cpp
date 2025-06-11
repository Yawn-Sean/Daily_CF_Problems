#include <bits/stdc++.h>
using namespace std;
using ld = long double;
const long double Pi = acos(-1.0);
template <class T> void fmax(T &a, T b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}

void solve(){
    int n, p;
    cin >> n >> p;
    vector <ld> pros;

    for (int i = 0, l,r; i < n; ++ i){
        cin >> l >> r;
        int x = r/p - (l-1)/p;
        pros.push_back((ld)x/(r-l+1));
    }

    ld ans = 0;
    for (int i = 0; i < n; ++ i){
        ld x = pros[i], y = pros[(i+1)%n];
        ans += x+y - x*y;
    }

    cout << fixed << setprecision(10) << ans * 2000 << "\n";
}
