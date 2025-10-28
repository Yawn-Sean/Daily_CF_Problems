#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;

int n, ans[MAXN + 5];

void gao(int l, int r, vector<int> &vec) {
    if (l == r) { ans[l] = vec[0]; return; }

    vector<int> vl, vr;
    for (int i = 0; i < vec.size(); i++) {
        if (i & 1) vr.push_back(vec[i]);
        else vl.push_back(vec[i]);
    }

    int mid = (l + r) >> 1;
    gao(l, mid, vl); gao(mid + 1, r, vr);
}

int main() {
    scanf("%d", &n);
    vector<int> vec;
    for (int i = 1; i <= n; i++) vec.push_back(i);
    gao(1, n, vec);
    for (int i = 1; i <= n; i++) printf("%d%c", ans[i], "\n "[i < n]);
    return 0;
}
