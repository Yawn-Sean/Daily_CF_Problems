/**
 * Problem: A. Karen and Game
 * Contest: Codeforces Round 419 (Div. 1)
 * OnlineJudge: Codeforces
 * @Author: Chizer
 * DateTime: 2025-06-05 16:54
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

void solve() {
    int n, m;
    cin >> n >> m;
    int arr[n + 1][m + 1];
    int row[2][n + 1], col[2][m + 1];
    memset(row, 0, sizeof row);
    memset(col, 0, sizeof col);
    int ans1 = 0;
    int ans2 = 0;
    rep(i, 1, n) {
        int minrow1 = inf;
        rep(j, 1, m) {
            cin >> arr[i][j];
            minrow1 = min(minrow1, arr[i][j]);
        }
        row[0][i] = minrow1;
        ans1 += minrow1;
    }
    rep(j, 1, m) {
        int lastcol = arr[1][j] - row[0][1];
        if(lastcol < 0) {
            cout << -1 << endl;
            return;
        }
        int mincol2 = inf;
        rep(i, 1, n) {
            mincol2 = min(mincol2, arr[i][j]);
            if(lastcol != arr[i][j] - row[0][i]) {
                cout << -1 << endl;
                return;
            }
        }
        col[0][j] = lastcol;
        ans1 += lastcol;
        col[1][j] = mincol2;
        ans2 += mincol2;
    }
    rep(i, 1, n) {
        int lastrow = arr[i][1] - col[1][1];
        if(lastrow < 0) {
            cout << -1 << endl;
            return;
        }
        rep(j, 1, m) {
            if(lastrow != arr[i][j] - col[1][j]) {
                cout << -1 << endl;
                return;
            }
        }
        row[1][i] = lastrow;
        ans2 += lastrow;
    }
    cout << min(ans1, ans2) << endl;
    int idx = ans1 <= ans2 ? 0 : 1;
    rep(i, 1, n) {
        rep(j, 1, row[idx][i]) {
            cout << "row " << i << endl;
        }
    }
    rep(i, 1, m) {
        rep(j, 1, col[idx][i]) {
            cout << "col " << i << endl;
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    T = 1;
    //    cin >> T;
    while(T--) solve();
}
