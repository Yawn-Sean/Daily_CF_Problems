#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 105, mod = 1e9 + 7, inf = 1e9;

int f[N][N];
void solve(){
    int n, m;
    cin >> n >> m;
    const int dto[] = {-1,0,1,0,-1};
    memset(f, -1, sizeof f);
    auto find = [&](int x, int y)->int{
        if (f[x][y] != -1) return f[x][y];
        for (int i = 0; i < 26; ++ i) {
            bool flg = true;
            for (int j = 0; j < 4; ++ j) {
                int dx = x + dto[j], dy = y + dto[j+1];
                if (f[dx][dy] == i) flg = false;
            }
            if (flg) return i;
        }
    };
    /*
     *  位置按改位置在 字典序的权重枚举(从左到右，从上到下)， 再尽可能多的让在该位置的字符最小，并让正方形的面积尽可能大
        用枚举顺序和dp判断正方形
    */
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= m; ++ j){
            if (f[i][j] != -1) continue;
            int t = find(i, j);
            int len = 0;
            while (i+len-1 < n && j+len-1 < m && find(i,j+len)==t) ++ len;
            for (int r = i; r <= i+len-1; ++ r){
                for (int c = j; c <= j+len-1; ++ c){
                    f[r][c] = t;
                }
            }
        }
    }

    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= m; ++ j) {
            cout << char(f[i][j] + 'A');
        }
        cout << "\n";
    }
}
