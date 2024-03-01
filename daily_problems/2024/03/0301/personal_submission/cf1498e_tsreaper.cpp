#include <bits/stdc++.h>
#define MAXN 500
using namespace std;

int n, A[MAXN + 10];

bool query(int x, int y) {
    if (A[x] < A[y]) printf("? %d %d\n", y, x);
    else printf("? %d %d\n", x, y);
    fflush(stdout);
    char s[10]; scanf("%s", s);
    return s[0] == 'Y';
}

void answer(int x, int y) {
    printf("! %d %d\n", x, y);
    fflush(stdout);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    vector<array<int, 3>> vec;
    for (int i = 1; i <= n; i++) for (int j = i + 1; j <= n; j++) vec.push_back({-abs(A[i] - A[j]), i, j});
    sort(vec.begin(), vec.end());
    for (auto &arr : vec) if (query(arr[1], arr[2])) {
        answer(arr[1], arr[2]);
        return 0;
    }
    answer(0, 0);
    return 0;
}
