#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define ve vector
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using pi = pair<int, int>;

const int mod = 1e9 + 7;
struct matrix {
    int64_t p[2][2];
};

matrix mul(matrix& a, matrix& b) {
    matrix res;
    rep(i, 0, 2) {
        rep(j, 0, 2) {
            res.p[i][j] = 0;
        }
    }

    rep(i, 0, 2) {
        rep(j, 0, 2) {
            rep(k, 0, 2) {
                //res.p[i][j] = (res.p[i][j] + a.p[i][k] * b.p[k][j]) % mod;
                res.p[i][k] = (res.p[i][k] + a.p[i][j] * b.p[j][k]) % mod;  //效率高
            }
        }
    }
    return res;
}

matrix ksm(matrix& a, int64_t k) {
    matrix res;
    rep(i, 0, 2) {
        rep(j, 0, 2) {
            res.p[i][j] = 0;
        }
    }
    rep(i, 0, 2) {
        res.p[i][i] = 1;
    }
    while (k > 0) {
        if (k % 2 == 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        k >>= 1;
    }
    return res;
}

void solve() {
    int a, b, x;
    int64_t n;
    cin >> a >> b >> n >> x;

    matrix B, C;

    B.p[0][0] = a;
    B.p[0][1] = b;
    B.p[1][0] = 0;
    B.p[1][1] = 1;
    C.p[0][0] = x;
    C.p[1][0] = 1;

    B = ksm(B, n);
    B = mul(B, C);
    cout << B.p[0][0] << '\n';
}
  
int main() {  
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {  
        solve();
    }  
    return 0;  
}

/*
https://codeforces.com/problemset/problem/678/D
*/