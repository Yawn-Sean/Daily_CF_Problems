#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, L, R, q;
char s[MAXN + 5];

int main() {
    scanf("%d%d%d%s%d", &n, &L, &R, s + 1, &q);

    deque<char> dq;
    for (int i = L; i <= R; i++) dq.push_back(s[i]);
    bool rev = false;

    while (q--) {
        char op[3]; scanf("%s", op);
        if (op[0] == 'S') {
            char x[3], y[3]; scanf("%s%s", x, y);
            if (x[0] == 'L') {
                if (y[0] == 'L') {
                    if (rev) dq.push_back(s[--L]);
                    else dq.push_front(s[--L]);
                } else {
                    if (rev) s[L++] = dq.back(), dq.pop_back();
                    else s[L++] = dq.front(), dq.pop_front();
                }
            } else {
                if (y[0] == 'R') {
                    if (rev) dq.push_front(s[++R]);
                    else dq.push_back(s[++R]);
                } else {
                    if (rev) s[R--] = dq.front(), dq.pop_front();
                    else s[R--] = dq.back(), dq.pop_back();
                }
            }
        } else if (op[0] == 'R') {
            rev = !rev;
        } else {
            char x[3]; scanf("%s", x);
            if (x[0] == 'L') {
                if (rev) printf("%c", dq.back());
                else printf("%c", dq.front());
            } else {
                if (rev) printf("%c", dq.front());
                else printf("%c", dq.back());
            }
        }
    }
    printf("\n");
    return 0;
}
