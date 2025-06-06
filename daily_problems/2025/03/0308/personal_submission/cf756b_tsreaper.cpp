#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, A[MAXN + 5];

int TIM[2] = {90, 1440}, COST[2] = {50, 120};
int f[MAXN + 5];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    deque<int> dq[2];
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 2; j++) while (!dq[j].empty() && A[i] - A[dq[j].front()] >= TIM[j]) dq[j].pop_front();
        for (int j = 0; j < 2; j++) {
            while (!dq[j].empty() && f[dq[j].back() - 1] >= f[i - 1]) dq[j].pop_back();
            dq[j].push_back(i);
        }
        f[i] = f[i - 1] + 20;
        for (int j = 0; j < 2; j++) if (!dq[j].empty()) f[i] = min(f[i], f[dq[j].front() - 1] + COST[j]);
    }

    for (int i = 1; i <= n; i++) printf("%d\n", f[i] - f[i - 1]);
    return 0;
}
