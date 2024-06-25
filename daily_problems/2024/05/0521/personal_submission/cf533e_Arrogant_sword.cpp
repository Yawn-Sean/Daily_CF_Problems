
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
    int l = 0, r = n-1;
    while (l < r && a[l] == b[l]) l ++;
    while (r > l && a[r] == b[r]) r --;

    if (l == r) {
        cout << 2 << endl;
        return;
    }

    string c = a.substr(l, r - l + 1), d = b.substr(l, r - l + 1);
    cout << (c.substr(0, r - l) == d.substr(1, r - l)) + (c.substr(1, r - l) == d.substr(0, r - l)) << endl;
} 

signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int T = 1;
   // cin >> T;
    for (int _ = 1; _ <= T; _ ++ ) {
        solve(_);
    }
    return 0;
}