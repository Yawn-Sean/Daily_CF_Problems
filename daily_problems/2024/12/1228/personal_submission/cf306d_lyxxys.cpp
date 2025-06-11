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
    int n;
    cin >> n;
    srand(time(0));
    if (n <= 4){
        cout << "No solution\n";
    } else {
        cout << fixed << setprecision(8);
        f64 angle = acosl(-1)*2 / n, cur = 0;
        f64 x = 0, y = 0, step = 500;
        for (int i = 0; i < n-1; ++ i){
            cout << x << " " << y << "\n";
            cur += angle;
            step += 0.01;
            if (i < n-2){
                x += step * cosl(cur);
                y += step * sinl(cur);
            }
        }
        cout << x - y/tanl(cur) << " " << 0.0 << "\n";
    }
}
