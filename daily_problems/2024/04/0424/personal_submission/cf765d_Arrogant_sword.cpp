#include<bits/stdc++.h>
#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define pb push_back
#define PII pair<int,int>
#define x first
#define y second
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
    int n;
    cin >> n;
    int tol = 0;
    vector<int> g(n+1), h(n+1), f(n+1);
    for (int i = 1, x; i <= n; i ++ ) {
        cin >> x;
        if (!g[x]) {
            g[x] = ++tol;
            h[tol] = x;
            g[i] = tol;
        } else {
            if (h[g[x]] == x) {
                g[i] = g[x];
            } else {
                cout << -1 << endl;
                return;
            }
        }
    }
    cout << tol << endl;
    for (int i = 1; i <= n; i ++) {
        cout << g[i] << ' ';
    }
    cout << endl;
    for (int i = 1; i <= tol; i ++ ) {
        cout << h[i] << ' ';
    }
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
    
}
