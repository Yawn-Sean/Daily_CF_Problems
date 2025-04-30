#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <map>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    i64 n, m, p;
    cin >> n >> m >> p;

    vector<i64> a(n), b(m);
    map<int, int> cnt2;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        ++cnt2[b[i]];
    }

    int ans_cnt = 0;
    vector<int> ans(n, 0);
    for (int i = 0; i < p; i++) {
        if (1ll * i + 1ll * (m - 1) * p >= n) {
            break;
        }

        map<int,int> cnt1;
        int match = 0;
        auto add_element = [&](int x) {
            if(cnt2.find(x) != cnt2.end()) {
                match -= (cnt1[x] == cnt2[x]);
                ++cnt1[x];
                match += (cnt1[x] == cnt2[x]);
            }
        };

        auto del_element = [&](int x) {
            if (cnt2.find(x) != cnt2.end()) {
                match -= (cnt1[x] == cnt2[x]);
                --cnt1[x];
                match += (cnt1[x] == cnt2[x]);
            }
        };

        for (int j = 0; j < m; j++) {
            add_element(a[i + j * p]);
        }
        if (match == cnt2.size()) {
            ans[i] = 1;
            ++ans_cnt;
        }

        for (int ni = i; ni < n; ni += p) {
            del_element(a[ni]);
            if (1ll * ni + 1ll * m * p >= n) {
                break;
            }
            add_element(a[ni + m * p]);
            if (match == cnt2.size()) {
                ans[ni + p] = 1;
                ++ans_cnt;
            }
        }
    }

    cout << ans_cnt << '\n';
    for (int i = 0; i < n; i++) {
        if (ans[i] == 1) { cout << i + 1 << ' '; }
    }
    return 0;
}
