#include <bits/stdc++.h>
#define MAXN ((int) 5e5)
using namespace std;

int n, q, K;
char s[MAXN + 5], OP[MAXN + 5];

int f[MAXN + 5];

int main() {
    scanf("%d%d%d%s%s", &n, &q, &K, s + 1, OP + 1);

    stack<int> stk;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '(') stk.push(i);
        else {
            int t = stk.top(); stk.pop();
            f[i] = t; f[t] = i;
        }
    }

    list<int> lst;
    for (int i = 0; i <= n; i++) lst.push_back(i);
    auto it = lst.begin();
    while (*it != K) it++;

    for (int i = 1; i <= q; i++) {
        if (OP[i] == 'L') {
            if (prev(it) != lst.begin()) it--;
        } else if (OP[i] == 'R') {
            if (next(it) != lst.end()) it++;
        } else {
            int t = *it;
            if (s[*it] == '(') {
                if (t == *next(lst.begin()) && f[t] == *prev(lst.end())) continue;
                while (it != lst.end() && *it <= f[t]) lst.erase(it++);
            } else {
                if (f[t] == *next(lst.begin()) && t == *prev(lst.end())) continue;
                while (*it >= f[t]) lst.erase(it--);
                it++;
            }
            if (it == lst.end()) it--;
        }
    }

    for (int x : lst) if (x > 0) printf("%c", s[x]);
    printf("\n");
    return 0;
}
