#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7, INF = 1e9, N = 2e5+11, M = N;

void solve(){
    int n;
    cin >> n;
    vector <array<int,2>> d(n+1);
    vector <int> permu(n+1);

    for (int i = 1; i <= n; ++ i) cin >> d[i][0] >> d[i][1];  //思路是谁包含谁，谁就在前面
    if (n == 3){  //特判掉n=3后两个都互相包含的情况
        cout << 1 << " ";
        if (d[2][0] == 3 || d[2][1] == 3) cout << 2 << " " << 3 << "\n";
        else cout << 3 << " " << 2 << "\n";
        return;
    }
    permu[1] = 1;
    for (int j = 1; j < n; ++ j){  
        int i = permu[j];
        int a = d[i][0], b = d[i][1];
        if (d[a][0] == b || d[a][1] == b) permu[j+1] = a;
        else permu[j+1] = b;
    }

    for (int i = 1; i <= n; ++ i){
        cout << permu[i] << "\n "[i<n];
    }
}
