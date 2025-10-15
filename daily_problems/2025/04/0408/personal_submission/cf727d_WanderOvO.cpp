/*
先把只有一种的给分配了
对于剩下的，通用的匹配算法时间复杂度超了，考虑根据图的性质寻求其他做法
考虑按照每个人需要的最小尺寸排序，然后枚举每个人，先拿小号的，小号没了拿大号的
如果排序时还考虑了把只有一种选择的排到前面，则可以整套流程直接做下来
*/

map<string, int> sz;
string raw_sz[7] = {"S", "M", "L", "XL", "XXL", "XXXL"};
int n, res[N], cnt[7], order[N];
vector<vector<int>> a(N);

void meibao() {
    sz["S"] = 0;
    sz["M"] = 1;
    sz["L"] = 2;
    sz["XL"] = 3;
    sz["XXL"] = 4;
    sz["XXXL"] = 5;

    for (int i = 0; i < 6; i++) {
        cin >> cnt[i];
    }
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        int comma_pos = -1;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == ',') {
                comma_pos = j;
                break;
            }
        }

        if (comma_pos == -1) {
            a[i].push_back(sz[s]);
        } else {
            a[i].push_back(sz[s.substr(0, comma_pos)]);
            a[i].push_back(sz[s.substr(comma_pos + 1)]);
        }
    }

    for (int i = 1; i <= n; i++) {
        order[i] = i;
    }

    sort(order + 1, order + n + 1, [&] (int i, int j) -> bool {
        if (a[i].size() == a[j].size()) {
            return a[i][0] < a[j][0];
        }
        return a[i].size() < a[j].size();
    });

    bool ok = true;
    for (int i = 1; i <= n; i++) {
        int id = order[i];
        if (a[id].size() == 1) {
            if (cnt[a[id][0]] > 0) {
                cnt[a[id][0]]--;
                res[id] = a[id][0];
            } else {
                ok = false;
                break;
            }
        } else {
            if (cnt[a[id][0]] > 0) {
                cnt[a[id][0]]--;
                res[id] = a[id][0];
            } else if (cnt[a[id][1]] > 0) {
                cnt[a[id][1]]--;
                res[id] = a[id][1];
            } else {
                ok = false;
                break;
            }
        }
    }

    if (ok) {
        cout << "YES\n";
        for (int i = 1; i <= n; i++) {
            // cout << res[i] << " ";
            cout << raw_sz[res[i]] << "\n";
        }
    } else {
        cout << "NO\n";
    }
}
