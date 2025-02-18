#include <bits/stdc++.h>

using namespace std;
constexpr int N = 100'000;
char s[N + 1];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    int ans = 0;
    int tot_gold = 0;
    for (int i = 0, cnt_slvr = 0, j = 0; i < n; i++) {
        tot_gold += s[i] == 'G';
        cnt_slvr += s[i] == 'S';
        while (cnt_slvr > 1) {
            cnt_slvr -= s[j++] == 'S';
        }
        ans = max(ans, i - j + 1);
    }
    printf("%d\n", min(ans, tot_gold));
    return 0;
}

