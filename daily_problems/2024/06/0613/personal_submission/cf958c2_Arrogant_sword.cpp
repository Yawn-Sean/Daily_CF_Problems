
#include<bits/stdc++.h>
#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define pb push_back
#define PII pair<int,int>
#define SZ(a) ((int)a.size())
using namespace std;
void print(vector<int> vi)
{
    for (auto t : vi) cout << t << ' ';
    cout << endl;
}
//////////////////////////////////////////////////
const int N = 2e5 + 10;

void solve(int _) 
{
    int n, k, p;
    cin >> n >> k >> p;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i ++ ) {
        cin >> a[i];
        a[i] = (a[i] + a[i-1]) % p;
    }

    vector f(k+1, vector<int>(n+1, -1e9));
    vector<int> t(p);
    for (int i = 1; i <= k; i ++ ) {
        for (int j = 0; j < p; j ++ ) {
            t[j] = -1e9;
        } 
        if (i == 1) t[0] = 0;
        for (int j = 1; j <= n; j ++ ) {
            for (int x = 0; x < p; x ++ ) {
                f[i][j] = max(f[i][j], t[x] + (a[j] - x + p) % p);
            }
            t[a[j]] = max(t[a[j]], f[i-1][j]);
        }
    }

    cout << f[k][n] << endl;
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