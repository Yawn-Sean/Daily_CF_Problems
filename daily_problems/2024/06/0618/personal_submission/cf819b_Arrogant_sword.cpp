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
    int n;
    cin >> n;
    vector<int> a(n+1), b(n*3+1);
    for (int i = 1; i <= n; i ++ ) {
        cin >> a[i];
    }
    int fcnt = 0, ftol = 0, zcnt = 0, ztol = 0;
    for (int i = 1; i <= n; i ++ ) {
        if (a[i] <= i) {
            fcnt ++; ftol += (i - a[i]);
        } else {
            zcnt ++; ztol += (a[i] - i);
            b[a[i] - i] ++;
        }
    }

    
    int ans = ftol + ztol, res = 0;
    for (int i = 1; i < n; i ++ ) {
        ztol -= zcnt; ftol += fcnt;
        zcnt -= b[i]; fcnt += b[i];
        int x = a[n-i+1];
        ftol -= n+1-x; fcnt --;
        if (x > 1) {
            b[x-1+i] ++; ztol += x - 1; ++zcnt;
        } else {
            fcnt ++;
        }

        if (ans > ftol + ztol) {
            ans = ftol + ztol;
            res = i;
        }
    }

    cout << ans << ' ' << res << endl;
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