#include <bits/stdc++.h>
#define MAXN 100
using namespace std;
typedef pair<int, int> pii;

int gao(vector<pii> &vec, int X) {
    int n = vec.size();
    int ret = 0;
    multiset<pii> ms;
    for (int i = n - 1, j = 0; i >= 0; i--) {
        while (j < i && vec[i].first + vec[j].first <= X) {
            ms.insert(pii(vec[j].second, vec[j].first));
            j++;
        }
        if (j > i) ms.erase(ms.find(pii(vec[i].second, vec[i].first)));
        if (ms.size() > 0) ret = max(ret, vec[i].second + prev(ms.end())->first);
        if (j > i) ms.insert(pii(vec[i].second, vec[i].first));
    }
    return ret;
}

int main() {
    int n, C, D; scanf("%d%d%d", &n, &C, &D);
    vector<pii> vc, vd;
    for (int i = 1; i <= n; i++) {
        int x, y;
        char s[3];
        scanf("%d%d%s", &x, &y, s);
        if (s[0] == 'C') vc.push_back(pii(y, x));
        else vd.push_back(pii(y, x));
    }
    sort(vc.begin(), vc.end());
    sort(vd.begin(), vd.end());

    int mxc = 0, mxd = 0;
    for (pii p : vc) if (p.first <= C) mxc = max(mxc, p.second);
    for (pii p : vd) if (p.first <= D) mxd = max(mxd, p.second);
    printf("%d\n", max({mxc && mxd ? mxc + mxd : 0, gao(vc, C), gao(vd, D)}));
    return 0;
}
