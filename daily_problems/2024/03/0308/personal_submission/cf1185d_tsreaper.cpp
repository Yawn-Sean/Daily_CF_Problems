#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;
typedef pair<int, int> pii;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int n;
pii A[MAXN + 10];

long long f[MAXN + 10];

bool checkFirst() {
    for (int i = n - 1; i - 1 > 1; i--) if (f[i] != f[i - 1]) return false;
    return true;
}

bool checkLast() {
    for (int i = 1; i + 1 < n - 1; i++) if (f[i] != f[i + 1]) return false;
    return true;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i].first), A[i].second = i;
    sort(A + 1, A + n + 1);

    if (n <= 3) {
        printf("1\n");
        return 0;
    }

    for (int i = 1; i < n; i++) f[i] = A[i + 1].first - A[i].first;
    if (checkFirst()) { printf("%d\n", A[1].second); return 0; }
    if (checkLast()) { printf("%d\n", A[n].second); return 0; }

    unordered_map<long long, int, custom_hash> L, R;
    for (int i = 3; i < n; i++) R[f[i]]++;
    for (int i = 2; i < n; i++) {
        long long sm = f[i - 1] + f[i];
        bool ok = false;
        if (L.empty() && R.empty()) ok = true;
        else if (L.empty()) { if (R.size() == 1 && sm == R.begin()->first) ok = true; }
        else if (R.empty()) { if (L.size() == 1 && sm == L.begin()->first) ok = true; }
        else {if (L.size() == 1 && R.size() == 1 && L.begin()->first == R.begin()->first && sm == L.begin()->first) ok = true; }
        if (ok) { printf("%d\n", A[i].second); return 0; }

        L[f[i - 1]]++;
        if (i + 1 < n) {
            int x = --R[f[i + 1]];
            if (x == 0) R.erase(f[i + 1]);
        }
    }
    printf("-1\n");
    return 0;
}
