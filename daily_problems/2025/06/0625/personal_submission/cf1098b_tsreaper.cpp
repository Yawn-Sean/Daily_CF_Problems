#include <bits/stdc++.h>
#define MAXPROD ((int) 3e5)
using namespace std;

int n, m, best;
char s[MAXPROD + 5], ans[MAXPROD + 5], tmp[MAXPROD + 5];

void gao1(vector<char> &ord) {
    for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) tmp[i * m + j] = ord[i * 2 + j];
    for (int j = 2; j < m; j++) for (int i = 0; i < 2; i++) tmp[i * m + j] = tmp[i * m + j % 2];
    for (int i = 2; i < n; i++) {
        int cnt[2] = {0};
        for (int j = 0; j < m; j++) {
            if (s[i * m + j] != tmp[i % 2 * m + j % 2]) cnt[0]++;
            if (s[i * m + j] != tmp[i % 2 * m + 1 - j % 2]) cnt[1]++;
        }
        if (cnt[0] < cnt[1]) {
            for (int j = 0; j < m; j++) tmp[i * m + j] = tmp[i % 2 * m + j % 2];
        } else {
            for (int j = 0; j < m; j++) tmp[i * m + j] = tmp[i % 2 * m + 1 - j % 2];
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (s[i * m + j] != tmp[i * m + j]) cnt++;
    if (cnt < best) {
        best = cnt;
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) ans[i * m + j] = tmp[i * m + j];
    }
}

void gao2(vector<char> &ord) {
    for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) tmp[i * m + j] = ord[i * 2 + j];
    for (int i = 2; i < n; i++) for (int j = 0; j < 2; j++) tmp[i * m + j] = tmp[i % 2 * m + j];
    for (int j = 2; j < m; j++) {
        int cnt[2] = {0};
        for (int i = 0; i < n; i++) {
            if (s[i * m + j] != tmp[i % 2 * m + j % 2]) cnt[0]++;
            if (s[i * m + j] != tmp[(1 - i % 2) * m + j % 2]) cnt[1]++;
        }
        if (cnt[0] < cnt[1]) {
            for (int i = 0; i < n; i++) tmp[i * m + j] = tmp[i % 2 * m + j % 2];
        } else {
            for (int i = 0; i < n; i++) tmp[i * m + j] = tmp[(1 - i % 2) * m + j % 2];
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (s[i * m + j] != tmp[i * m + j]) cnt++;
    if (cnt < best) {
        best = cnt;
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) ans[i * m + j] = tmp[i * m + j];
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%s", s + i * m);

    best = n * m + 1;
    vector<char> ord = {'A', 'G', 'C', 'T'};
    for (int i = 0; i < 24; i++) {
        gao1(ord); gao2(ord);
        next_permutation(ord.begin(), ord.end());
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) printf("%c", ans[i * m + j]);
        printf("\n");
    }
    return 0;
}
