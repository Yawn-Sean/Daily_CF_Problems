/*
    1、最大clique是图中最长链
    2、图中最长链是数组a的最长整除子序列（def: 子序列相邻两项中后者是前者的倍数）
    3、dp计算a[i]开头的每个整除子序列的长度
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
const int N=1e6+10;
using PII = pair<int, int>;
int t, n, maxv, res;
int a[N], f[N];


void sol()
{
    cin >> n; 
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        f[a[i]] = 1;
    }
    maxv = a[n];
    
    // O(n ^ 2)
    // for (int i = 1; i <= n; i++) {
    //     f[i] = 1;
    //     for (int j = 1; j < i; j++)
    //         if (a[i] % a[j] == 0)
    //             f[i] = max(f[i], f[j] + 1);
    // }
    //cout << *max_element(f + 1, f + n + 1) << '\n';

    //O(n * ln(n))
    for (int i = maxv; i >= 1; i--) {
        if (f[i] == 0) continue;    //不存在以i开头的整除子序列
        f[i] = 1;
        for (int j = i << 1; j <= maxv; j += i)
            f[i] = max(f[i], f[j] + 1);
        res = max(res, f[i]);
    }
    cout << res << endl;
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
