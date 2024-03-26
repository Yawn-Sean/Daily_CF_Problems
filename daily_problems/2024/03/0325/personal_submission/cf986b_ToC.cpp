/*
    1、任意无重复元素序列，交换任意两元素，逆序对数量的奇偶性改变
    2、3n和7n+1的奇偶性不同
    3、根据n的奇偶性和最终序列里逆序对数量的奇偶性，判断是谁执行了操作
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
int n, t;
int a[N], fen[N];
LL cnt;

void add(int v, int p) {
    for (; p <= n; p += p & -p) {
        fen[p] += v;
    }
}

int query(int p) {
    int res = 0;
    while (p) {
        res += fen[p];
        p -= p & -p;
    }
    return res;
}

void sol()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        cnt += (query(n) - query(a[i] - 1));
        add(1, a[i]);
    }
    //cout << cnt << '\n';
    if (n & 1) {
        if (cnt & 1) cout << "Petr\n";
        else cout << "Um_nik\n";
    } else {
        if (cnt & 1) cout << "Um_nik\n";
        else cout << "Petr\n";
    }
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
