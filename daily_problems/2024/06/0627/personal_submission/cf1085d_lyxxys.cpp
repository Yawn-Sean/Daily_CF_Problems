#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 100050, inf = 1e9;

void solve(){   
    int n, s;
    cin >> n >> s;
    vector <int> deg(n+1);
    for (int i = 1; i < n; ++ i){
        int a, b;
        cin >> a >> b;
        ++ deg[a], ++ deg[b];
    }
    int cnt = 0;
    // 只考虑和叶子节点相连的边
    for (int i = 1; i <= n; ++ i)
        if (deg[i] == 1) ++ cnt;
    
    cout << (2.0*s/cnt) << "\n";
}
