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
    vector<int> a(n+1);
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    vector<int> ans(n+1);
    ans[1] = 1; ans[n] = 1;
    for (int i = 2; i < n; i ++ ) {
        ans[i] = min(a[i], ans[i-1] + 1);
    }
    for (int i = n-1; i > 1; i -- ) {
        ans[i] = min(ans[i], ans[i+1] + 1);
    }

    cout << *max_element(all(ans)) << endl;
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
