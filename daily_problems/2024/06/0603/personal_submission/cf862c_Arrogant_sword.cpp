
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
    int n, x;
    cin >> n >> x;
    if (n == 1) {
        cout << "YES" << endl;
        cout << x << endl;
        return;
    } else if (n == 2) {
        if (x) {
            cout << "YES" << endl;
            cout << 0 << ' ' << x << endl;
        } else {
            cout << "NO" << endl;
        }
        return;
    }
    int now = 0;
    cout << "YES" << endl;
    for (int i = 1; i <= n - 3; i ++ ) {
        cout << i << ' ';
        now ^= i;
    }
    int u = (1 << 18);
    if (now != x) {
        cout << 0 << ' ' << u << ' ' << (now ^ u ^ x) << endl;
    } else {
        cout << u << ' ' << u / 2 << ' ' << ((u / 2)  ^ u) << endl; 
    }
    
    
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