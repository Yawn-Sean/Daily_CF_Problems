
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

void solve(int _) 
{
    int n;
    cin >> n;
    vector<int> a(n+1), pos(n+1);
    for (int i = 1; i <= n; i ++ ) {
        cin >> a[i];
        pos[a[i]] = i;
    }

    vector<int> dp(n+1, 2);
    for (int i = n; i >= 1; i -- ) {
        int u = pos[i];
        dp[u] = 0;
        
        for (int j = u % a[u] ; j <= n; j += a[u]) {
            if (a[u] > a[j] || u == j) {
                continue;
            }
            if (dp[j] == 0) {
                dp[u] = 1;
                break;
            }
        }
    }
    
    for (int i = 1; i <= n; i ++ ) {
        cout << (dp[i] ? 'A' : 'B');
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
    return 0;
}