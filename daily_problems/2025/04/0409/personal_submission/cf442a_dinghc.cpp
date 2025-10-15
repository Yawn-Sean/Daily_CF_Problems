#include <bits/stdc++.h>
 
using namespace std;
constexpr int N = 300;
char s[N + 1];
map<char, int> colors {
    {'R', 0}, 
    {'G', 1}, 
    {'B', 2}, 
    {'Y', 3}, 
    {'W', 4}
};

int main() {
    int n;
    scanf("%d", &n);
    map<pair<int, int>, pair<int, int>> sta;
    getchar(); gets(s);
    for (int i = 0; i < n; i++) {
        int c = colors[s[i * 3]];
        int v = s[i * 3 + 1] - '0' - 1;
        sta[make_pair(c, v)] = make_pair(-1, -1);
    }
    int ans = n;
    for (int msk1 = 0; msk1 < 32; msk1 += 1) {
        for (int msk2 = 0; msk2 < 32; msk2 += 1) {
            map<pair<int, int>, pair<int, int>> stb = sta;
            for (auto& [k, st] : stb) {
                if (msk1 & (1 << k.first)) {
                    st.first = k.first;
                }
                if (msk2 & (1 << k.second)) {
                    st.second = k.second;
                }
            }
            set<pair<int, int>> dist;
            for (auto& [k, st] : stb) {
                dist.insert(st);
            }
            if (dist.size() == stb.size()) {
                ans = min(ans, __builtin_popcount(msk1) + __builtin_popcount(msk2));
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}

