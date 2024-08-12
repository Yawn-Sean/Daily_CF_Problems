#include <bits/stdc++.h>

using namespace std;
constexpr int MX = 55;
char s[MX];
char t[MX];

int main() {
    int test;
    scanf("%d", &test);
    while (test--) {
        int n;
        scanf("%d", &n);
        scanf("%s", s + 1);
        scanf("%s", t + 1);
        int freq[26]{};
        for (int i = 1; i <= n; i++) {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']++;
        }
        bool valid = true;
        for (auto& cnt : freq) {
            if (cnt % 2) {
                valid = false;
                break;
            }
        }
        if (!valid) {
            printf("No\n");
            continue;
        }
        printf("Yes\n");
        vector<pair<int, int>> swaps;
        for (int i = 1; i <= n; i++) {
            if (s[i] != t[i]) {
                for (int j = i + 1; j <= n; j++) {
                    if (s[j] == s[i]) {
                        swaps.emplace_back(j, i);
                        swap(s[j], t[i]);
                        break;
                    } else if (t[j] == s[i]) {
                        swaps.emplace_back(j, j);
                        swap(s[j], t[j]);
                        swaps.emplace_back(j, i);
                        swap(s[j], t[i]);
                        break;
                    }
                }
            }
        }
        printf("%d\n", swaps.size());
        for (auto&[x, y] : swaps) {
            printf("%d %d\n", x, y);
        }
    }
    return 0;
}

