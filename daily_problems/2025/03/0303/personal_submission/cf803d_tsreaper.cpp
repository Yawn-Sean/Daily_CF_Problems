#include <bits/stdc++.h>
#define MAXN ((int) 1e6)
using namespace std;

int n, K;
char s[MAXN + 5];

vector<int> vec;

int calc(int lim) {
    int ret = 1, now = 0;
    for (int x : vec) {
        if (x > lim) return K + 1;
        if (now + x > lim) ret++, now = x;
        else now += x;
    }
    return ret;
}

int main() {
    scanf("%d\n%[^\n]", &K, s + 1); n = strlen(s + 1);

    for (int i = 1, j = 1; ; i++) {
        if (i == n) {
            vec.push_back(i - j + 1);
            break;
        } else if (s[i] == ' ' || s[i] == '-') {
            vec.push_back(i - j + 1);
            j = i + 1;
        }
    }

    int head = 1, tail = n;
    while (head < tail) {
        int mid = (head + tail) >> 1;
        if (calc(mid) <= K) tail = mid;
        else head = mid + 1;
    }
    printf("%d\n", head);
    return 0;
}
