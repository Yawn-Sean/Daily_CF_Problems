/*
现在看第 i 个数，只需要把不确定的位二分即可
如果首位为 ?，则二分下限为 1... 否则为 0，二分上限一直都是全 9
*/

int T;
int n;
string s;
LL a[N];

LL fill_question(LL ans) {
    int question_cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '?') {
            question_cnt++;
        }
    }

    stack<int> nums;
    while (ans > 0) {
        nums.push(ans % 10);
        ans /= 10;
    }
    while (nums.size() < question_cnt) {
        nums.push(0);
    }

    assert(nums.size() == question_cnt);

    LL val = 0;
    for (int j = 0; j < s.size(); j++) {
        if (s[j] == '?') {
            val = 10 * val + nums.top();
            nums.pop();
        } else {
            val = 10 * val + s[j] - '0';
        }
    }
    return val;
}

bool check(LL ans, int id) {
    LL val = fill_question(ans);
    if (id == 1) {
        return true;
    }
    return val > a[id - 1];
}

void solve1() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        int question_cnt = 0;
        bool first_one = false;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == '?') {
                question_cnt++;
                if (j == 0) {
                    first_one = true;
                }
            } 
        }
        if (question_cnt == 0) {
            LL val = 0;
            for (int j = 0; j < s.size(); j++) {
                val = 10 * val + s[j] - '0';
            }
            a[i] = val;
            if (i > 1 && a[i] <= a[i - 1]) {
                cout << "NO\n";
                return;
            }
            continue;
        }
        LL l = (first_one ? pow(10, question_cnt - 1) : 0);
        LL r = pow(10, question_cnt) - 1;
        while (l + 1 < r) {
            LL mid = (l + r) / 2;
            if (check(mid, i)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        LL val = 0;
        for (int j = 0; j < s.size(); j++) {
            val = 10 * val;
            if (s[j] != '?') {
                val += s[j] - '0';
            }
        }
        if (check(l, i)) {
            a[i] = fill_question(l);
        } else if (check(r, i)) {
            a[i] = fill_question(r);
        } else {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
        cout << a[i] << "\n";
    }
}     