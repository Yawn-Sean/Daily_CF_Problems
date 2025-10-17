#include  <bits/stdc++.h>
#define MAXN 3000
using namespace std;
typedef pair<int, int> pii;

namespace fast {
    char B[1 << 18], *S = B,*T = B;
    #define getc() (S == T && (T = (S = B) + fread(B, 1, 1 << 18, stdin), S == T) ? 0 : *S++)
    long long read() {
        long long ret = 0; char c;
        while (c = getc(), (c < '0' || c > '9') && c != '-');
        bool neg = false;
        if (c == '-') neg = true, c = getc();
        for (; c >= '0' && c <= '9'; c = getc()) ret = ret * 10 + c - '0';
        return ret * (neg ? -1 : 1);
    }
}

int n, A[MAXN + 5][MAXN + 5];
long long ans;

int U[MAXN + 5][MAXN + 5], D[MAXN + 5][MAXN + 5], L[MAXN + 5][MAXN + 5], R[MAXN + 5][MAXN + 5];
int tree[MAXN + 5];

int lb(int x) { return x & (-x); }

void add(int pos, int val) {
    for (; pos <= n; pos += lb(pos)) tree[pos] += val;
}

int query(int pos) {
    int ret = 0;
    for (; pos; pos -= lb(pos)) ret += tree[pos];
    return ret;
}

void gao(int i, int j) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    int bias = 0;

    for (int d = 0; i + d <= n && j + d <= n; d++) {
        int ii = i + d, jj = j + d;
        int x = min(U[ii][jj], L[ii][jj]);
        if (x) {
            int y = min(D[ii][jj], R[ii][jj]);
            pq.push({y - bias, jj});
            add(jj, 1);
            ans += query(jj) - query(jj - x);
        }
        bias--;
        while (!pq.empty()) {
            pii p = pq.top();
            if (p.first + bias > 0) break;
            pq.pop();
            add(p.second, -1);
        }
    }

    while (!pq.empty()) add(pq.top().second, -1), pq.pop();
}

int main() {
    n = fast::read();
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) A[i][j] = fast::read();

    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
        if (A[i][j]) U[i][j] = U[i - 1][j] + 1, L[i][j] = L[i][j - 1] + 1;
        else U[i][j] = L[i][j] = 0;
    }
    for (int i = n; i > 0; i--) for (int j = n; j > 0; j--) {
        if (A[i][j]) D[i][j] = D[i + 1][j] + 1, R[i][j] = R[i][j + 1] + 1;
        else D[i][j] = R[i][j] = 0;
    }

    for (int i = 1; i <= n; i++) gao(i, 1);
    for (int j = 2; j <= n; j++) gao(1, j);
    printf("%lld\n", ans);
    return 0;
}
