/*
map 维护类型名和实际代表啥
不妨设 0 为 errtype，1 为 void
用 pair 表示
(0, 0) 是 errtype
(1, x) 是 void 的 x 级指针，如果 x 是负数则表示解了
typedef 时，需要把前缀的 & 和后缀的 * 个数算出来
*/

map<string, PII> ts;
int n;

int get_cnt(string t) {
    int res = 0;
    for (int i = 0; i < t.size(); i++) {
        if (t[i] == '&') {
            res--;
        } else {
            break;
        }
    }
    for (int i = t.size() - 1; i >= 0; i--) {
        if (t[i] == '*') {
            res++;
        } else {
            break;
        }
    }

    return res;
}

string get_pure_type(string s) {
    int st = 0, ed = s.size() - 1;
    while (st < s.size() && s[st] == '&') {
        st++;
    }
    while (ed >= 0 && s[ed] == '*') {
        ed--;
    }
    assert(ed >= st);
    return s.substr(st, ed - st + 1);
}

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string op;
        cin >> op;
        if (op == "typedef") {
            string old_t, new_t;
            cin >> old_t >> new_t;
            string pure_t = get_pure_type(old_t);
            int cnt = get_cnt(old_t);
            if (pure_t == "errtype") {
                ts[new_t] = {0, 0};
            } else if (pure_t == "void") {
                if (cnt >= 0) {
                    ts[new_t] = {1, cnt};
                } else {
                    ts[new_t] = {0, 0};
                }
            } else {
                if (!ts.count(pure_t)) {
                    ts[new_t] = {0, 0};
                    continue;
                }
                PII val = ts[pure_t];
                if (val.x == 0) {
                    ts[new_t] = {0, 0};
                } else {
                    val.y += cnt;
                    if (val.y >= 0) {
                        ts[new_t] = val;
                    } else {
                        ts[new_t] = {0, 0};
                    }
                }
            }
        } else {
            string t;
            cin >> t;
            int cnt = get_cnt(t);
            string pure_t = get_pure_type(t);
            if (pure_t == "errtype") {
                cout << "errtype" << "\n";
            } else if (pure_t == "void") {
                if (cnt >= 0) {
                    cout << "void";
                    for (int j = 0; j < cnt; j++) {
                        cout << "*";
                    }
                    cout << "\n";
                } else {
                    cout << "errtype\n";
                }
            } else {
                if (!ts.count(pure_t)) {
                    cout << "errtype\n";
                    continue;
                }
                PII val = ts[pure_t];
                val.y += cnt;
                if (val.x == 0) {
                    cout << "errtype\n";
                } else {
                    if (val.y >= 0) {
                        cout << "void";
                        for (int j = 0; j < val.y; j++) {
                            cout << "*";
                        }
                        cout << "\n";
                    } else {
                        cout << "errtype\n";
                    }
                }
            }
        }
    }
}   
