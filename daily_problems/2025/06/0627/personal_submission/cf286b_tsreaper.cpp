#include <bits/stdc++.h>
#define MAXN ((int) 1e6)
using namespace std;
typedef pair<int, int> pii;

int n, bias, A[MAXN * 2 + 5];

int query(int pos) {
    return A[pos + bias];
}

void modify(int pos, int val) {
    A[pos + bias] = val;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) A[i] = i;
    for (int i = 2; i <= n; i++) {
        vector<pii> vec;
        for (int j = 1; j <= n; j += i) vec.push_back({min(j + i - 1, n), query(j)});
        bias++;
        for (pii p : vec) modify(p.first, p.second);
    }
    for (int i = 1; i <= n; i++) printf("%d%c", query(i), "\n "[i < n]);
    return 0;
}
