#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;
typedef pair<int, int> pii;

int n, K;
char s[3][MAXN + 5];

int main() {
    scanf("%d", &K);
    for (int i = 0; i < 3; i++) scanf("%s", s[i]);
    n = strlen(s[0]);

    vector<pii> vec;
    for (int i = 0; i < 3; i++) {
        unordered_map<char, int> mp;
        for (int j = 0; j < n; j++) mp[s[i][j]]++;
        int mx = 0;
        for (auto &p : mp) mx = max(mx, p.second);
        if (K == 1 && mx == n) vec.push_back({n - 1, i});
        else vec.push_back({mx + min(n - mx, K), i});
    }
    sort(vec.begin(), vec.end(), greater<pii>());
    if (vec[0].first == vec[1].first) printf("Draw\n");
    else {
        vector<string> names = {"Kuro", "Shiro", "Katie"};
        printf("%s\n", names[vec[0].second].c_str());
    }
    return 0;
}
