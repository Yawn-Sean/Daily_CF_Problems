#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef vector<vll> vvll;

#define INF 1e18
#define MOD 1000000007

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, s, t;
    cin >> n >> k >> s >> t;
    vector<pii> res;
    for (int i = 0; i < n; ++i) {
        int ci, vi;
        cin >> ci >> vi;
        res.emplace_back(ci, vi);
    }
    vi pos(k);
    for (int i = 0; i < k; ++i) {
        cin >> pos[i];
    }
    sort(pos.begin(), pos.end());
    pos.insert(pos.begin(), 0);
    pos.push_back(s);

    int mxDis = 0;
    for (int i = 1; i < pos.size(); ++i) {
        mxDis = max(mxDis, pos[i] - pos[i-1]);
    }

    vector<pii> candi;
    for (auto& [ci, vi] : res) {
        if (vi >= mxDis) {
            candi.emplace_back(ci, vi);
        }
    }
    if (candi.empty()) {
        cout << -1 << endl;
        return 0;
    }
    sort(candi.begin(), candi.end());
    int tmp = 0;
    for (int i = 0; i < candi.size(); ++i) {
        tmp = max(tmp, candi[i].second);
        candi[i].second = tmp;
    }

    auto miCostTime = [&](int x) {
        ll ret = 0;
        for (int i = 1; i < pos.size(); ++i) {
            int dis = pos[i] - pos[i-1];
            int costB = min(x - dis, dis);
            int tarTime = 2 * dis - costB;
            ret += tarTime;
        }
        return ret;
    };

    if (miCostTime(candi.back().second) > t) {
        cout << -1 << endl;
        return 0;
    }

    int low = 0, high = candi.size() - 1;
    int ans = high;
    while (low <= high) {
        int mid = (low + high) >> 1;
        if (miCostTime(candi[mid].second) > t) {
            low = mid + 1;
        } else {
            ans = mid;
            high = mid - 1;
        }
    }
    cout << candi[ans].first << endl;

    return 0;
}
