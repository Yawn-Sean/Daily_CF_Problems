#include <bits/stdc++.h>
using namespace std;
const long double Pi = acos(-1.0);
template <class T> void fmax(T &a, T b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}

void solve(){
    auto error = [&]()->void{
        cout << "MORTAL\n";
    };

    int n, m;
    cin >> n >> m;
    vector <string> s(n);
    vector <int> vis1(n), vis2(m);
    int c = 0;
    bool jg1 = 0;
    for (int i = 0; i < n; ++ i){
        cin >> s[i];
        bool jg = 1;
        for (auto &ch : s[i]){
            c += ch == 'A';
            if (ch == 'P') jg = 0;
        }
        if (jg){
            vis1[i] = 1;
            jg1 = 1;
        }
    }
    if (!c) return error();
    if (c == n*m) return cout << 0 << "\n", void();

    for (int j = 0; j < m; ++ j){
        bool jg = 1;
        for (int i = 0; i < n; ++ i){
            if (s[i][j] == 'P') jg = 0;
        }
        if (jg){
            jg1 = 1;
            vis2[j] = 1;
        }
    }
    // 行或者列被填满
    if (jg1){
        if (vis1[0] || vis1[n-1] || vis2[0] || vis2[m-1]) cout << 1 << "\n";
        else cout << 2 << "\n";
        return;
    }

    if (s[0][0]=='A' || s[0][m-1]=='A' || s[n-1][0]=='A' || s[n-1][m-1]=='A'){
        cout << 2 << "\n";  // 角落有
        return;
    }

    bool jg2 = 0;
    for (int i = 0; i < m; ++ i){
        if (s[0][i] == 'A' || s[n-1][i] == 'A') jg2 = 1;
    }
    for (int i = 0; i < n; ++ i){
        if (s[i][0] == 'A' || s[i][m-1] == 'A') jg2 = 1;
    }

    if (jg2) cout << 3 << "\n";  // 边缘有
    else cout << 4 << "\n";
}
