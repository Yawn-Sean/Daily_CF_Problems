/*
枚举严格小的数从哪一位开始不一样
然后枚举这一位填什么(也是从大到小填)，之后的位就可以随便填了，尽可能大即可
把前缀的数字个数统计一下，如果是奇数个，则需要补一下，剩下的都贪心填 9 即可，但是 9 的个数也必须保证是偶数个
*/

int T;
int cnt[10] = {0};
string s;

void solve1() {
    cin >> s;
    int n = s.size();
    memset(cnt, 0, sizeof cnt);
    for (int i = 0; i < n; i++) {
        cnt[s[i] - '0']++;
    }
    for (int i = n - 1; i >= 0; i--) {
        cnt[s[i] - '0']--;
        for (int j = s[i] - '0' - 1; j >= (i == 0 ? 1 : 0); j--) {
            cnt[j]++;
            
            vector<int> odd;
            for (int k = 9; k >= 0; k--) {
                if (cnt[k] % 2) {
                    odd.pb(k);
                }
            }
            if (n - 1 - i >= odd.size()) {
                int free_cnt = n - 1 - i - odd.size();
                if (free_cnt % 2 != 0) continue;
                for (int k = 0; k < i; k++) {
                    cout << s[k];
                }
                cout << j;
                for (int k = 0; k < free_cnt; k++) {
                    cout << "9";
                }
                for (int k = 0; k < odd.size(); k++) {
                    cout << odd[k];
                }
                cout << "\n";
                return;
            }
            cnt[j]--;
        }
    }
    
    // 单独处理第一位填 0 的情况
    int len = n - 1;
    if ((n - 1) % 2 != 0) {
        len--;
    }
    for (int i = 0; i < len; i++) {
        cout << "9";
    }
    cout << "\n";
}          