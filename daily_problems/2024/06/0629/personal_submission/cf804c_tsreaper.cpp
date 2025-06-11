#include <bits/stdc++.h>
#define MAXN ((int) 3e5)
using namespace std;

namespace fast {
    char B[1 << 18], *S = B,*T = B;
    #define getc() (S == T && (T = (S = B) + fread(B, 1, 1 << 18, stdin), S == T) ? 0 : *S++)
    long long read() {
        long long ret = 0; char c;
        while (c = getc(), c < '0' || c > '9');
        for (; c >= '0' && c <= '9'; c = getc()) ret = ret * 10 + c - '0';
        return ret;
    }
}

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int n, m, K, ans[MAXN + 10];

vector<int> e[MAXN + 10], C[MAXN + 10];
unordered_set<int, custom_hash> st;

void dfs(int sn, int fa) {
    for (int x : C[sn]) if (ans[x]) st.erase(ans[x]);
    for (int x : C[sn]) if (ans[x] == 0) ans[x] = *(st.begin()), st.erase(st.begin());
    for (int x : C[sn]) st.insert(ans[x]);
    for (int fn : e[sn]) if (fn != fa) dfs(fn, sn);
}

int main() {
    n = fast::read(); m = fast::read();
    K = 1;
    for (int i = 1; i <= n; i++) {
        int t = fast::read();
        K = max(K, t);
        while (t--) {
            int x = fast::read();
            C[i].push_back(x);
        }
    }
    for (int i = 1; i < n; i++) {
        int x = fast::read(), y = fast::read();
        e[x].push_back(y); e[y].push_back(x);
    }

    for (int i = 1; i <= K; i++) st.insert(i);
    dfs(1, 0);
    printf("%d\n", K);
    for (int i = 1; i <= m; i++) printf("%d%c", ans[i] ? ans[i] : 1, "\n "[i < m]);
    return 0;
}
