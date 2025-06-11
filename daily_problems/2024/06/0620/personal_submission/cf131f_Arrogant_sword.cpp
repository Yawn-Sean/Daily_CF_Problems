
#include<bits/stdc++.h>
#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define pb push_back
#define PII pair<int,int>
#define SZ(a) ((int)a.size())
using namespace std;
void print(int *vi, int st, int ed)
{
    for (int i = st; i <= ed; i ++ ) cout << vi[i] << ' ';
    cout << endl;
}

void print(vector<int>& vi) {
    for (auto t: vi) {
        cout << t << ' ';
    }
    cout << endl;
}

//////////////////////////////////////////////////
const int N = 2e5 + 10;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
void solve(int _) 
{
    int n, m, k;
    cin >> n >> m >> k;
    string g[n];
    for (int i = 0; i < n; i ++ ) {
        cin >> g[i];
    }

    vector w(n, vector<int>(m));
    for (int i = 1; i < n-1; i ++ ) {
        for (int j = 1; j < m-1; j ++ ) {
            if (g[i][j] == '1') {
                w[i][j] = 1;
                for (int k = 0; k < 4; k ++ ) {
                    if (g[i+dx[k]][j+dy[k]] == '0') {
                        w[i][j] = 0;
                        break;
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int down = 0; down < n - 2; down ++ ) {
        vector<int> tmp(m);
        for (int up = down + 2; up < n; up ++ ) {
            for (int j = 0; j < m; j ++ ) {
                tmp[j] += w[up - 1][j];
            }
            int r = 1, cur = 0;
            for (int l = 1; l < m - 1; l ++ ) {
                while (r < m - 1 && cur < k) {
                    cur += tmp[r];
                    r ++;
                }
                if (cur < k) {
                    break;
                }
                ans += m - r;
                cur -= tmp[l];
            }
        }   
    }

    cout << ans << endl;
} 


signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int T = 1;
    //cin >> T;
    for (int _ = 1; _ <= T; _ ++ ) {
        solve(_);
    }
    return 0;
}