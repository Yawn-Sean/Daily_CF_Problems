/*
对于给定的 s，寻找严格比 s 大且周期为 L 的最小的数
最终的字符串长度几乎是确定的，为 len = (s.size() + L - 1) / L * L
如果 len > s.size()，则直接选每段是 10..0 即可
如果 len = s.size()，则取 s 的前 L 位，答案要么是这 L 位拼起来，要么是这 L 位 + 1
注意这个时候的特殊情况，即 s.size() = 99..9 的情况
这个时候最终长度就是 len + L 了，每段都是 10..0
*/

int L;
string s;

void meibao() {
    cin >> L >> s;
    int n = s.size();
    int len = (n + L - 1) / L * L;
    if (len > s.size()) {
        string t = "1";
        for (int i = 1; i < L; i++) {
            t += "0";
        }
        for (int i = 1; i <= len / L; i++) {
            cout << t;
        }
        cout << "\n";
    } else {
        string t1 = s.substr(0, L);
        string res1 = "";
        for (int i = 1; i <= len / L; i++) {
            res1 += t1;
        }
        bool ok = false;
        for (int i = 0; i < len; i++) {
            if (res1[i] > s[i]) {
                ok = true;
                break;
            } else if (res1[i] < s[i]) {
                break;
            }
        }
        if (ok) {
            cout << res1 << "\n";
        } else {
            bool all_9 = true;
            for (int i = 0; i < L; i++) {
                if (t1[i] != '9') {
                    all_9 = false;
                }
            }
            if (all_9) {
                string t2 = "1";
                for (int i = 1; i < L; i++) {
                    t2 += "0";
                }
                for (int i = 0; i <= len / L; i++) {
                    cout << t2;
                }
                cout << "\n";
            } else {
                // +1，输出
                int flag = 1;
                for (int i = L - 1; i >= 0; i--) {
                    if (flag == 0) {
                        break;
                    }
                    if (t1[i] == '9') {
                        t1[i] = '0';
                    } else {
                        t1[i]++;
                        flag = 0;
                    }
                }
                for (int i = 1; i <= len / L; i++) {
                    cout << t1;
                }
                cout << "\n";
            }
        }
    }
}
