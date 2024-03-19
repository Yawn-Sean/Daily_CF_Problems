
#include<bits/stdc++.h>
#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define pb push_back
#define PII pair<int,int>
#define x first
#define y second
using namespace std;
void print(vector<int> vi)
{
    for (auto t : vi) cout << t << ' ';
    cout << endl;
}
//////////////////////////////////////////////////

void solve() 
{
    int x, y, p, q;
    cin >> x >> y >> p >> q;
    if (p == 0) {
        if (x == 0) cout << 0 << endl;
        else cout << -1 << endl;
        return;
    }

    if (p == q) {
        if (x == y) cout << 0 << endl;
        else cout << -1 << endl;
        return;
    }

    int l = 1, r = 1e9+1;
    while (l < r) {
        int mid = l + r >> 1;

        if (x + mid * q - y >= p * mid && x <= p * mid) r = mid;
        else l = mid + 1;
    }
    cout << r * q - y << endl;
} 

signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int T = 1;
    cin >> T;
    while (T --) {
        solve();
    }
    
}