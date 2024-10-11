/*
首先估计一下是几位数
假设是 cnt 位数，则算一下应该是第几个 cnt 位数
*/

int T;
LL n;

void solve1() {
    cin >> n;
    LL tot = 0, base = 9, cnt = 1;
    while (tot < n) {
        if (tot + base * cnt >= n) {
            break;
        }
        tot += base * cnt;
        base *= 10;
        cnt++;
    }
    n -= tot;
    // 答案在第 pos 个 cnt 位数中
    LL pos = (n + cnt - 1) / cnt;
    // 答案是第 pos 个 cnt 位数的第 idx 个数
    LL idx = n - (pos - 1) * cnt;
    LL val = 1;
    for (int i = 1; i < cnt; i++) {
        val *= 10;
    }
    val += pos - 1;
    vector<int> nums;
    while (val > 0) {
        nums.pb(val % 10);
        val /= 10;
    }
    reverse(nums.begin(), nums.end());
    cout << nums[idx - 1] << "\n";
}              
