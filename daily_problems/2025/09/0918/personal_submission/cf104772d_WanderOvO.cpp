/*
d = 1 时，随便输出啥都可以
d > 1 时，相当于构造一个数组 a，使得
(a[0] + ... + a[n]) % d == 0
(a[0] + a[1] * 10 + ... + a[n] * 10^n) % d == 0
注意到 n 的限制很宽松，为 1e6
能否预处理出来所有的 10^i % d？
10^i % d 是有循环的，我们把循环周期找出来，每个周期拿同一个位置的，拿 d 个周期
对于拿出来的这些位置，a[i] = 1，其他的 a[i] = 0，则构造好了
*/

int d;
map<int, int> mod_to_time;
vector<int> nums;

void meibao() {
    cin >> d;
    if (d == 1) {
        cout << "1\n";
        return;
    }

    int mod = 1;
    int period = 0;
    mod_to_time[mod] = 0;
    for (int i = 1; ; i++) {
        mod *= 10;
        mod %= d;
        if (mod_to_time.count(mod)) {
            period = i - mod_to_time[mod];
            break;
        }
        mod_to_time[mod] = i;
    }

    int cnt = 0;
    assert(period != 0);
    int st = 0;
    for (int i = 0; cnt < d; i++) {
        if (i < mod_to_time[mod]) {
            nums.push_back(0);
        } else {
            if (st % period == 0) {
                cnt++;
                nums.push_back(1);
            } else {
                nums.push_back(0);
            }
            st++;
        }
    }
    reverse(nums.begin(), nums.end());
    assert(nums.size() <= 1000000);
    for (auto v : nums) {
        cout << v;
    }
} 
