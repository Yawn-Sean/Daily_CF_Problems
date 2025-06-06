/**
 * Problem: E. Comments
 * Contest: Codeforces Round 387 (Div. 2)
 * OnlineJudge: Codeforces
 * @Author: Chizer
 * DateTime: 2025-05-29 17:24
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
#define maxn 300005
using namespace std;

int T;
vector<pair<string, int>> v;
vector<string> g[maxn];
int depth;

int getnum(string tmp) {
    int num = 0;
    int n = (int)tmp.size();
    rep(i, 0, n - 1) {
        num *= 10;
        num += tmp[i] - '0';
    }
    return num;
}

void split(string s) {
    int n = (int)s.size();
    string tmp;
    int idx = 0;
    int f = 0;
    string str;
    int num;
    while(idx < n) {
        if(s[idx] == ',') {
            if(f) {
                num = getnum(tmp);
                v.pb({ str, num });
            } else str = tmp;
            tmp = "";
            f = f ^ 1;
        } else tmp += s[idx];
        idx++;
    }
    num = getnum(tmp);
    v.pb({ str, num });
}
int idx;

void dfs(int now, int d) {
    if(idx > (int)v.size()) return;
    depth = max(depth, d);
    string ns = v[now].first;
    int num = v[now].second;
    g[d].pb(ns);
    int tmp = 0;
    while(tmp < num) {
        dfs(++idx, d + 1);
        tmp++;
    }
}

void solve() {
    string s;
    cin >> s;
    split(s);
    int n = v.size();
    vector<int> st;
    while(idx < n) {
        st.pb(idx);
        dfs(idx, 0);
        idx++;
    }
    cout << depth + 1 << endl;
    rep(i, 0, depth) {
        for(const string& x : g[i]) {
            cout << x << ' ';
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
