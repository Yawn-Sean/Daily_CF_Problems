#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n;
long long A[MAXN + 5];

vector<long long> calc(long long d) {
    long long R = A[1] + d * 2;
    vector<long long> ret = {A[1] + d};
    for (int i = 1; i <= n; i++) if (A[i] > R) {
        R = A[i] + d * 2;
        ret.push_back(A[i] + d);
    }
    return ret;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &A[i]), A[i] *= 2;
    sort(A + 1, A + n + 1);

    long long head = 0, tail = 2e9;
    while (head < tail) {
        long long mid = (head + tail) >> 1;
        auto vec = calc(mid);
        if (vec.size() <= 3) tail = mid;
        else head = mid + 1;
    }

    auto vec = calc(head);
    while (vec.size() < 3) vec.push_back(vec.back());
    printf("%.6f\n", head / 2.0);
    for (int i = 0; i < 3; i++) printf("%.6f%c", vec[i] / 2.0, "\n "[i < 2]);
    return 0;
}
