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
const int inf = 1e9;
void solve(int _) 
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    if (n == 1) {
        cout << "YES" << endl;
        cout << inf << ' ' << 1 << endl;
        return;
    }

    int col = 1;
    for (int i = 2; i <= n; i ++ ) {
        int x = abs(a[i] - a[i-1]);
        if (x == 0) {
            cout << "NO" << endl;
            return;
        } else if (x != 1) {
            col = x;
        }
    }
    
    if (col == 1) {
        cout << "YES" << endl;
        cout << inf << ' ' << 1 << endl;
        return;
    }
    
    for (int i = 2; i <= n; i ++ ) {
        int x = abs(a[i] - a[i-1]);
        if (x == 1 && ((a[i] - 1) / col != (a[i-1] - 1) / col)) {
            cout << "NO" << endl;
            return;
        }
        if (x != 1 && x != col) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
    cout << inf << ' ' << col << endl;

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