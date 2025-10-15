#include <bits/stdc++.h>
#define MAXK ((int) 1e6)
using namespace std;

int n, K, A[MAXK];

void gao(int x, int y) {
    if (x < y) {
        A[0]++; A[K - y + 1]--;
        A[K - x + 1]++;
    } else {
        A[K - x + 1]++; A[K - y + 1]--;
    }
}

int main() {
    scanf("%d%d", &n, &K);

    vector<int> vec[2];
    int need = 0;
    for (int i = 1; i <= n; i++) {
        int l; scanf("%d", &l);
        for (int j = 1; j <= l; j++) {
            int x; scanf("%d", &x);
            vec[0].push_back(x);
        }

        int sz0 = vec[0].size(), sz1 = vec[1].size();
        bool flag = true;
        for (int j = 0; j < sz0 && j < sz1; j++) if (vec[0][j] != vec[1][j]) {
            gao(vec[1][j], vec[0][j]);
            flag = false;
            break;
        }

        if (flag) {
            if (sz0 < sz1) { printf("-1\n"); return 0; }
        } else {
            need++;
        }

        swap(vec[0], vec[1]);
        vec[0].clear();
    }

    for (int i = 0; i < K; i++) {
        if (i > 0) A[i] += A[i - 1];
        if (A[i] == need) { printf("%d\n", i); return 0; }
    }
    printf("-1\n"); return 0;
}
