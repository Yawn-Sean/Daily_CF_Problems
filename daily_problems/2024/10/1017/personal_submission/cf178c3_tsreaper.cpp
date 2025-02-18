#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;
typedef pair<int, int> pii;

int n, m, q, A[MAXN];
long long ans;

set<int> st[MAXN];

char B[1 << 18], *S = B,*T = B;
#define getc() (S == T && (T = (S = B) + fread(B, 1, 1 << 18, stdin), S == T) ? 0 : *S++)
long long read() {
    long long ret = 0; char c;
    while (c = getc(), c < '0' || c > '9');
    for (; c >= '0' && c <= '9'; c = getc()) ret = ret * 10 + c - '0';
    return ret;
}

int main() {
    n = read(); m = read(); q = read();

    int g = gcd(n, m);
    for (int i = 0; i < g; i++) for (int j = i, cnt = 0; cnt < n / g; j = (j + m) % n, cnt++) A[j] = cnt;
    for (int i = 0; i < g; i++) for (int j = 0; j < n / g; j++) st[i].insert(j);

    unordered_map<int, pii> mp;
    while (q--) {
        char op = ' ';
        while (op != '+' && op != '-') op = getc();
        int x = read();
        if (op == '+') {
            int y = read();
            int t = y % g;
            auto it = st[t].lower_bound(A[y]);
            if (it == st[t].end()) it = st[t].begin();
            ans += (*it - A[y] + n / g) % (n / g);
            mp[x] = {t, *it};
            st[t].erase(it);
        } else {
            pii p = mp[x];
            st[p.first].insert(p.second);
        }
    }
    printf("%lld\n", ans);
    return 0;
}
