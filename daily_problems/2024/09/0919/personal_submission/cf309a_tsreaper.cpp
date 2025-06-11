#include <bits/stdc++.h>
#define MAXN ((int) 1e6)
using namespace std;

namespace fast {
    char B[1 << 18], *S = B,*T = B;
    #define getc() (S == T && (T = (S = B) + fread(B, 1, 1 << 18, stdin), S == T) ? 0 : *S++)
    long long read() {
        long long ret = 0; char c;
        while (c = getc(), c != '-' && (c < '0' || c > '9'));
        int k = 1;
        if (c == '-') k = -1, c = getc();
        for (; c >= '0' && c <= '9'; c = getc()) ret = ret * 10 + c - '0';
        return ret * k;
    }
}

int n;
long long L, T, A[MAXN];
double ans;

int main() {
    n = fast::read(); L = fast::read(); T = fast::read();
    for (int i = 0; i < n; i++) A[i] = fast::read();
    if (n == 1) { printf("0\n"); return 0; }

    long long r = (T * 2) / L, rem = (T * 2) % L;
    for (int i = 0; i < n; i++) {
        int head = 0, tail = n - 1;
        while (head < tail) {
            int mid = (head + tail + 1) >> 1;
            int d = (A[(i + mid) % n] - A[i] + L) % L;
            if (d <= rem) head = mid;
            else tail = mid - 1;
        }
        ans += ((n - 1) * r + head) / 4.0;

        head = 0; tail = n - 1;
        while (head < tail) {
            int mid = (head + tail + 1) >> 1;
            int d = (A[i] - A[(i - mid + n) % n] + L) % L;
            if (d <= rem) head = mid;
            else tail = mid - 1;
        }
        ans += ((n - 1) * r + head) / 4.0;
    }
    printf("%.12f\n", ans / 2);
    return 0;
}
