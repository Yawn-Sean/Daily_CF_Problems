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

ll sqre(ll x){
    return x*x;
}
struct Circle {
    ll x, y, r;
    bool in_circle(Circle oth){
        ll d = sqre(x-oth.x) + sqre(y-oth.y);
        if (d <= sqre(r-oth.r)) return true;
        else return false;
    }
};
void solve(){
    int n;
    cin >> n;
    vector <Circle> A;
    for (int i = 0; i < n; ++ i){
        ll x, y, r;
        cin >> x >> y >> r;
        A.push_back({x, y, r});
    }
    sort(A.begin(), A.end(), [&](Circle &u, Circle &v){
        return u.r > v.r;
    });

    vector <int> cnt(n);

    long long ans = 0;
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < i; ++ j){
            if (A[i].in_circle(A[j])){
                cnt[i] += 1;
            }
        }
    }
    for (int i = 0; i < n; ++ i){
        ans += sqre(A[i].r) * (max(0, cnt[i]-1)%2 ? -1 : 1);
    }
    
    cout << fixed << setprecision(20) << acosl(-1) * ans << "\n";
}
