#include <bits/stdc++.h>
using namespace std;

vector<string> gao(int d) {
    if (d == 1) return {"++", "+*"};
    vector<string> vec = gao(d - 1);
    vector<string> ret;
    for (auto &s : vec) ret.push_back(s + s);
    for (auto &s : vec) {
        string t = s;
        for (char c : s) {
            if (c == '+') t.push_back('*');
            else t.push_back('+');
        }
        ret.push_back(t);
    }
    return ret;
}

int main() {
    int d; scanf("%d", &d);
    if (d == 0) { printf("+\n"); return 0; }
    vector<string> vec = gao(d);
    for (auto &s : vec) printf("%s\n", s.c_str());
    return 0;
}
