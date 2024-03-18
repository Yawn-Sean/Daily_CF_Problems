// 注意数据范围，倒退模拟即可。
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
    int n, q, m;
    cin >> n >> q >> m;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    vector<array<int, 3>> op(q);
    for (int i = 0; i < q; i ++ ) {
        cin >> op[i][0] >> op[i][1] >> op[i][2];
    }

    for (int i = 0; i < m; i ++ ) {
        int pos;
        cin >> pos;
        
        for (int i = q-1; i >= 0; i -- ) {
            int t = op[i][0], l = op[i][1], r = op[i][2];
            if (t == 1) {
                if (pos == l) pos = r;
                else if (l < pos && pos <= r) pos --;
            } else {
                if (l <= pos && pos <= r) pos = l + r - pos;
            }
        }
        cout << a[pos] << ' ';
    }
} 

signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int T = 1;
    //cin >> T;
    while (T --) {
        solve();
    }
    
}