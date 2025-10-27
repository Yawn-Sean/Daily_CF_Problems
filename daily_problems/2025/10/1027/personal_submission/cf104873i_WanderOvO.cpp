/*
完全想复杂了
关键的观察只有每个数组元素不相同
所以假如同时问 1 1 2 2 这种，我们完全能分辨出来 1 和 2 是谁
所以只要问 1 1 2 2 3 3... 就好了，两三次就能搞定
*/

int n;

void solve() {
    cin >> n;

    auto query = [&] (vector<int> &ids) -> void {
        cout << "? ";
        cout << ids.size() << " ";
        for (auto id : ids) {
            cout << id << " ";
        }
        cout << endl;
    };

    if (n == 1) {
        vector<int> ids;
        ids.push_back(1);
        query(ids);
        int len;
        cin >> len;
        vector<int> ans;
        for (int i = 1; i <= len; i++) {
            int x;
            cin >> x;
            ans.push_back(x);
        }
        cout << "! " << ans.size() << " ";
        for (auto val : ans) {
            cout << val << " ";
        }
        cout << endl;
    } else {
        vector<int> ids;
        int i = 1;
        vector<vector<int>> ans;
        while (i <= n) {
            ids.clear();
            if (i == n) {
                ids.push_back(n);
                query(ids);
                int len;
                cin >> len;
                vector<int> cur;
                for (int i = 1; i <= len; i++) {
                    int x;
                    cin >> x;
                    cur.push_back(x);
                }
                ans.push_back(cur);
                break;
            }
            int cnt = 0;
            for ( ; cnt <= n; ) {
                if (cnt + 2 <= n) {
                    ids.push_back(i);
                    ids.push_back(i);
                    i++;
                    cnt += 2;
                } else {
                    break;
                }
            }

            query(ids);
            int len;
            cin >> len;
            vector<int> a;
            for (int j = 1; j <= len; j++) {
                int x;
                cin >> x;
                a.push_back(x);
            }

            for (int j = 0; j < len; ) {
                for (int k = j + 1; k < len; k++) {
                    if (a[j] == a[k]) {
                        int cnt = k - j;
                        vector<int> cur;
                        for (int l = j; l < k; l++) {
                            cur.push_back(a[l]);
                        }
                        j += 2 * cnt;
                        ans.push_back(cur);
                        break;
                    }
                }
            }
        }
        cout << "! ";
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i].size() << " ";
            for (auto v : ans[i]) {
                cout << v << " ";
            }
        }
        cout << endl;
    }
}
