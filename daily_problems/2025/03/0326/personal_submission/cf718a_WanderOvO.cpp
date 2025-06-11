/*
肯定是选 >= 5 的位进行 rounding，能 rounding 至多 t 次
会产生一些连锁反应
1.449 -> 1.45 -> 1.5 -> 2
1.499 -> 1.5 -> 2
456789
能否贪心只 rounding 位数最高的？不贪心的话可能更大吗？
- 只 rounding 位数最高的，假设其下标为 pos，会把 pos - 1 位给 + 1
- 挨个 ronuding，等 rounding 到 pos 位时，我们断言 pos 位不变或者 + 1
  如果不变则 rounding 后 pos - 1 位 + 1
  如果 + 1 了，假如 pos 位还能 rounding，则 pos - 1 位 + 1
  如果 pos 位不能 rounding 了，则 pos 位一定是 0，pos - 1 位也进位 + 1 了
最后整数部分如果进位多出来一位也没关系，因为只会多一位，那一位存两位数输出出来也是对的
*/

string s;
int n, t;
vector<int> nums;

void my_round(int pos) {
    assert(pos - 1 >= 0);
    nums[pos - 1]++;
    for (int i = pos - 1; i > 0; i--) {
        if (nums[i] >= 10) {
            nums[i - 1]++;
            nums[i] %= 10;
        } else {
            break;
        }
    }
}

void meibao() {
    cin >> n >> t >> s;
    int decimal_point_pos = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '.') {
            decimal_point_pos = i;
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        if (isdigit(s[i])) {
            nums.push_back(s[i] - '0');
        }
    }

    int pos = -1;
    // 从 decimal_point_pos 开始，都是小数部分
    for (int i = decimal_point_pos; i < nums.size(); i++) {
        if (nums[i] >= 5) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        cout << s << "\n";
    } else {
        // 从 last_round_pos 开始，后面的位都没了，所以只需要输出到 last_round_pos - 1 位
        int last_round_pos = pos;
        my_round(pos);
        t--;
        for (int i = pos - 1; i >= decimal_point_pos && t > 0; i--) {
            if (nums[i] >= 5) {
                my_round(i);
                last_round_pos = i;
                t--;
            }
        }
        for (int i = 0; i < decimal_point_pos; i++) {
            cout << nums[i];
        }
        if (last_round_pos > decimal_point_pos) {
            cout << ".";
            for (int i = decimal_point_pos; i < last_round_pos; i++) {
                cout << nums[i];
            }
        }
    }
}   
