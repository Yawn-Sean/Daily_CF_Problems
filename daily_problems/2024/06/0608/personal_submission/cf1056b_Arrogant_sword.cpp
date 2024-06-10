
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
    int n, mod;
    cin >> n >> mod;

    int g = n / mod;
    vector<int> cnt(mod, g);
    for (int i = 1; i <= n % mod; i ++ ) {
        cnt[i] ++;
    }
    vector<int> res(mod);
    for (int i = 0; i < mod; i ++ ) {
        res[(i * i) % mod] += cnt[i];
    }
    int ans = 0;
    for (int i = 1; i < mod; i ++ ) {
        ans += res[i] * res[mod - i];
    }
    ans += res[0] * res[0];

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