#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1000005;
const LL P1 = 131, P2 = 13331; // 双哈希的两个基数
const LL mod1 = 1e9+7, mod2 = 998244353; // 双哈希的两个模数

LL f[N], p1[N], p2[N], h1[N], h2[N]; // p1和p2分别表示双哈希的基数幂次，h1和h2表示哈希值

int main(){
    int n, m;
    cin >> n >> m; 

    // 计算阶乘
    f[1] = 1;
    for(int i = 2; i < N; i++) f[i] = f[i-1] * i % mod1;  // 阶乘 % mod1
    
    // 计算两个不同基数的幂次
    p1[0] = p2[0] = 1;
    for(int i = 1; i <= n; i++) {
        p1[i] = p1[i-1] * P1 % mod1;
        p2[i] = p2[i-1] * P2 % mod2;
    }

    // 输入并计算双哈希值
    for(int i = 1; i <= n; i++) {
        int c, t = 1;
        cin >> c;
        for(int j = 1; j <= c; j++) {
            cin >> t;
            h1[t] = (h1[t] + p1[i]) % mod1;  // 使用 P1 和 mod1 计算第一个哈希值
            h2[t] = (h2[t] + p2[i]) % mod2;  // 使用 P2 和 mod2 计算第二个哈希值
        }
    }

    // 使用双哈希值组合进行排序
    vector<pair<LL, LL>> hashes;  // 存储两个哈希值的组合
    for(int i = 1; i <= m; i++) {
        hashes.push_back({h1[i], h2[i]});
    }
    sort(hashes.begin(), hashes.end());  // 排序组合的哈希值

    // 计算结果
    LL ans = 1, c = 1;
    pair<LL, LL> qh = {-1, -1};  // 初始化上一个哈希值对
    for(int i = 0; i <= m; i++) {
        if(i < m && hashes[i] == qh) {
            c++;
        } else {
            ans = (ans * f[c]) % mod1;  // 将相同哈希值组合的方案数乘入结果
            c = 1;
            if(i < m) qh = hashes[i];
        }
    }

    cout << ans;
    return 0;
}
