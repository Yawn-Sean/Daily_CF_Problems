#include <bits/stdc++.h>

using namespace std;
using li = long long;
constexpr int N = 200'000;
char s[N+1];

int main() {
    int n, a, b, k;
    scanf("%d%d%d%d", &n, &a, &b, &k);
    scanf("%s", s);
    vector<int> ans;
    for (int i = 0, curr = 0; i < n; i++) {
        if (s[i] == '0') {
            if (++curr == b) {
                if (a == 0) {
                    ans.push_back(i + 1);
                } else {
                    if (--a == 0) {
                        ans.push_back(i + 1);
                    }
                }
                curr = 0;
            }
        } else {
            curr = 0;
        }
    }
    printf("%d\n", ans.size());
    for (auto& x : ans) {
        printf("%d ", x);
    }
    printf("\n");
    return 0;
}

