/*
答案显然一定存在，只要补 0 就行
b = 300，则至少是 33 位数
考虑构造前 i 个数，使得第 i 个数最小
则前 i + 1 个数，使得第 i + 1 个数最小时，当然也是希望第 i 个数越小越好
所以可以考虑从左往右贪心搞
第一个数显然是贪心拆，然后把数码小的放到高位
第二个数需要比第一个数大，在此基础上要尽可能小，如何保证？
让第 2 个数的前 cnt 位和第 1 个数一样大
然后 cnt + 1 位第 2 个数严格大于第 1 个数
再后边的就是将剩余的和贪心拆，拆的位数不够就补 0
我们从相同前缀长的开始枚举，这样遇到合法的就可以直接 break 掉了
倘若前面实在没法让前缀相同，就只能多一些位了
*/

int n, b[N];
string res[N];

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    while (b[1] > 0) {
        if (b[1] >= 10) {
            res[1] += "9";
            b[1] -= 9;
        }  else {
            res[1] += char('0' + b[1]);
            b[1] = 0;
        }
    }

    reverse(res[1].begin(), res[1].end());

    for (int i = 2; i <= n; i++) {
        bool ok = false;
        for (int diff_pos = res[i - 1].size() - 1; diff_pos >= 0 && !ok; diff_pos--) {
            if (res[i - 1][diff_pos] == '9') {
                continue;
            }
            
            int left_sum = b[i];
            for (int j = 0; j < diff_pos; j++) {
                left_sum -= res[i - 1][j] - '0';
            }
            
            for (int cur_val = res[i - 1][diff_pos] - '0' + 1; cur_val <= 9 && cur_val <= left_sum; cur_val++) {
                int cur_sum = left_sum - cur_val;
                vector<int> nums;
                while (cur_sum > 0) {
                    if (cur_sum >= 10) {
                        nums.push_back(9);
                        cur_sum -= 9;
                    } else {
                        nums.push_back(cur_sum);
                        cur_sum = 0;
                    }
                }
                int len = res[i - 1].size() - 1 - diff_pos;
                if (nums.size() <= len) {
                    ok = true;
                    res[i] = res[i - 1].substr(0, diff_pos);
                    res[i] += char(cur_val + '0');
                    for (int zero_cnt = 0; zero_cnt < len - nums.size(); zero_cnt++) {
                        res[i] += "0";
                    }
                    for (int k = nums.size() - 1; k >= 0; k--) {
                        res[i] += char('0' + nums[k]);
                    }
                    break;
                }
            }
        }

        if (!ok) {
            int cur_sum = b[i];
            vector<int> nums;
            while (cur_sum > 0) {
                if (cur_sum >= 10) {
                    nums.push_back(9);
                    cur_sum -= 9;
                } else {
                    nums.push_back(cur_sum);
                    cur_sum = 0;
                }
            }
            if (nums.size() > res[i - 1].size()) {
                for (int k = nums.size() - 1; k >= 0; k--) {
                    res[i] += char('0' + nums[k]);
                }
                continue;
            }

            // 强行拆出来 1 个 1 之后再重新拆分补 0
            cur_sum = b[i] - 1;
            nums.clear();
            while (cur_sum > 0) {
                if (cur_sum >= 10) {
                    nums.push_back(9);
                    cur_sum -= 9;
                } else {
                    nums.push_back(cur_sum);
                    cur_sum = 0;
                }
            }
            while (nums.size() < res[i - 1].size()) {
                nums.push_back(0);
            }
            nums.push_back(1);
            for (int k = nums.size() - 1; k >= 0; k--) {
                res[i] += char('0' + nums[k]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << res[i] << "\n";
    }
}   
