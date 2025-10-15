#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, A[MAXN + 5];
bool flag[MAXN + 5];

int main() {
    scanf("%d", &n);
    int zero = 0, neg = 0, mx = -2e9, pos = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        if (A[i] == 0) zero++;
        else if (A[i] < 0) {
            neg++;
            if (A[i] > mx) mx = A[i], pos = i;
        }
    }

    if (neg <= 1 && neg + zero == n) {
        for (int i = 1; i < n; i++) printf("1 %d %d\n", i, i + 1);
        return 0;
    } else if (zero > 0) {
        vector<int> vec;
        for (int i = 1; i <= n; i++) if (A[i] == 0) flag[i] = true, vec.push_back(i);
        for (int i = 0; i + 1 < vec.size(); i++) printf("1 %d %d\n", vec[i], vec[i + 1]);
        if (neg % 2 == 1) flag[pos] = true, printf("1 %d %d\n", pos, vec.back());
        printf("2 %d\n", vec.back());
    } else if (zero == 0 && neg % 2 == 1) {
        flag[pos] = true;
        printf("2 %d\n", pos);
    }

    vector<int> vec;
    for (int i = 1; i <= n; i++) if (!flag[i]) vec.push_back(i);
    for (int i = 0; i + 1 < vec.size(); i++) printf("1 %d %d\n", vec[i], vec[i + 1]);
    return 0;
}
