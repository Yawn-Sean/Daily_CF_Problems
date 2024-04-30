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
void solve(int _) 
{
    int n;
    cin >> n;
    map<int,int> mp;
    vector<int> a(n);
    int mn = n+1;
    for (int i = 0, x; i < n; i ++ ) {
        cin >> x;
        a[i] = x;
        mp[x] ++;
    }
    for (auto [x, cnt]: mp) {
        mn = min(mn, cnt);
    }

    int ans = n;
    for (int k = 1; k <= mn+1; k ++ ) {
        int res = 0;
        bool ok = true;
        for (auto [xx, m]: mp) {
            int x = (m - 1) / k + 1;
            if ((k - 1) * x > m) {
                ok = false;
                break;
            }
            res += x;
        }
        if (ok) {
            ans = min(ans, res);
        }
    }

    cout << ans << endl;
    
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
