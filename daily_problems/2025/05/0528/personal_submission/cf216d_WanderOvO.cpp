/*
对于每个扇形，使用双指针维护每个扇形的左右两边的连接点个数即可
*/

int n;
vector<vector<int>> e(M);

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int cnt;
        cin >> cnt;
        while (cnt--) {
            int d;
            cin >> d;
            e[i].push_back(d);
        }
        sort(e[i].begin(), e[i].end());
    }

    int res = 0;

    auto calc = [&] (int id, int last, int ne) -> int {
        int ans = 0;
        int p1 = 0, p2 = -1, p3 = 0, p4 = -1;
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i + 1 < e[id].size(); i++) {
            while (p2 + 1 < e[last].size() && e[last][p2 + 1] < e[id][i + 1]) {
                p2++;
                cnt1++;
            }
            while (p1 <= p2 && e[last][p1] < e[id][i]) {
                p1++;
                cnt1--;
            }

            while (p4 + 1 < e[ne].size() && e[ne][p4 + 1] < e[id][i + 1]) {
                p4++;
                cnt2++;
            }
            while (p3 <= p4 && e[ne][p3] < e[id][i]) {
                p3++;
                cnt2--;
            }

            if (cnt1 != cnt2) {
                ans++;
            }
        }
        return ans;
    };

    for (int i = 1; i <= n; i++) {
        int last = (i == 1) ? n : (i - 1);
        int ne = (i == n) ? 1 : (i + 1);
        res += calc(i, last, ne);
    }
    cout << res << "\n";
}
