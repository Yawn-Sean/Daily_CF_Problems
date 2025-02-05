#include <bits/stdc++.h>

using namespace std;
constexpr int N = 100;
char s[N + 1], t[N + 1];

int main() {
    scanf("%s", s);
    scanf("%s", t);
    int n = strlen(s);
    int carry = 1;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] < 'z') {
            s[i] += 1;
            carry -= 1;
            break;
        }
        s[i] = 'a';
    }
    bool flg = false;
    if (carry == 0) {
        for (int i = 0; i < n; i++) {
            if (s[i] < t[i]) {
                flg = true;
                break;
            }
        }
    }
    if (flg) {
        printf("%s\n", s);
    } else {
        printf("No such string\n");
    }
    return 0;
}

