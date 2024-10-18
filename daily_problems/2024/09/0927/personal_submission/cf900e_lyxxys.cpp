#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+1;
int f[N], g[N], Pre[N], h[N][2];

void solve(){
    int n, m;
    string s;
    cin >> n;
    cin >> s;
    cin >> m;
    s = " " + s;

    for (int i = 1; i <= n; ++ i){
        Pre[i] = Pre[i-1] + (s[i] == '?');
        if (s[i] != 'a') h[i][0] = h[i-1][1] + 1;
        if (s[i] != 'b') h[i][1] = h[i-1][0] + 1;
        f[i] = f[i-1], g[i] = g[i-1];
        if (h[i][m%2] >= m){
            if (f[i-m]+1 > f[i]) f[i] = f[i-m]+1, g[i] = g[i-m] + Pre[i] - Pre[i-m];
            else if (f[i] == f[i-m]+1) g[i] = min(g[i], g[i-m] + Pre[i] - Pre[i-m]); 
        }
    }
    
    cout << g[n] << "\n";
}
