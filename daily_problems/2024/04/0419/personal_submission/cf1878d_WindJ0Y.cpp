#include <bits/stdc++.h>
using namespace std;

void work() {
    int n, m;
    cin >> n >> m;

    string str; cin >> str;

    vector<pair<int, int>> lines(m);
    for (int i = 0; i < m; i++) {
        cin >> lines[i].first;
        lines[i].first--;
    }
    for (int i = 0; i < m; i++) {
        cin >> lines[i].second;
        lines[i].second--;
    }

    int q; cin >> q;
    vector<int> qs(q);
    for (int i = 0; i < q; i++) {
        cin >> qs[i];
        qs[i]--;
    }
    sort(qs.begin(), qs.end());
    auto qpos = qs.begin();

    for (auto line : lines) {
        int l = line.first, r = line.second;
        int len = r - l + 1;
        vector<int> mcnt(len);

        while (qpos != qs.end() && *qpos <= r) {
            int pos = *qpos;
            assert(l <= pos && pos <= r);
            int tp = pos - l;
            mcnt[tp]++;
            mcnt[len - tp - 1]++;
            qpos++;
        }

        string target_str = str.substr(l, len);

        bool in_mirror = false;
        for (int i = 0 ; i < len; i ++) {
            int mirror_i = len - i - 1;
            if ((i < len / 2) && (mcnt[i] & 1)) {
                in_mirror = !in_mirror;
            }
            str[l + i] = (in_mirror ? target_str[mirror_i] : target_str[i]);
            if ((i >= len / 2) && (mcnt[i] & 1)) {
                in_mirror = !in_mirror;
            }
        }
    }

    cout << str << '\n';
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T {1};
    cin >> T;

    while (T--) {
        work();
    }
}