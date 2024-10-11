#include <bits/stdc++.h>
#define MAXN ((int) 3e5)
#define INF ((int) 1e9)
using namespace std;
typedef pair<int, int> pii;

struct Magic {
    multiset<int> ms1, ms2;
    int K;

    Magic(int K): K(K) {}

    void adjust() {
        while (ms1.size() < K && !ms2.empty()) {
            ms1.insert(*prev(ms2.end()));
            ms2.erase(prev(ms2.end()));
        }
        while (ms1.size() > K) {
            ms2.insert(*(ms1.begin()));
            ms1.erase(ms1.begin());
        }
    }

    void insert(int x) {
        if (!ms1.empty() && x < *(ms1.begin())) ms2.insert(x);
        else ms1.insert(x);
        adjust();
    }

    void erase(int x) {
        auto it = ms1.find(x);
        if (it != ms1.end()) ms1.erase(it);
        else ms2.erase(ms2.find(x));
        adjust();
    }

    int query() {
        if (ms1.size() < K) return -INF;
        else return *(ms1.begin());
    }
};

int n, K;
array<int, 3> A[MAXN + 10];

int main() {
    scanf("%d%d", &n, &K);
    for (int i = 1; i <= n; i++) scanf("%d%d", &A[i][0], &A[i][1]), A[i][2] = i;

    sort(A + 1, A + n + 1);
    int ansL = 0, ansR = -1;
    Magic magic(K);
    for (int i = 1; i <= n; i++) {
        magic.insert(A[i][1]);
        int r = magic.query();
        if (ansR - ansL < r - A[i][0]) ansL = A[i][0], ansR = r;
    }

    int ans = ansR - ansL + 1;
    printf("%d\n", ans);
    if (ans == 0) {
        for (int i = 1; i <= K; i++) printf("%d%c", i, "\n "[i < K]);
        return 0;
    }
    for (int i = 1; i <= n && K > 0; i++) if (A[i][0] <= ansL && A[i][1] >= ansR) {
        printf("%d ", A[i][2]);
        K--;
    }
    printf("\n");
    return 0;
}
