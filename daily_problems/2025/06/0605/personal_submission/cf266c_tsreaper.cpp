#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;
typedef pair<int, int> pii;

int n, R[MAXN], A[MAXN][MAXN];
vector<array<int, 3>> ans;

int B[MAXN][MAXN], P[MAXN];

void gao(vector<pii> &vec, int op) {
    for (int i = 0; i < n; i++) P[i] = i;
    for (int i = 0; i < n; i++) if (P[i] != vec[i].second) {
        for (int j = i + 1; j < n; j++) if (P[j] == vec[i].second) {
            ans.push_back({op, i, j});
            swap(P[i], P[j]);
            break;
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int r, c; scanf("%d%d", &r, &c);
        r--; c--;
        R[r]++;
        A[r][c] = 1;
    }
    
    vector<pii> vec;
    for (int i = 0; i < n; i++) vec.push_back({R[i], i});
    sort(vec.begin(), vec.end());
    gao(vec, 1);
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) B[i][j] = A[vec[i].second][j];

    vec.clear();
    for (int j = 0; j < n; j++) {
        int t = n;
        for (int i = 0; i < n; i++) if (B[i][j]) { t = i; break; }
        vec.push_back({t, j});
    }
    sort(vec.begin(), vec.end());
    gao(vec, 2);

    printf("%d\n", ans.size());
    for (auto &arr : ans) printf("%d %d %d\n", arr[0], arr[1] + 1, arr[2] + 1);
    return 0;
}
