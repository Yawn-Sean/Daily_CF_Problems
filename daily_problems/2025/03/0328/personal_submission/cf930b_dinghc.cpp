#include <bits/stdc++.h>
 
using namespace std;
constexpr int N = 5'000;
char s[N + 1];
constexpr int A = 26;
vector<int> pos[A];

int main() {
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        pos[s[i] - 'a'].push_back(i);
    }
    int ans = 0;
    for (int c = 0; c < A; c++) if (!pos[c].empty()) {
        int cnt = 0;
        for (int d = 1; d < n; d++) {
            array<int, A> freq{};
            for (auto& p : pos[c]) {
                freq[s[(p + d) % n] - 'a'] += 1;
            }
            int u = 0;
            for (auto& k : freq) {
                if (k == 1) u += 1;
            }
            cnt = max(cnt, u);
        }
        ans += cnt;
    }
    printf("%.9f\n", 1.0 * ans / n);
    return 0;
}

