
#include<bits/stdc++.h>
#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define pb push_back
#define PII pair<int,int>
#define x first
#define y second
#define SZ(a) ((int)a.size())
using namespace std;
void print(vector<int> vi)
{
    for (auto t : vi) cout << t << ' ';
    cout << endl;
}
//////////////////////////////////////////////////
const int N = 2e5 + 10;
const int inf = 1e14;
const int mod = 998244353;

void solve(int _) 
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    map<int, PII> mp;
    for (int i = 1; i <= n; i ++ ) {
        cin >> a[i];
        if (mp[a[i]].x == 0) mp[a[i]].x = mp[a[i]].y = i;
        else mp[a[i]].y = i;
    }
    int ans = -1;
    for (int i = 1; i <= n; i ++ ) {
        int l = mp[a[i]].x, r = mp[a[i]].y;
        if (l == r) {
            if (ans == -1) ans = 1;
            else ans = ans * 2 % mod;
            continue;
        } 

        int j = l;
        for (; j <= r; j ++ ) {
            r = max(r, mp[a[j]].y);
        }
        if (ans == -1) ans = 1;
        else ans = ans * 2 % mod;
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