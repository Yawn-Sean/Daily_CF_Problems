/*
单独考虑一个位，看这个位是 0 或者 1 的时候，得到的结果是什么
这样可以得到 10 个位各自是 0 或者 1 的时候的“真值表”
- 0->0, 1->1，用 and 1
- 0->0, 1->0，用 and 0
- 0->1, 1->1，用 or 1
- 0->1, 1->0，用 xor 1
*/

int T;
int n;
pair<char, int> op[N];

void solve1() {
    cin >> n; 
    for (int i = 1; i <= n; i++) {
        cin >> op[i].x >> op[i].y;
    }
    int and_val = 1023, or_val = 0, xor_val = 0;
    for (int i = 0; i < 10; i++) {
        int res0 = 0, res1 = 1;
        for (int j = 1; j <= n; j++) {
            int val = ((op[j].y >> i) & 1);
            if (op[j].x == '|') {
                res0 |= val;
                res1 |= val;
            } else if (op[j].x == '&') {
                res0 &= val;
                res1 &= val;
            } else {
                res0 ^= val;
                res1 ^= val;
            }
        }
        if (res0 == 0 && res1 == 1) {
            and_val |= (1 << i);
        } else if (res0 == 0 && res1 == 0) {
            and_val &= (~(1 << i));
        } else if (res0 == 1 && res1 == 1) {
            or_val |= (1 << i);
        } else if (res0 == 1 && res1 == 0) {
            xor_val |= (1 << i);
        }
    }
    cout << "3\n";
    cout << "& " << and_val << "\n";
    cout << "| " << or_val << "\n";
    cout << "^ " << xor_val << "\n"; 
}                                                                                                                  
