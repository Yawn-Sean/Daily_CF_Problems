/**
 * Problem: A. Harry Potter and Three Spells
 * Contest: Codeforces Beta Round 60
 * OnlineJudge: Codeforces
 * @Author: Chizer
 * DateTime: 2025-06-02 23:22
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
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    if((!c && d) || (!a && b && d) || (b * d * f > a * c * e)) {
        cout << "Ron";
    } else cout << "Hermione";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    T = 1;
    //    cin >> T;
    while(T--) solve();
}
