#include <bits/stdc++.h>
#define MAXM 50
using namespace std;

int a, b, c, d;
vector<string> ans;

void gao(int b, char ca, char cb) {
    string base;
    for (int i = 0; i < MAXM; i++) base.push_back(ca);
    ans.push_back(base);
    while (b > 0) {
        int t = min(b, MAXM / 2);
        b -= t;
        string s = base;
        for (int i = 0; i < t; i++) s[i * 2] = cb;
        ans.push_back(s);
        ans.push_back(base);
    }
}

int main() {
    scanf("%d%d%d%d", &a, &b, &c, &d);

    gao(b - 1, 'A', 'B');
    gao(a - 1, 'B', 'A');
    gao(d - 1, 'C', 'D');
    gao(c - 1, 'D', 'C');

    printf("%d %d\n", ans.size(), MAXM);
    for (int i = 0; i < ans.size(); i++) printf("%s\n", ans[i].c_str());
    return 0;
}
