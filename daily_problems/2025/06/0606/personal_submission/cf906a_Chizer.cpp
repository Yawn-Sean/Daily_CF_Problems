/**
 * Problem: A. Shockers
 * Contest: Codeforces Round 454 (Div. 1, based on Technocup 2018 Elimination Round 4)
 * OnlineJudge: Codeforces
 * @Author: Chizer
 * DateTime: 2025-06-06 22:07
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
    int n;
    cin >> n;
    vector<char> a, last, res;
    rep(i, 0, 25) {
        last.pb('a' + i);
    }
    int f = 0;
    int ans = 0;
    rep(i, 1, n) {
        char op;
        string s;
        cin >> op >> s;
        for(char c : s) a.pb(c);
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        if(last.size() == 1) f = 1;
        if(op == '.') {
            set_difference(last.begin(), last.end(), a.begin(), a.end(), back_inserter(res));
            last = res;
        } else if(op == '!') {
            set_intersection(a.begin(), a.end(), last.begin(), last.end(), back_inserter(res));
            last = res;
            if(f) ans++;
        } else if(op == '?') {
            auto it = std::find(last.begin(), last.end(), s[0]);
            if(it != last.end()) {
                last.erase(it);
            }
            if(f) ans++;
        }
        a.clear();
        res.clear();
    }
    cout << (ans > 0 ? ans - 1 : 0) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    T = 1;
    //    cin >> T;
    while(T--) solve();
}
