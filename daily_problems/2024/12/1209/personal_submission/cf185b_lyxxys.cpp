#include <bits/stdc++.h>
using namespace std;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}

void solve(){
    int s, a, b, c;
    cin >> s >> a >> b >> c;
    cout << fixed << setprecision(15);
    if (a || b || c){
        const long double tot = a+b+c;
        cout << (s*a/tot) << " " << (s*b/tot) << " " << (s*c/tot) << "\n";
    } else {
        cout << 0 << " " << 0 << " " << s << "\n";
    }
}
