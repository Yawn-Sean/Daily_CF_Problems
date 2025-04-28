

int cnt[N], n, a[N];
int res[N];

void meibao() {
    cin >> n;
    for (int i = 1; i <= 2 * n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= 2 * n; i++) {
        if (cnt[a[i]] == 1) {
            if (cnt1 > cnt2) {
                cnt2++;
                res[i] = 2;
            } else {
                cnt1++;
                res[i] = 1;
            }
        }
    }

    map<int, vector<int>> positions;
    for (int i = 1; i <= 2 * n; i++) {
        if (cnt[a[i]] > 1) {
            positions[a[i]].push_back(i);
        }
    } 

    for (auto &it : positions) {
        if (cnt1 > cnt2) {
            for (int i = 0; i < it.y.size(); i++) {
                res[it.y[i]] = (i % 2 == 0 ? 2 : 1);
                if (i % 2 == 0) {
                    cnt2++;
                } else {
                    cnt1++;
                }
            }
        } else {
            for (int i = 0; i < it.y.size(); i++) {
                res[it.y[i]] = (i % 2 == 0 ? 1 : 2);
                if (i % 2 == 0) {
                    cnt1++;
                } else {
                    cnt2++;
                }
            }
        }
    }

    set<int> s1, s2;
    for (int i = 1; i <= 2 * n; i++) {
        if (res[i] == 1) {
            s1.insert(a[i]);
        } else {
            s2.insert(a[i]);
        }
    }

    cout << s1.size() * s2.size() << "\n";
    assert(cnt1 == cnt2);

    for (int i = 1; i <= 2 * n; i++) {
        assert(res[i] != 0);
        cout << res[i] << " "; 
    }
}   
