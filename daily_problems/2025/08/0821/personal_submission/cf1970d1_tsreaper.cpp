#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}

int n;

vector<string> vec;
unordered_map<int, pii> mp;

int gao(string &s) {
    unordered_set<string> st;
    for (int i = 0; i < s.size(); i++) {
        string t;
        for (int j = i; j < s.size(); j++) {
            t.push_back(s[j]);
            st.insert(t);
        }
    }
    return st.size();
}

bool check() {
    int sz = vec.size();
    unordered_map<int, pii> res;
    for (int i = 0; i < sz; i++) {
        string t = vec[i] + vec[sz - 1];
        int v = gao(t);
        if (mp.count(v) || res.count(v)) {
            vec.pop_back();
            return false;
        }
        res[v] = {i, sz - 1};
    }
    for (int i = 0; i + 1 < sz; i++) {
        string t = vec[sz - 1] + vec[i];
        int v = gao(t);
        if (mp.count(v) || res.count(v)) {
            vec.pop_back();
            return false;
        }
        res[v] = {sz - 1, i};
    }
    for (auto &p : res) mp[p.first] = p.second;
    return true;
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int tries = 0;
        do {
            string s;
            for (int j = 1; j <= 30 * n; j++) s.push_back(rnd(0, 1) ? 'O' : 'X');
            vec.push_back(s);
            tries++;
        } while (!check());
    }

    for (auto &s : vec) printf("%s\n", s.c_str());
    fflush(stdout);

    int q; scanf("%d", &q);
    while (q--) {
        int x; scanf("%d", &x);
        pii p = mp[x];
        printf("%d %d\n", p.first + 1, p.second + 1);
        fflush(stdout);
    }

    return 0;
}
