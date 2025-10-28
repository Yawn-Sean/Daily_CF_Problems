#include <bits/stdc++.h>
using namespace std;

long long ans[100];

int main() {
    ans[12] = 48;
    ans[15] = 5055;
    ans[18] = 288;
    ans[21] = 7077;
    ans[24] = 8088;
    ans[27] = 3699;
    ans[36] = 48888;
    ans[45] = 5055555555L;
    ans[54] = 222888888;
    ans[63] = 111888;
    ans[72] = 8088888888L;
    ans[81] = 9099999999L;

    int tcase; scanf("%d", &tcase);
    while (tcase--) {
        long long n; scanf("%lld", &n);
        vector<int> vec;
        for (long long x = n; x; x /= 10) vec.push_back(x % 10);
        sort(vec.begin(), vec.end());
        if (vec[0] == vec.back()) printf("%lld\n", n);
        else if (n < 100 && ans[n]) printf("%lld\n", ans[n]);
        else printf("-1\n");
    }
    return 0;
}
