/*
有 m 轮游戏，第 i 轮有 k[i] 个朋友是可以来协助的
希望每个朋友被邀请协助的次数不严格大于 (m + 1) / 2
倘若在这 m 轮里，所有出现过的朋友都没有超过 (m + 1) / 2 次，就可以随便搞
倘若有人出现次数超过了 (m + 1) / 2 次，不妨先用它 (m + 1) / 2 次，然后其他人就可以随便用了（前提是有其他人）
假设编号为 id 的人出现超过 (m + 1) / 2 次，我们优先把只出现它的那些去强制选了
如果只有 id 能选的天数居然超过了 (m + 1) / 2 次，则必然不行
*/

int n, m;
vector<set<int>> e(N);

void meibao() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        e[i].clear();
    }
    vector<int> cnt(n + 1, 0);
    for (int i = 1; i <= m; i++) {
        int k;
        cin >> k;
        while (k--) {
            int id;
            cin >> id;
            cnt[id]++;
            e[i].insert(id);
        }
    }    

    int id = -1;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] > (m + 1) / 2) {
            id = i;
            break;
        }
    }
    if (id == -1) {
        cout << "YES\n";
        for (int i = 1; i <= m; i++) {
            cout << *e[i].begin() << " ";
        }
        cout << "\n";
    } else {
        vector<int> res(m + 1, 0);
        int must_choose_cnt = 0;
        for (int i = 1; i <= m; i++) {
            if (e[i].count(id) && e[i].size() == 1) {
                res[i] = id;
                must_choose_cnt++;
            }
        }
        if (must_choose_cnt > (m + 1) / 2) {
            cout << "NO\n";
            return;
        }

        cout << "YES\n";
        for (int i = 1; i <= m; i++) {
            if (res[i] == 0) {
                if (e[i].count(id) && must_choose_cnt < (m + 1) / 2) {
                    res[i] = id;
                    must_choose_cnt++;
                } else {
                    for (auto other_id : e[i]) {
                        if (other_id != id) {
                            res[i] = other_id;
                            break;
                        }
                    }
                }
            }
        }
        for (int i = 1; i <= m; i++) {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
}
