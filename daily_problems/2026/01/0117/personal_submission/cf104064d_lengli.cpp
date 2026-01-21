#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    const long long INF = 1e9;

    long long add_ma = -INF, add_mi = INF;
    long long minus_ma = -INF, minus_mi = INF;

    for(int i = 0; i < n; ++i){
        long long x, y;
        cin >> x >> y;
        add_ma = max(add_ma, x + y);
        add_mi = min(add_mi, x + y);
        minus_ma = max(minus_ma, x - y);
        minus_mi = min(minus_mi, x - y);
    }

    if(add_ma == add_mi && minus_ma == minus_mi){
        cout << 4 << "\n";
    } else if(add_ma == add_mi || minus_ma == minus_mi){
        cout << (add_ma - add_mi + minus_ma - minus_mi + 5) << "\n";
    } else {
        cout << (add_ma - add_mi + minus_ma - minus_mi + 4) << "\n";
    }

    return 0;
}
