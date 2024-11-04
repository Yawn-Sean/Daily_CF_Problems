#include <bits/stdc++.h>

using namespace std;
const int N = 100'000;
long long y1[N];
long long y2[N];

int main() {
    int n;
    scanf("%d", &n);
    int x1, x2;
    scanf("%d%d", &x1, &x2);
    for (int i = 0, k, b; i < n; i++) {
        scanf("%d%d", &k, &b);
        y1[i] = 1LL * k * x1 + b;
        y2[i] = 1LL * k * x2 + b;
    }
    vector<int> indices(n, 0);
    iota(indices.begin(), indices.end(), 0);
    ranges::sort(indices, [&] (int a, int b) {
        return y1[a] < y1[b] || y1[a] == y1[b] && y2[a] < y2[b];
    });
    for (int i = 1; i < n; i++) {
        if (y2[indices[i - 1]] > y2[indices[i]]) {
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
    return 0;
}

