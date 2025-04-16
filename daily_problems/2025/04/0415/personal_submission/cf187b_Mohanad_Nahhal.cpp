/*
Mayoeba Yabureru
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
const ll INF = 1e18;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, m, r;
    cin >> n >> m >> r;

    vector<vector<vector<ll>>> dist(m, vector<vector<ll>>(n, vector<ll>(n)));
    for (int c = 0; c < m; c++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cin >> dist[c][i][j];
            }
        }
    }
 
    for (int c = 0; c < m; c++){
        for (int k = 0; k < n; k++){
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    if(dist[c][i][k] + dist[c][k][j] < dist[c][i][j])
                        dist[c][i][j] = dist[c][i][k] + dist[c][k][j];
                }
            }
        }
    }
 
    vector<vector<ll>> A(n, vector<ll>(n, INF));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            for (int c = 0; c < m; c++){
                A[i][j] = min(A[i][j], dist[c][i][j]);
            }
        }
    }
 
    int maxSeg = 1001; 
    vector<vector<vector<ll>>> dp(maxSeg+1, vector<vector<ll>>(n, vector<ll>(n, INF)));
    dp[1] = A;
 
    for (int L = 2; L <= maxSeg; L++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                ll best = INF;
         
                for (int k = 0; k < n; k++){
                    best = min(best, dp[L-1][i][k] + A[k][j]);
                }
                dp[L][i][j] = best;
            }
        }
    }
 
    for (int i = 0; i < r; i++){
        int s, t, k;
        cin >> s >> t >> k;
        s--; t--; 
        cout << dp[k+1][s][t] << "\n";
    }
 
    return 0;
}
