#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, K;
array<int, 3> A[MAXN + 10];

vector<int> check(int lim) {
    vector<int> ret;
    int sm = 0;
    for (int i = 1; i <= n; i++) if (A[i][1] >= lim) {
        sm += A[i][0];
        if (sm > K) break;
        ret.push_back(A[i][2]);
    }
    return ret;
}

int main() {
    scanf("%d%d", &n, &K);
    for (int i = 1; i <= n; i++) scanf("%d%d", &A[i][1], &A[i][0]), A[i][2] = i;
    sort(A + 1, A + n + 1);

    int head = 0, tail = n;
    while (head < tail) {
        int mid = (head + tail + 1) >> 1;
        if (check(mid).size() >= mid) head = mid;
        else tail = mid - 1;
    }

    printf("%d\n%d\n", head, head);
    vector<int> vec = check(head);
    for (int i = 0; i < head; i++) printf("%d%c", vec[i], "\n "[i + 1 < head]);
    return 0;
}
