/**
 * Problem: C. Cardiogram
 * Contest: Codeforces Round 249 (Div. 2)
 * OnlineJudge: Codeforces
 * @Author: Chizer
 * DateTime: 2025-06-01 17:01
 * 适度编程益脑，沉迷编程伤身，合理安排时间，享受快乐生活。
 */
#include "bits/stdc++.h"
#define rep(i, j, k) for(int i = (j); i <= (k); ++i)
#define dep(i, j, k) for(int i = (j); i >= (k); --i)
using i64 = int64_t;
using f64 = double_t;
#define pb push_back
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define ull unsigned long long
#define mod 1000000007
#define inf 0x3f3f3f3f
#define maxn 100005
using namespace std;

int T;
int a[maxn];

void solve() {
    int n;
    cin >> n;
    int mx = 0, mi = 0;
    int sum = 0;
    int stand = 0;
    int f = 1;
    rep(i, 1, n) {
        cin >> a[i];
        if(f) stand += a[i];
        else stand -= a[i];
        f = f ^ 1;
        mx = max(mx, stand);
        mi = min(mi, stand);
        sum += a[i];
    }
    //    cout << mx << ' ' << mi << endl;
    int nowi = abs(mi), nowj = 0;
    int hei = mx - mi;
    char c[hei][sum + 1];
    memset(c, ' ', sizeof c);
    f = 1;
    rep(i, 1, n) {
        int tmp = a[i];
        while(tmp) {
            if(f) {
                c[nowi][nowj++] = '/';
                if(tmp > 1) nowi++;
            } else {
                c[nowi][nowj++] = '\\';
                if(tmp > 1) nowi--;
            }
            tmp--;
        }
        f = f ^ 1;
    }
    dep(i, hei - 1, 0) {
        rep(j, 0, sum - 1) {
            cout << c[i][j];
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    T = 1;
    //    cin >> T;
    while(T--) solve();
}
