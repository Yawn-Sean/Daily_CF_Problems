#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%d", &n);

    vector<char> ans1;
    int i = 1, j = 1;
    for (int d = 2; d < n + 1; d++) {
        bool right = false;
        if (j < n) {
            printf("? %d %d %d %d\n", i, j + 1, n, n);
            fflush(stdout);
            char s[10]; scanf("%s", s);
            if (s[0] == 'Y') right = true;
        }
        if (right) ans1.push_back('R'), j++;
        else ans1.push_back('D'), i++;
    }

    vector<char> ans2;
    i = j = n;
    for (int d = n * 2; d > n + 1; d--) {
        bool up = false;
        if (i > 1) {
            printf("? %d %d %d %d\n", 1, 1, i - 1, j);
            fflush(stdout);
            char s[10]; scanf("%s", s);
            if (s[0] == 'Y') up = true;
        }
        if (up) ans2.push_back('D'), i--;
        else ans2.push_back('R'), j--;
    }
    reverse(ans2.begin(), ans2.end());

    printf("! ");
    for (char c : ans1) printf("%c", c);
    for (char c : ans2) printf("%c", c);
    printf("\n");
    fflush(stdout);
    return 0;
}
