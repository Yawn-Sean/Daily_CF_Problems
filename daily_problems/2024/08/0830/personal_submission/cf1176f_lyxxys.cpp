#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
long long f[N+10][10];

void solve(){
    int t;
    cin >> t;
    
    for (int i = 1; i < 10; ++ i) f[0][i] = -1e18;

    for (int i = 1, n; i <= t; ++ i){
        cin >> n;
        vector <vector<int>> ts(4);
        for (int i = 1, c, d; i <= n; ++ i){
            cin >> c >> d;
            ts[c].push_back(d);
        }
        for (int i = 1; i < 4; ++ i) sort(ts[i].begin(), ts[i].end(), greater<int>());
        for (int j = 0; j < 10; ++ j) f[i][j] = f[i-1][j];
        // 枚举子集
        for (int c1 = 0; c1 <= 3 && c1 <= ts[1].size(); ++ c1){
            for (int c2 = 0; c1+2*c2 <= 3 && c2 <= ts[2].size(); ++ c2){
                for (int c3 = 0; c1+2*c2+3*c3 <= 3 && c3 <= ts[3].size(); ++ c3){
                    long long sums = 0;
                    int Max = 0;
                    for (int i = 0; i < c1; ++ i){
                        sums += ts[1][i];
                        Max = max(ts[1][i], Max);
                    }
                    for (int i = 0; i < c2; ++ i){
                        sums += ts[2][i];
                        Max = max(ts[2][i], Max);
                    }
                    for (int i = 0; i < c3; ++ i){
                        sums += ts[3][i];
                        Max = max(ts[3][i], Max);
                    }
                    for (int j = 0; j < 10; ++ j){
                        long long v = f[i-1][j]+sums;
                        int tot = j+c1+c2+c3;
                        if (tot >= 10){
                            v += Max;
                            tot -= 10;
                        }
                        f[i][tot] = max(f[i][tot], v);
                    }
                }
            }
        }
    }

    long long res = 0;
    for (int i = 0; i < 10; ++ i) res = max(res, f[t][i]);
    cout << res << "\n";
}
