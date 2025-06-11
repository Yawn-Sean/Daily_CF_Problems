#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;
typedef pair<int, int> pii;

int n, A[MAXN + 10], B[MAXN + 10];
vector<pii> ans;

set<int> pos[MAXN + 10];

bool flag[MAXN + 10];
vector<int> prime;

void swp(int i, int j) {
    pos[A[i]].erase(i); pos[A[i]].insert(j);
    pos[A[j]].erase(j); pos[A[j]].insert(i);
    swap(A[i], A[j]);
}

int main() {
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) if (!flag[i]) {
        prime.push_back(i);
        for (int j = i * 2; j <= n; j += i) flag[j] = true;
    }

    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        B[i] = A[i];
        pos[A[i]].insert(i);
    }
    sort(B + 1, B + n + 1);
    for (int i = 1; i <= n; i++) if (A[i] != B[i]) {
        int j = *prev(pos[B[i]].end());
        while (i != j) {
            int dis = j - i + 1;
            int x = *prev(upper_bound(prime.begin(), prime.end(), dis));
            swp(j, j - x + 1);
            ans.push_back({j - x + 1, j});
            j = j - x + 1;
        }
    }
    printf("%d\n", ans.size());
    for (pii p : ans) printf("%d %d\n", p.first, p.second);
    return 0;
}
