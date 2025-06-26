#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> path;
    
    for (int i = 1; i <= 6; i++) for (int j = 0; j < 8; j++) {
        string s;
        if (i & 1) s.push_back(j + 'a');
        else s.push_back((7 - j) + 'a');
        s.push_back(i + '0');
        path.push_back(s);
    }

    for (int j = 0; j < 6; j++) {
        string s;
        s.push_back(j + 'a');
        s.push_back('7');
        path.push_back(s);
    }
    path.push_back("h7");
    path.push_back("g7");

    path.push_back("g8");
    for (int j = 0; j < 6; j++) {
        string s;
        s.push_back(j + 'a');
        s.push_back('8');
        path.push_back(s);
    }
    path.push_back("h8");

    int n; scanf("%d", &n);
    for (int i = 0; i < n - 2; i++) printf("%s ", path[i].c_str());
    string t = path[n - 2];
    if (t[1] - '0' <= 7) {
        if (t == "h7") printf("g7 g8 h8\n");
        else if (t[0] != 'h') printf("%s %c8 h8\n", t.c_str(), t[0]);
        else printf("%s h7 h8\n", t.c_str());
    } else {
        printf("%s %s h8\n", t.c_str(), path[n - 1].c_str());
    }
    return 0;
}
