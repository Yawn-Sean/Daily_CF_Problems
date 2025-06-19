#include <bits/stdc++.h>

using namespace std;
constexpr int N = 100;
char s[N + 1];

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    scanf("%s", s);
    int n = strlen(s);
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'U') {
            y += 1;
        } else if (s[i] == 'D') {
            y -= 1;
        } else if (s[i] == 'L') {
            x -= 1;
        } else if (s[i] == 'R') {
            x += 1;
        }
    }
    // curr_x + k * x = a
    // curr_y + k * y = b
    for (int i = 0, curr_x = 0, curr_y = 0; i < n; i++) {
        if (x == 0 && y == 0) {
            if (curr_x == a && curr_y == b) {
                printf("Yes\n");
                return 0;
            }
        } else if (x) {
            if ((a - curr_x) % x == 0) {
                int k = (a - curr_x) / x;
                if (k >= 0 && curr_y + k * y == b) {
                    printf("Yes\n");
                    return 0;
                }
            }
        } else {
            if ((b - curr_y) % y == 0) {
                int k = (b - curr_y) / y;
                if (k >= 0 && curr_x + k * x == a) {
                    printf("Yes\n");
                    return 0;
                }
            }
        }
        if (s[i] == 'U') {
            curr_y += 1;
        } else if (s[i] == 'D') {
            curr_y -= 1;
        } else if (s[i] == 'L') {
            curr_x -= 1;
        } else if (s[i] == 'R') {
            curr_x += 1;
        }
    }
    printf("No\n");
    return 0;
}

