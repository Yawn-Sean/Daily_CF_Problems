#include <bits/stdc++.h>

using namespace std;
constexpr int N = 1000;
char s[N + 1];

bool solve(int n, int k) {
    for (int i = n - 1; i >= 0; i--) {
        set<char> forbidden_chars;
        for (int j = i - 1; j >= max(i - 2, 0); j--) {
            forbidden_chars.insert(s[j]);
        }
        for (int d = 1; d <= 3; d++) {
            if (s[i] + d < 'a' + k && forbidden_chars.count(s[i] + d) == 0) {
                s[i] += d;
                for (int j = i + 1; j < n; j++) {
                    set<char> forbidden_chars2;
                    for (int p = j - 1; p >= max(j - 2, 0); p--) {
                        forbidden_chars2.insert(s[p]);
                    }
                    for (int q = 0; q < 3; q++) {
                        if (forbidden_chars2.count('a' + q) == 0) {
                            s[j] = 'a' + q;
                            break;
                        }
                    }
                }
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n, p;
    scanf("%d%d", &n, &p);
    scanf("%s", s);
    if (solve(n, p)) {
        printf("%s\n", s);
    } else {
        printf("NO\n");
    }
    return 0;
}

