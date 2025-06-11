#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using f64 = long double;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, const T &b){
    if (b < a) a = b;
}

void solve(){
    int n, x, a, y, b;
    i64 tar;

    cin >> n;
    vector <int> price(n);
    for (auto &x : price){
        cin >> x;
    }
    sort(price.begin(), price.end(), greater<int>());

    cin >> x >> a >> y >> b >> tar;
    i64 c = 1ll*a*b / __gcd(a, b);
    int j1 = a, j2 = b, pay1 = x, pay2 = y;
    if (x < y) swap(j1, j2), swap(pay1, pay2);
    assert(pay1 >= pay2);

    auto chk = [&](int mid)->bool{
        i64 ans = 0;
        int j = 0;
        for (i64 i = c; i <= mid; i += c){
            ans += price[j++]/100 * (x+y);
        }
        for (int i = j1; i <= mid; i += j1){
            if (i%j2 == 0) continue;
            ans += price[j++]/100 * pay1;
        }
        for (int i = j2; i <= mid; i += j2){
            if (i%j1 == 0) continue;
            ans += price[j++]/100 * pay2;
        }
        return ans >= tar;
    };

    int lo = 1, hi = n;
    while (lo < hi){
        int mid = (lo+hi) >> 1;
        if (chk(mid)) hi = mid;
        else lo = mid+1;
    }
    if (chk(n)){
        cout << lo << "\n";
    } else {
        cout << -1 << "\n";
    }
}
