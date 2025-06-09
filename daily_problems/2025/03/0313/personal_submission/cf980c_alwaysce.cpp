#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    // 贪心取最小 每次组大小<=k就合并到前一个组
    vector<int> color(256), sz(256, 1);
    iota(color.begin(), color.end(), 0);
    
    for (int i = 0; i < n; i++) {
        while (1) {
            int cur = color[p[i]];
            if (cur == 0) {
                break;
            }

            // color[cur] == cur 初始
            int prev = color[cur - 1];
            // 需要新开一个组
            if (sz[cur] + sz[prev] > k) { break; }
            
            // 否则直接往前合并 直到size>k 或者到0
            for (int j = cur; j <= p[i]; j++) {
                color[j] = prev;
            }
            // 
            sz[prev] += sz[cur];
        }
        cout << color[p[i]] << ' ';
    }

    return 0;
}
