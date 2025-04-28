#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }


        /*
            ?1 +1 -> 0 少了一个1

            p(x+n-1)=x+n-1的二进制表示中1的个数

            p(x+1) <= p(x) 说明什么?
            x+1的二进制表示中1的个数 <= x的二进制表示中1的个数
            
            1. p[x+1] <= p[x]+1 不可能一下子多2个1

            ohh x->x+1 假设x末尾有x个1 非末尾有y个1 总共x+y
            +1之后这一连串1都会变成0 -> 1 + y -> y+1
            所以p[i+1]-p[i]=(y+1)-(x+y)=1-x

            p[i]-p[i+1]+1就是i数字末尾1的个数
            这个1前面也必须要0-> p[i]= (前面放剩下的1)|0|trail_cnt个1

            于是得到了一个下界= 0 | ((1<<trail_cnt)-1)
            base+(i-1) =  (1ll << (p[i - 1] + 1))- (1ll << trail_cnt) - 1 ( 11101111)
        */

        i64 res = (1ll << p[0]) - 1;
        for (int i = 1; i < n; i++) {
            int trail_cnt = p[i - 1] - p[i] + 1;
            if (trail_cnt >= 0) {
                res = max(res, (1ll << (p[i - 1] + 1)) - (1ll << trail_cnt) - i);
            }
        }

        bool find = true;
        for (int i = 0; i < n; i++) {
            if (__popcount(res + i) != p[i]) {
                find = false;
                break;
            }
        }

        if (find) {
            cout << res << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
    return 0;
}
