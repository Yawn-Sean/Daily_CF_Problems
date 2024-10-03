#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = " " + s;
    vector <vector<int>> f(n+1, vector<int>(2*k+1)), befo(n+1, vector<int>(2*k+1));
    int det = k;
    auto id = [&](int x)->int{
        return x + det;
    };

    f[0][id(0)] = 1;
    for (int i = 0; i < n; ++ i){
        for (int j = -k; j <= k; ++ j){
            // 首先要 为 true
            if (!f[i][id(j)]) continue;
            // 分别讨论四种情况 进行状态转移
            if (s[i+1]=='W'){
                if (j+1==k && i+1!=n) continue;
                if (j==k || f[i+1][id(j+1)]) continue;
                f[i+1][id(j+1)] = 1;
                befo[i+1][id(j+1)] = j;
            } else if (s[i+1]=='L'){
                if (j-1 == -k && i+1!=n) continue;
                if (j==-k || f[i+1][id(j-1)]) continue;
                f[i+1][id(j-1)] = 1;
                befo[i+1][id(j-1)] = j;
            } else if (s[i+1]=='D'){
                if (abs(j) == k && i+1!=n) continue;
                if (f[i+1][id(j)]) continue;
                f[i+1][id(j)] = 1;
                befo[i+1][id(j)] = j;
            } else {
                // 注意只有最后一个 i 的 状态 可以到 k 或者 -k
                if (j < k && !f[i+1][id(j+1)]){  // 'W'
                    if (i+1 == n || j+1 != k){
                        f[i+1][id(j+1)] = 1;
                        befo[i+1][id(j+1)] = j;     
                    }
                }
                if (j > -k && !f[i+1][id(j-1)]){
                    if (i+1 == n || j-1 != -k){  // 'L'
                        f[i+1][id(j-1)] = 1;
                        befo[i+1][id(j-1)] = j;
                    }
                }
                if (!f[i+1][id(j)]){
                    if (i+1 == n || abs(j) != k){   // 'D'
                        f[i+1][id(j)] = 1;
                        befo[i+1][id(j)] = j;
                    }
                }
            }
        }
    }

    if (!f[n][id(k)] && !f[n][id(-k)]) return cout << "NO\n", void();
    int cur = f[n][id(k)] ? k : -k;
    int p = n;
    while (p > 0){
        if (s[p]=='?'){
            s[p] = befo[p][id(cur)] == cur ? 'D' : (befo[p][id(cur)] > cur ? 'L' : 'W');
        }
        cur = befo[p][id(cur)];
        p -= 1;
    }
    for (int i = 1; i <= n; ++ i) cout << s[i];
    cout << "\n";
}
 
