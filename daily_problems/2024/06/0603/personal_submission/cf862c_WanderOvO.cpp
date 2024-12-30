
/*
x 有 cnt 个为 1 的二进制位，需要拆成互不相同的非负数，且每个数字不超过 1e6
- 若 n <= cnt，则直接拆位即可，最后一个数把剩下所有的 1 都用上
- 若 n > cnt，则先凑出来这个数，然后考虑剩下的数异或为 0
  不妨直接第一个数为 x，剩下的 n - 1 个数考虑怎么异或变成 0
  2^i 到 2^(i + 1) - 1 异或起来为 0，这是 2^i 个数
  
其实可以随机生成 n - 1 个数，然后第 n 个数就确定了
*/

int T;
int n, x;

void solve1() {
    cin >> n >> x;
    if (n == 1) {
        cout << "YES\n";
        cout << x << "\n";
        return;
    } else if (n == 2) {
        if (x == 0) {
            cout << "NO\n";
            return;
        } else {
            cout << "YES\n";
            cout << "0 " << x << "\n";
            return;
        }
    }

    random_device rd;
    mt19937 engine(rd());
    int mod = 1e6;
    set<int> s;
    int last_val = 0;
    while (true) {
        s.clear();
        last_val = 0;
        for (int i = 0; i < n - 1; i++) {
            int val = engine() % mod;
            if (!s.count(val)) {
                s.insert(val);
                last_val ^= val;
            } else {
                i--;
            }
        }
        last_val = last_val ^ x;
        if (!s.count(last_val)) {
            s.insert(last_val);
            break;
        }
    }
    cout << "YES\n";
    for (auto val : s) {
        cout << val << " ";
    }
}             