#include <bits/stdc++.h>

using namespace std;
constexpr int N = 2e5;
int a[N], b[N];

int main() {
    int n, m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }
    sort(a, a + n);
    sort(b, b + m);
    tuple<int, int, int> ans = max(tuple<int, int, int>{ n * 3 - m * 3, n * 3, m * 3 }, 
                                    tuple<int, int, int>{ n * 2 - m * 2, n * 2, m * 2 });
    int i = 0, j = 0;
    do {
        if (a[i] < b[j]) {
            i += 1;
        } else if (a[i] > b[j]) {
            j += 1;
        } else {
            int x = a[i];
            while (i < n && a[i] == x) i += 1;
            while (j < m && b[j] == x) j += 1;
        }
        int amx = i * 2 + (n - i) * 3;
        int bmx = j * 2 + (m - j) * 3;
        ans = max(ans, tuple<int, int, int> {amx - bmx, amx, bmx});
    } while (i < n && j < m);
    printf("%d:%d\n", get<1>(ans), get<2>(ans));
    return 0;
}

