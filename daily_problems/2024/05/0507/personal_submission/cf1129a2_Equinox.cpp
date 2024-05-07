// 车站有多少颗糖，火车就要经过站点多少次
// 最后一次经过时，我们应该送的是目标站点顺时针最接近该站点的糖
#include <bits/stdc++.h>
const int N = 5010, M = 20010;
int n, m;
int sz[N], mi[N];
int main(){
    std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);

    std::cin >> n >> m;
    std::memset(mi, 0x3f, sizeof mi);
    for(int i = 1, a, b; i <= m; i ++) {
        std::cin >> a >> b;
        sz[a] ++;
        mi[a] = std::min(mi[a], (b + n - a) % n);
    }
    for(int i = 1; i <= n; i++){
        int res = 0;
        for(int j = 1; j <= n; j ++){
            if(!sz[j]) continue;
            res = std::max(res, (sz[j] - 1) * n + mi[j] + (j + n - i) % n);
        }
        std::cout << res << ' ';
    }

    return 0;
}