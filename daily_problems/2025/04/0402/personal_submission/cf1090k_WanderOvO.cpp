/*
不妨 s[i] t[i] 直接改成 mask 的形式，则应该有:
- t[i] in t[j]
- t[j] in t[i]
因此应该有 t[i] == t[j]，不妨先按照 t 分组，相同的放到一组里面
s 要满足什么条件？可能有的字符只在 s 中出现，没法通过后面的 t 去补充
同一个组里面，找 s 的最大后缀，使得这个后缀中的每个字符都在 t 中出现过
对于 s 剩下的前面的部分，只有一模一样的才能分到一起
*/

int n;
string s[N], t[N];
map<int, vector<int>> group_by_t;

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i] >> t[i];
        int mask = 0;
        for (int j = 0; j < t[i].size(); j++) {
            mask |= (1 << (t[i][j] - 'a'));
        }
        group_by_t[mask].push_back(i);
    }

    vector<vector<int>> final_groups;
    for (auto &t_group : group_by_t) {
        int mask = t_group.x;
        vector<int> ids = t_group.y;
        map<string, vector<int>> group_by_s;
        for (auto id : ids) {
            int pos = s[id].size();
            for (int i = s[id].size() - 1; i >= 0; i--) {
                int st = s[id][i] - 'a';
                st = (1 << st);
                if (mask & st) {
                    pos = i;
                } else {
                    break;
                }
            }

            group_by_s[s[id].substr(0, pos)].push_back(id);
        }
        for (auto it : group_by_s) {
            vector<int> new_group;
            for (auto id : it.y) {
                new_group.push_back(id);
            }
            final_groups.push_back(new_group);
        }
    }

    cout << final_groups.size() << "\n";
    for (auto &group : final_groups) {
        cout << group.size() << " ";
        for (auto id : group) {
            cout << id << " ";
        }
        cout << "\n";
    }
}
