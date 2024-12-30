
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
    string a, b;
    cin >> a >> b;

    int ca = 0, cb = 0; 
    for (int i = 0; i < n; i ++ ) {
        ca += (a[i] == '1');
        cb += (b[i] == '1');
    }

    int ans = n+10;
    if (ca == cb) {
        int res = 0;
        for (int i = 0; i < n; i ++ ) {
            res += (a[i] != b[i]);
        }
        ans = min(ans, res);
    }
    if (n - ca + 1 == cb) {
        int res = 0;
        for (int i = 0; i < n; i ++ ) {
            res += (a[i] == b[i]);
        }
        ans = min(ans, res);
    }

    cout << (ans > n ? -1 : ans) << endl;
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