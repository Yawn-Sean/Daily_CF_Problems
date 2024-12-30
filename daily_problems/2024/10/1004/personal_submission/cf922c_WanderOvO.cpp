/*
n <= k，则肯定有相等的，No
羊神提示：
n % 1 = 0, n % 2 != n % 1，故 n % 2 只能是 1，同理 n % 3 只能是 2...
n % i = i - 1
所以 (n + 1) % i == 0 对所有 1 <= i <= k 成立
所以 (n + 1) 能整除所有的 1 <= i <= k，这看起来在 k 比较大时很困难
(n + 1) 需要是 lcm(1, 2, ... k) 的倍数
*/

LL n, k;

void solve1() {
    cin >> n >> k;
    for (LL i = 1; i <= k; i++) {
        if ( (n + 1) % i != 0 ) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}    
