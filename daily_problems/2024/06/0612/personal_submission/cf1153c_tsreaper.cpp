#include <bits/stdc++.h>
#define MAXN ((int) 3e5)
using namespace std;

int n;
char s[MAXN + 10];

int main() {
    scanf("%d%s", &n, s + 1);
    vector<int> vec;
    int now = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '(') now++;
        else if (s[i] == ')') now--;
        else {
            s[i] = ')';
            now--;
            vec.push_back(i);
        }

        while ((i < n && now <= 0) || (i == n && now < 0)) {
            if (vec.empty()) { printf(":(\n"); return 0; }
            s[vec.back()] = '(';
            now += 2;
            vec.pop_back();
        }
    }
    if (now == 0) printf("%s\n", s + 1);
    else printf(":(\n");
    return 0;
}
