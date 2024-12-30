/*
优先放'('
默认'?'为-1预处理后缀和
遍历字符串如果能放'('就放
如果出现没到末尾就 <= 0 说明非法
结果不是0也非法
开始特判长度奇数
*/
void solve() {
    int N;
    std::string s;
    std::cin >> N >> s;
    if (N & 1) {
        std::cout << ":(";
        return;
    }
    std::vector<int> suf(N + 1);
    std::unordered_map<char, int> mp;
    mp['('] = 1, mp[')'] = -1, mp['?'] = -1;
    for (int i = N - 1; ~i; i -- ) 
        suf[i] = suf[i + 1] + mp[s[i]];
    int sum = 0;
    for (int i = 0; i < N; i ++ ) {
        if (s[i] == '?') {
            if (sum + suf[i] < 0) sum ++, s[i] = '(';
            else sum --, s[i] = ')';
        }
        else 
            sum += mp[s[i]];
        if (sum <= 0 && i + 1 < N) {
            std::cout << ":(";
            return;
        }
    }
    if (!sum) std::cout << s;
    else std::cout << ":(";
}   
