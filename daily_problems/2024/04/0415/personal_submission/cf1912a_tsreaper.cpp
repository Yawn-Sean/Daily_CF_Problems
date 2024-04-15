#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
vector<pll> vec[MAXN + 10]; 

int main() {
    long long X; scanf("%lld%d", &X, &n);
    for (int i = 1; i <= n; i++) {
        int len; scanf("%d", &len);
        long long now = 0, mn = 0;
        for (int j = 1; j <= len; j++) {
            int x; scanf("%d", &x);
            now += x;
            if (now > 0) {
                vec[i].push_back(pll(-mn, now));
                now = mn = 0;
            } else {
                mn = min(mn, now);
            }
        }
    }
    
    map<long long, vector<pii>> mp;
    for (int i = 1; i <= n; i++) if (vec[i].size() > 0) mp[vec[i][0].first].push_back(pii(i, 0));

    while (!mp.empty() && mp.begin()->first <= X) {
        for (auto &p : mp.begin()->second) {
            int i = p.first, j = p.second;
            while (j < vec[i].size() && vec[i][j].first <= X) {
                X += vec[i][j].second;
                j++;
            }
            if (j < vec[i].size()) mp[vec[i][j].first].push_back(pii(i, j));
        }
        mp.erase(mp.begin());
    }
    printf("%lld\n", X);
    return 0;
}
