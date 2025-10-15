#include <bits/stdc++.h>
#define MAXN 150000
using namespace std;
typedef pair<int, int> pii;

int n, bad, A[MAXN + 5];

int calc(int idx) {
    if (idx == n) return 0;
    if (idx & 1) {
        if (A[idx] < A[idx + 1]) return 0;
        else return 1;
    } else {
        if (A[idx] > A[idx + 1]) return 0;
        else return 1;
    }
}

bool gao(int x, int y) {
    unordered_set<int> tmp;
    tmp.insert(x);
    if (x - 1 > 0) tmp.insert(x - 1);
    tmp.insert(y);
    if (y - 1 > 0) tmp.insert(y - 1);

    int v = bad;
    for (int z : tmp) v -= calc(z);
    swap(A[x], A[y]);
    for (int z : tmp) v += calc(z);
    swap(A[x], A[y]);
    return v == 0;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    unordered_set<int> st;
    for (int i = 1; i <= n; i++) {
        int t = calc(i);
        bad += t;
        if (t) {
            st.insert(i);
            if (i + 1 <= n) st.insert(i + 1);
        }
    }
    if (st.size() > 10) { printf("0\n"); return 0; }

    vector<pii> vec;
    for (int x : st) for (int i = 1; i <= n; i++) if (i != x) {
        if (gao(i, x)) vec.push_back({min(i, x), max(i, x)});
    }
    sort(vec.begin(), vec.end());
    printf("%d\n", unique(vec.begin(), vec.end()) - vec.begin());
    return 0;
}
