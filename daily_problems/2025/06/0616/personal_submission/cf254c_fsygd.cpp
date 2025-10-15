#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

string s;
string t;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> s >> t;

    std::vector<int> s_count(26);
    std::vector<int> t_count(26);
    for (int i = 0; i < s.length(); ++i) {
        ++s_count[s[i] - 'A'];
        ++t_count[t[i] - 'A'];
    }

    int total = 0;
    for (int i = 0; i < 26; ++i) total += min(s_count[i], t_count[i]);
    printf("%d\n", s.length() - total);

    int y = 0;
    for (int i = 0; i < s.length(); ++i) {
        int x = s[i] - 'A';
        while (s_count[y] >= t_count[y] && y + 1 < 26) ++y;
        if (s_count[x] > t_count[x] && (t_count[x] == 0 || y < x)) x = y;
        --s_count[s[i] - 'A'];
        --t_count[x];
        printf("%c", 'A' + x);
    }
    printf("\n");
    fclose(stdin);
    fclose(stdout);
    return 0;
}