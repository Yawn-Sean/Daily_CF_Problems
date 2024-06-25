
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
const int mod = 1e9 + 7;

int qmi(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

void solve(int _) 
{
    int n, m, k, r, c;
    cin >> n >> m >> k >> r >> c;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    // 相当于没有影响
    if (x1 == x2 && y1 == y2) {
        cout << qmi(k, n * m) << endl;
    } else {
        // 一个矩阵内的颜色随便选，另一个矩形区域就固定了.
        //cout << n * m - r * c << endl;
        cout << qmi(k, n * m - r * c) << endl;
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