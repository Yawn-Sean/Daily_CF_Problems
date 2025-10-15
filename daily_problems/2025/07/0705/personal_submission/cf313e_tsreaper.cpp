#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, m, A[2][MAXN + 5];

struct Bitset {
    const int W = 64;
    int len;
    typedef unsigned long long ull;
    vector<ull> vec;

    Bitset(int len): len(len) {
        vec.resize((len + W - 1) / W, 0);
    }

    void set(int pos) {
        vec[pos / W] |= 1ULL << (pos & (W - 1));
    }

    void unset(int pos) {
        vec[pos / W] &= ~(1ULL << (pos & (W - 1)));
    }

    void shift() {
        int b = vec[0] & 1;
        for (int i = 0; i < vec.size(); i++) {
            int t = vec[i] & 1;
            vec[i] >>= 1;
            if (t && i > 0) vec[i - 1] |= 1ULL << (W - 1);
        }
        if (b) vec[vec.size() - 1] |= 1ULL << ((len - 1) & (W - 1));
    }

    void join(Bitset &o) {
        assert(len == o.len);
        for (int i = 0; i < vec.size(); i++) vec[i] &= o.vec[i];
    }

    int findFirst(int bgn) {
        int bias = bgn & (W - 1);
        for (int i = bgn / W; i < vec.size(); i++) {
            ull x = vec[i] >> bias;
            x &= -x;
            if (x) return i * W + __lg(x) + bias;
            bias = 0;
        }
        return -1;
    }
};

int main() {
    scanf("%d%d", &n, &m);
    for (int k = 0; k < 2; k++) for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        A[k][x]++;
    }

    Bitset X(m), Y(m);
    for (int i = 0; i < m; i++) if (A[0][i]) X.set(i);
    for (int i = 0; i < m; i++) if (A[1][i]) Y.set(m - 1 - i);

    for (int v = m - 1; v >= 0; v--) {
        Bitset Z = X;
        Z.join(Y);
        int idx = 0;
        while (true) {
            idx = Z.findFirst(idx);
            if (idx < 0) break;
            int iidx = (v - idx + m) % m;
            int t = min(A[0][idx], A[1][iidx]);
            for (int i = 1; i <= t; i++) printf("%d ", v);
            if ((A[0][idx] -= t) == 0) X.unset(idx);
            if ((A[1][iidx] -= t) == 0) Y.unset(idx);
            idx++;
        }
        Y.shift();
    }
    printf("\n");
    return 0;
}
