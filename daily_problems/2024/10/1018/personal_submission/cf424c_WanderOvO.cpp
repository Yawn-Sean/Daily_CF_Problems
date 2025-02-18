/*
显然输入的 p 数组意义不大，直接全异或起来就好
关键是看所有的 (i % j) 异或起来怎么样
固定 j，则 i % j 循环从 1 2 ... j-1 0
主要看循环了完整的几轮，然后又单独余下几个
显然循环了完整的 n / j 轮，假如这个数是奇数，则需要把 1 异或到 j - 1 统计到答案中
接下来考虑余下的，有 n % j 个数，从 1 到 n % j 异或起来
因此，只需要预处理 1 到 n 的异或前缀和，然后枚举 j，计算即可
*/

int n;

void meibao() {
    cin >> n;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        int p;
        cin >> p;
        res ^= p;
    }
    vector<int> xor_s(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        xor_s[i] = xor_s[i - 1] ^ i;
    }
    for (int j = 1; j <= n; j++) {
        int cnt = n / j;
        if (cnt % 2) {
            res ^= xor_s[j - 1];
        }
        int r = n % j;
        res ^= xor_s[r];
    }
    cout << res << "\n";
}    
