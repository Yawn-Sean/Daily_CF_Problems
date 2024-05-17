#include <bits/stdc++.h>
#define MAXPROD ((int) 1e5)
using namespace std;

int n, m, A[MAXPROD];
long long ans;

int B[MAXPROD];
long long f[MAXPROD];

int idx(int i, int j, int m) {
    return i * m + j;
}

void rev() {
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) B[idx(j, i, n)] = A[idx(i, j, m)];
    swap(n, m);
    for (int i = 0; i < n * m; i++) A[i] = B[i];
}

void calc() {
    for (int j = 0; j < m; j++) f[j] = A[j];
    for (int i = 1, t = m; i < n; i++) for (int j = 0; j < m; j++, t++)
        f[t] = A[t] + f[t - m];
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n * m; i++) scanf("%d", &A[i]);
    
    if (n > m) rev();
    calc();

    for (int i = 0; i < n; i++) for (int ii = i + 1; ii < n; ii++) {
        long long now = 0, mx1 = 0, mx2 = 0;
        for (int j = 0; j < m; j++) {
            int x = A[idx(i, j, m)] + A[idx(ii, j, m)];
            now += x;
            long long t = f[idx(n - 1, j, m)] - x;
            if (t > mx1) mx2 = mx1, mx1 = t;
            else if (t > mx2) mx2 = t;
        }
        ans = max(ans, now + mx1 + mx2);
    }

    for (int _ = 1; _ <= 2; _++) {
        rev(); calc();

        vector<long long> vec;
        for (int i = 0; i < n; i++) {
            long long t = 0;
            for (int j = 0; j < m; j++) t += A[idx(i, j, m)];
            vec.push_back(t);
        }
        sort(vec.begin(), vec.end(), greater<long long>());
        long long t = 0;
        for (int i = 0; i < 4 && i < n; i++) t += vec[i];
        ans = max(ans, t);

        for (int i = 0; i < n; i++) {
            vector<long long> vec;
            long long t = 0;
            for (int j = 0; j < m; j++) {
                t += A[idx(i, j, m)];
                vec.push_back(f[idx(n - 1, j, m)] - A[idx(i, j, m)]);
            }
            sort(vec.begin(), vec.end(), greater<long long>());
            for (int j = 0; j < 3 && j < m; j++) t += vec[j];
            ans = max(ans, t);
        }
    }

    printf("%lld\n", ans);
    return 0;
}
