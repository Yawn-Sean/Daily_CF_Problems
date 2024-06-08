
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
    int n, q;
    cin >> n >> q;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i ++ ) {
        cin >> a[i];
    }

    vector<int> nxt(n+1);
    vector<int> pos(N);
    for (int i = n; i >= 1; i -- ) {
        if (pos[a[i]]) {
            nxt[i] = pos[a[i]];
        } else {
            nxt[i] = i;
        }
        pos[a[i]] = i;
    }   

    int ans = 0;
    for (int l = 1; l <= n; ) {
        int r = l; map<int,int> cnt;
        int mx = 0, rr = nxt[r];
        while (r <= rr) {
            cnt[a[r]] ++;
            mx = max(mx, cnt[a[r]]);
            rr = max(rr, nxt[r]);
            r ++;
        }
        ans += r - l - mx;
        l = r;
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