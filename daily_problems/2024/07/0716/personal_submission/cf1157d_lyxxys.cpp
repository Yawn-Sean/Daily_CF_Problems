#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 3e5+3, mod = 1e9 + 7, inf = 1e9;

void solve(){
    int n, k;
    cin >> n >> k;
    /*
        可构造数字之和相当于有一个来自以1为公差的、首项为1 的 等差数列的下界，根据数据范围，一定没有上界
        先整体加k至不能再加，既以后最多再加k-1，再从后往前检查可不可以一个个调整至 和为n
        如果第一个数是1，那么后面的数字至少能加k-2次，有可能不满足条件
        如果第一个数不是1，那么后面的数字至少能加k-1次，一定能加k-1
    */
    vector <int> ans(k+1);
    ll sum = 0;
    for (int i = 1; i <= k; ++ i){
        ans[i] = i;
        sum += i;
    }
    if (sum > n){
        cout << "NO" << "\n";
        return;
    }

    int t = (n-sum)/k, rest = (n-sum)%k;
    for (int i = 1; i <= k; ++ i){
        ans[i] += t;
    }

    {
        int i = k;
        while (rest && ans[i] < 2*ans[i-1]){
            int v = min(rest, 2*ans[i-1]-ans[i]);
            ans[i] += v;
            rest -= v;
            -- i;
        }
        if (rest){
            cout << "NO" << "\n";
        } else {
            cout << "YES" << "\n";
            for (int i = 1; i <= k; ++ i){
                cout << ans[i] << "\n "[i < k];
            }
        }
    }
}
