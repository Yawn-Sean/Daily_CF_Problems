#include <bits/stdc++.h>
using namespace std;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}

void solve(){
    int n;
    cin >> n;
    vector <string> s(n);
    for (auto &chs : s) cin >> chs;
    vector <int> row1(n), row2(n), col1(n), col2(n);

    int res = 0;
    for (int i = n-1,x,y; i >= 1; -- i){
        x = 0, y = i;
        while (y < n){
            if (s[x][y]-'0' != (row1[x]^col1[y])){
                res += 1;
                row1[x] ^= 1, col1[y] ^= 1;
            }
            x += 1, y += 1;
        }
        x = n-1, y = n-i-1;
        while (y >= 0){
            if (s[x][y]-'0' != row2[x]^col2[y]){
                res += 1;
                row2[x] ^= 1, col2[y] ^= 1;
            }
            x -= 1, y -= 1;
        }
    }

    for (int i = 0; i < n; ++ i){
        if (s[i][i]-'0' != row1[i]^col1[i]^row2[i]^col2[i]){
            res += 1;
        }
    }

    cout << res << "\n";
}
