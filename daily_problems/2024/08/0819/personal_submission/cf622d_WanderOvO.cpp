/*
sum( (n - i) * |d[i] + i - n| )
(n - i) 是取遍 0 到 n - 1 的
n 的位置是无所谓的，因为不贡献到答案中
让 d[i] + i 和 n 尽可能接近
d[i] 能都等于 n - i 吗？还真行
1 3 3 1 2 4 2 4
3 * 0 + 1 * 0 + 2 * 0 + 0 * 2 = 0
1 3 5 3 1 2 4 4 2 5  
1 3 5 5 3 1 2 4 6 4 2 6
发现只要分奇偶疯狂构造回文即可
*/

int T;
int n;

void solve1() {
    cin >> n;
    if (n % 2 == 0) {
        for (int i = 1; i <= n; i += 2) {
            cout << i << " ";
        }
        for (int i = n - 1; i > 0; i -= 2) {
            cout << i << " ";
        }
        for (int i = 2; i <= n; i += 2) {
            cout << i << " ";
        }
        for (int i = n - 2; i >= 2; i -= 2) {
            cout << i << " ";
        }
        cout << n << "\n";
    } else {
        for (int i = 1; i <= n; i += 2) {
            cout << i << " ";
        }
        for (int i = n - 2; i > 0; i -= 2) {
            cout << i << " ";
        }
        for (int i = 2; i <= n - 1; i += 2) {
            cout << i << " ";
        }
        for (int i = n - 1; i >= 2; i -= 2) {
            cout << i << " ";
        }
        cout << n << "\n";
    }
}         
