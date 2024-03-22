/*
    1、利用c[i] = min(x, 2 * c[i - 1]), 使得单价非递增，最低单价在最后
    2、转换L为二进制表示
    3、贪心策略：总是买剩余可买的单价最低的柠檬水（当前c数组前缀的最后一个元素） 
                且 尽可能多得买。每一步都有两个分支：
                    把当前元素多买一个超过L，直接结束；
                    只买不超过剩余L的后一个元素，给将来单价更高的柠檬水留下机会
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <utility>
#include <complex>
#include <functional>
#define ff first
#define ss second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int INF=1e9+250;
LL mod=1e9+7;
const int N=1e5+10;
using PII = pair<int, int>;
int t;

int n, l, c[32], x;

                 
LL help(LL l) {
    LL res = 4e18;
    LL sum = 0;
    LL L = l;

    for (int i = n - 1; i >= 0; i--) {
        // cout << i << '\n';
        if ((1 << i) > L) { 
            res = min(res, (LL)c[i + 1]);
        } else {
            int copy = l / (1 << i);
            sum += copy * 1LL * c[i + 1];
            l -= copy * 1LL * (1 << i);
            res = min(res, sum + c[i + 1]);
        }
        // cout << res << '\n';
    }
    res = min(res, sum);
    //cout << res << '\n';
    return res;
}

void sol()
{
    cin >> n >> l;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (i > 1) c[i] = min(x, 2 * c[i - 1]);
        else c[i] = x;
    }
    LL p1 = help(l);

    cout << p1 << '\n';
    
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    
    //cin >> t;
    t = 1;
    while (t--) sol();
    return 0;
}
