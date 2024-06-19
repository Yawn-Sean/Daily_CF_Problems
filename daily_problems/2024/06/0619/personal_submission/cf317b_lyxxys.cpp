#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1050, inf = 0x3f3f3f3f, mod = 998244353;
const int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

int cod[300][300];

void solve(){
    int n, t;
    cin >> n >> t;
    queue <array<int,2>> Q;
    cod[100][100] = n;
    Q.push({100, 100});

    while (!Q.empty()){
        auto t = Q.front();
        Q.pop();
        int sx = t[0], sy = t[1];
        if (cod[sx][sy] < 4) continue;
        int cnt = cod[sx][sy]/4;
        cod[sx][sy] %= 4;
        for (int i = 0; i < 4; ++ i){
            int x = sx+dx[i], y = sy+dy[i];
            cod[x][y] += cnt;
            if (cod[x][y] >= 4) Q.push({x, y});
        }
    }
    while (t--){
        int x, y;
        cin >> x >> y;
        if (abs(x)+abs(y) > 100) cout << 0 << "\n";
        else cout << cod[x+100][y+100] << "\n";
    }
}
