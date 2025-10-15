#include <bits/stdc++.h>
using namespace std;
template <class T> void fmax(T &a, T b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}

void solve(){
    int n, m;
    cin >> n >> m;

    long long A = 0, B = 0, C = 0, D = 0;
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            long long v;
            cin >> v;
            int x = 4*i+2, y = 4*j+2;
            A += v * (x*x + y*y);
            B += v;
            C += v * x;
            D += v * y;
        }
    }

    long long res = 9e18;
    int chose_x = -1, chose_y = -1;
    for (long long i = 0; i <= n; ++ i){
        for (long long j = 0; j <= m; ++ j){
            long long x = 4*i, y = 4*j;
            long long ans = A + (x*x+y*y)*B - 2*(x*C + y*D);
            if (ans < res){
                chose_x = i, chose_y = j;
                res = ans;
            }
        }
    }

    cout << res << "\n";
    cout << chose_x << " " << chose_y << "\n";
}
