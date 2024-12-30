
#include<bits/stdc++.h>
#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define pb push_back
#define PII pair<int,int>
#define SZ(a) ((int)a.size())
#define rep(i, n) for (int i = 1; i <= n; i ++)
#define rep0(i, n) for (int i = 0; i < n; i ++)

using namespace std;
void print(vector<int> vi, int st, int ed)
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
const int mod = 998244353;
void solve(int _) 
{
    int n;
    cin >> n;
    vector<int> pw2(n+1);
    pw2[0] = 1;
    rep(i, n) {
        pw2[i] = (pw2[i-1] * 2) % mod;
    }
    int ans = 0;
    int x;
    rep(i, n - 1) {
        cin >> x;
        ans = (ans + x * ((pw2[n - i] + (n - i) * pw2[n - i - 1]) % mod)) % mod;
    }
    cin >> x;
    ans = (ans + x) % mod;
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