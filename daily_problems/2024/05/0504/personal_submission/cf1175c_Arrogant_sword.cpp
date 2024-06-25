
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

void solve(int _) 
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    int ans = 0, x = 0;
    for (int i = 1; i+k+1 <= n; i ++ ) {
        if (a[i+k+1] - a[i] > ans ) {
            ans = a[i+k+1] - a[i];
            x = (a[i+k+1] + a[i]) / 2;
        }
    }

    cout << x << endl;
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