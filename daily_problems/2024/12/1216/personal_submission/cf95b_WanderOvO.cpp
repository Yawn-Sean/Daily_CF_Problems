/*
如果 n 长度为奇数，则答案就是 4...47...7，比 n 多一位
如果 n 长度为偶数 cnt，则枚举高 i 位相同的情况下，最小是多少
假如第 i 位是 4 或者 7，则考虑第 i + 1 位是填 4 还是填 7 才能严格大
- 如果能严格大，则后边就可以随便填了，如果能填得相等就 OK
- 如果填 7 都不能严格大，则直接考虑下一轮枚举 i + 1 的前缀

假如第 i 位不是 4 和 7，则肯定不能相同了，无需考虑相等的情况了
肯定是越多位相同的，最后越小
假如本来 n 就是超级好串，则不用做了
假如上来就不是 4 和 7，必须决出大小，则如果能保证构造出的数更大，则答案也确定了，否则说明得是 cnt + 2 位数
*/

string s;

void meibao() {
    cin >> s;
    int n = s.size();
    bool all_47 = true;
    int flag = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '4' || s[i] == '7') {
            flag += (s[i] == '4' ? 1 : -1);
        } else {
            all_47 = false;
            break;
        }
    }
    if (all_47 && flag == 0) {
        cout << s << "\n";
        return;
    }

    if (n % 2 != 0) {
        for (int i = 0; i < (n + 1) / 2; i++) {
            cout << "4";
        }
        for (int i = 0; i < (n + 1) / 2; i++) {
            cout << "7";
        }
        cout << "\n";
        return;
    }

    if (s[0] != '4' && s[0] != '7') {
        if (s[0] < '4') {
            for (int i = 0; i < n / 2; i++) {
                cout << "4";
            }
            for (int i = 0; i < n / 2; i++) {
                cout << "7";
            }
        } else if (s[0] < '7') {
            cout << "7";
            for (int i = 0; i < n / 2; i++) {
                cout << "4";
            }
            for (int i = 0; i < n / 2 - 1; i++) {
                cout << "7";
            }
        } else {
            for (int i = 0; i < (n + 2) / 2; i++) {
                cout << "4";
            }
            for (int i = 0; i < (n + 2) / 2; i++) {
                cout << "7";
            }
        }
        return;
    }

    int cnt4 = 0, cnt7 = 0;
    int max_same_pos = -2;
    // 枚举从 s[i] 开始不一样
    for (int i = 0; i < n; i++) {
        if (s[i] < '4') {
            if ( (cnt4 + 1 <= n / 2 && cnt7 <= n / 2) || (cnt4 <= n / 2 && cnt7 + 1 <= n / 2) ) {
                max_same_pos = i - 1;
            } 
            break;
        } else if (s[i] == '4') {
            cnt4++;
            if (cnt4 - 1 <= n / 2 && cnt7 + 1 <= n / 2) {
                max_same_pos = i - 1;
            } else {
                if (cnt4 <= n / 2 && cnt7 <= n / 2) {
                    continue;
                } else {
                    break;
                }
            }
        } else if (s[i] < '7') {
            if (cnt4 <= n / 2 && cnt7 + 1 <= n / 2) {
                max_same_pos = i - 1;
            }
            break;
        } else if (s[i] == '7') {
            cnt7++;
            if (cnt4 <= n / 2 && cnt7 <= n / 2) {
                continue;
            } else {
                break;
            }
        } else {
            break;
        }
    }
    if (max_same_pos == -2) {
        for (int i = 0; i < (n + 2) / 2; i++) {
            cout << "4";
        }
        for (int i = 0; i < (n + 2) / 2; i++) {
            cout << "7";
        }
    } else {
        int cnt4 = 0, cnt7 = 0;
        for (int i = 0; i <= max_same_pos; i++) {
            cout << s[i];
            if (s[i] == '4') {
                cnt4++;
            } else {
                assert(s[i] == '7');
                cnt7++;
            }
        }
        int diff_pos = max_same_pos + 1;
        if (s[diff_pos] < '4') {
            if (cnt4 + 1 <= n / 2 && cnt7 <= n / 2) {
                cnt4++;
                cout << "4";
            } else {
                cnt7++;
                cout << "7";
            }
        } else if (s[diff_pos] == '4') {
            assert(cnt7 + 1 <= n / 2 && cnt4 <= n / 2);
            cnt7++;
            cout << "7";
        } else if (s[diff_pos] < '7') {
            assert(cnt7 + 1 <= n / 2 && cnt4 <= n / 2);
            cnt7++;
            cout << "7";
        } else {
            assert(0 == 1);
        }
        while (cnt4 < n / 2) {
            cout << "4";
            cnt4++;
        }
        while (cnt7 < n / 2) {
            cout << "7";
            cnt7++;
        }
    }
}
