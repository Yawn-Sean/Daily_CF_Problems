
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
    int n, d;
    cin >> n >> d;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i ++ ) {
        cin >> a[i];
    }

    int l = 0, r = 0, ans = 0;
    for (int i = 1; i <= n; i ++ ) {
        if (a[i] == 0) {
            l = max(0ll, l);
            if (r < 0) {
                ans ++;
                r = d;
            }
        } else {
            l += a[i];
            r += a[i];
            r = min(r, d);
            if (l > d) {
                cout << -1 << endl;
                return;
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