
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
int n, k, l, m;

struct mtx {
    int c[4][4];
    mtx(){memset(c, 0, sizeof(c));}
}A, res;

mtx operator*(mtx &x, mtx &y) {
    mtx t;
    for (int i = 1; i <= 2; i ++ ) {
        for (int j = 1; j <= 2; j ++ ) {
            for (int k = 1; k <= 2; k ++ ) {
                t.c[i][j] = (t.c[i][j] + x.c[i][k] * y.c[k][j]) % m;
            }
        }
    }
    return t;
}

void mtx_qmi(int k) {
    A.c[1][1] = A.c[1][2] = A.c[2][1] = 1; A.c[2][2] = 0;
    res.c[1][1] = res.c[2][1] = 1;
    while (k) {
        if (k & 1) res = res * A;
        A = A * A;
        k >>= 1;
    }
}

int qmi(int a,int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return ans;
}

void solve(int _) 
{
    
    cin >> n >> k >> l >> m;
    mtx_qmi(n+1);
    int f0 = res.c[1][1], f1 = (qmi(2, n) - f0 + m) % m;
    int ans = 1 % m;
    for (int i = 0; i < l; i ++ ) {
        if ((k >> i) & 1) {
            ans = ans * f1 % m;
        } else {
            ans = ans * f0 % m;
        }
    }
    if (l <= 63 && k >> l) {
        ans = 0;
    }

    cout << ans << endl;

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