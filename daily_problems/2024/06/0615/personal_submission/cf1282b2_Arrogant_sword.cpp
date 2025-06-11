
#include<bits/stdc++.h>
#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define pb push_back
#define PII pair<int,int>
#define SZ(a) ((in  t)a.size())
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
    int n, p, k;
    cin >> n >> p >> k;
    vector<int> dp(n+1);
    for (int i = 1; i <= n; i ++ ) {
        cin >> dp[i];
    }

    sort(dp.begin() + 1, dp.end());
    for (int i = 1; i < k; i ++ ) {
        dp[i] += dp[i-1];
    }
    for (int i = k; i <= n; i ++ ) {
        dp[i] += dp[i-k];
    }

    for (int i = n; i >= 0; i -- ) {
        if (dp[i] <= p) {
            cout << i << endl;
            return;
        }
    }
} 

signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int T = 1;
    cin >> T;
    for (int _ = 1; _ <= T; _ ++ ) {
        solve(_);
    }
    return 0;
}