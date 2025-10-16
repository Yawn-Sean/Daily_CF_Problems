#include <bits/stdc++.h>

using namespace std;
constexpr int MX = 1'000'000'000;
constexpr int N = 45'000;

int main() {
    map<int, int> mp;
    mp[1] = 1;
    for (int i = N; i > 2; i--) {
        long long v = 1;
        for (int j = i; j > 1; j--) {
            v = v * j / (i - j + 1);
            if (v > MX) break;
            mp[v] = i + 1;
        }
    }
    int Q;
    scanf("%d", &Q);
    while (Q--) {
        int x;
        scanf("%d", &x);
        if (mp.find(x) != mp.end())
            printf("%d\n", mp[x]);
        else 
            printf("%d\n", x + 1);
    }
    return 0;
}

