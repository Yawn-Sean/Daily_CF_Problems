#include <bits/stdc++.h>
#define LIM 9
using namespace std;

struct S {
    string sl, sr;
    unordered_set<int> st[LIM + 1];
};

void gao(string &s, int len, unordered_set<int> &st) {
    if (len > s.size()) return;
    int msk = 0;
    for (int i = 0; i < len; i++) msk = msk * 2 + s[i] - '0';
    st.insert(msk);
    for (int i = len; i < s.size(); i++) {
        msk = msk * 2 % (1 << len) + s[i] - '0';
        st.insert(msk);
    }
}

S gao(string &s) {
    S ret;
    if (s.size() <= LIM) ret.sl = ret.sr = s;
    else ret.sl = s.substr(0, LIM), ret.sr = s.substr(s.size() - LIM, LIM);
    for (int len = 1; len <= LIM; len++) gao(s, len, ret.st[len]);
    return ret;
};

S merge(S &x, S &y) {
    S ret;
    for (int len = 1; len <= LIM; len++) {
        for (int t : x.st[len]) ret.st[len].insert(t);
        for (int t : y.st[len]) ret.st[len].insert(t);
    }

    string mid = x.sr + y.sl;
    for (int len = 2; len <= LIM; len++) gao(mid, len, ret.st[len]);

    if (x.sl.size() < LIM && y.sl.size() < LIM) {
        int len = min((int) mid.size(), LIM);
        ret.sl = mid.substr(0, len);
        ret.sr = mid.substr(mid.size() - len, len);
    } else if (x.sl.size() < LIM) {
        ret.sl = mid.substr(0, LIM);
        ret.sr = y.sr;
    } else if (y.sl.size() < LIM) {
        ret.sl = x.sl;
        ret.sr = mid.substr(mid.size() - LIM, LIM);
    } else {
        ret.sl = x.sl;
        ret.sr = y.sr;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<S> vec;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        vec.push_back(gao(s));
    }

    int q; cin >> q;
    while (q--) {
        int a, b; cin >> a >> b;
        S res = merge(vec[a - 1], vec[b - 1]);
        for (int i = LIM; i >= 0; i--) if (i == 0 || res.st[i].size() == (1 << i)) { printf("%d\n", i); break; }
        vec.push_back(res);
    }
    return 0;
}
