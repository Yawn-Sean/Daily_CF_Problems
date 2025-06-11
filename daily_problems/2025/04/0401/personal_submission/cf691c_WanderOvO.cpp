string s;

void meibao() {
    cin >> s;
    int first_not_zero_pos = -1, last_not_zero_pos = -1;
    int dot_pos = -1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '.') {
            dot_pos = i;
            break;
        }
    }
    // 前导 0 无脑删
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '0') {
            first_not_zero_pos = i;
            break;
        }
    }
    string t;
    if (dot_pos != -1) {
        // 有小数点则无脑删后导 0
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] != '0') {
                last_not_zero_pos = i;
                break;
            }
        }
        assert(first_not_zero_pos != -1 && last_not_zero_pos != -1);
        t = s.substr(first_not_zero_pos, last_not_zero_pos - first_not_zero_pos + 1);
    } else {
        // 没有小数点就不要动后缀
        t = s.substr(first_not_zero_pos);
    }
    
    dot_pos = -1;
    for (int i = 0; i < t.size(); i++) {
        if (t[i] == '.') {
            dot_pos = i;
            break;
        }
    }

    if (dot_pos == -1) {
        if (t.size() == 1) {
            // 1 位整数
            cout << t << "\n";
        } else {
            // 多位整数
            int cnt = t.size() - 1;
            last_not_zero_pos = 0;
            for (int i = 1; i < t.size(); i++) {
                if (t[i] != '0') {
                    last_not_zero_pos = i;
                }
            }
            cout << t[0];
            if (last_not_zero_pos > 0) {
                cout << ".";
                for (int i = 1; i <= last_not_zero_pos; i++) {
                    cout << t[i];
                }
            }
            
            cout << "E" << cnt << "\n";
        }
    } else {
        if (t[0] == '.') {
            // 纯小数
            int cnt = 1;
            int pos = 1;
            for ( ; pos < t.size() && t[pos] == '0'; pos++, cnt++);
            assert(pos < t.size());
            cout << t[pos];
            if (pos + 1 < t.size()) {
                cout << ".";
            }
            for (int i = pos + 1; i < t.size(); i++) {
                cout << t[i];
            }
            if (cnt != 0) {
                cout << "E" << -cnt << "\n";
            }
        } else if (t.back() == '.') {
            // 整数
            if (t.size() == 2) {
                cout << t[0] << "\n";
            } else {
                int cnt = t.size() - 2;

                last_not_zero_pos = 0;
                for (int i = 1; i < t.size() - 1; i++) {
                    if (t[i] != '0') {
                        last_not_zero_pos = i;
                    }
                }
                cout << t[0];
                if (last_not_zero_pos > 0) {
                    cout << ".";
                    for (int i = 1; i <= last_not_zero_pos; i++) {
                        cout << t[i];
                    }
                }
                
                cout << "E" << cnt << "\n";
            }
        } else {
            if (dot_pos == 1) {
                cout << t << "\n";
            } else {
                int cnt = dot_pos - 1;
                cout << t[0];
                cout << ".";
                for (int i = 1; i < t.size(); i++) {
                    if (t[i] == '.') continue;
                    cout << t[i];
                }
                cout << "E" << cnt << "\n";
            }
        }
    }
}
