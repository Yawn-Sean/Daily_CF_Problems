/*
好数有多少种？
似乎不到 1e6 个，我们可以直接枚举这样的数，然后两数之和秒之
*/ 

int n;
set<int> vals;

void meibao() {
    cin >> n;
    for (int i = 0; i < 10; i++) {
        vals.insert(i);
    }
    int mx = 1e9;
    vals.insert(mx);

    auto to_value = [&] (vector<int> &nums) -> int {
        int val = 0;
        for (auto v : nums) {
            val = 10 * val + v;
        }
        return val;
    };

    for (int len = 2; len < 10; len++) {
        // 1...1 到 9...9
        for (int i = 1; i <= 9; i++) {
            int val = 0;
            for (int j = 0; j < len; j++) {
                val = 10 * val + i;
            }
            vals.insert(val);
        }

        // 1...12...2
        for (int i = 0; i <= 9; i++) {
            for (int j = i + 1; j <= 9; j++) {
                for (int cnt = 1; cnt < len; cnt++) {
                    vector<int> nums;
                    for (int k = 0; k < cnt; k++) {
                        nums.push_back(i);
                    }
                    for (int k = 0; k < len - cnt; k++) {
                        nums.push_back(j);
                    }
                    do {
                        vals.insert(to_value(nums));
                    } while (next_permutation(nums.begin(), nums.end()));
                }
            }
        }
    }
    
    int res = 0;
    for (auto val : vals) {
        if (val <= n && val <= n - val) {
            if (vals.count(n - val)) {
                res++;
            }
        } else {
            break;
        }
    }
    cout << res << "\n";
}   
