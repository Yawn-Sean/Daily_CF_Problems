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
LL n, b[N], l, r;
LL f1[N], f2[N];

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> n;
    cin >> l;
    for (int i = 1; i < n; i++) {
        cin >> r;
        b[i] = abs(r - l);
        l = r;
    }

    //f1[i]是以+b[i]结尾的,数组b中的，正/负交替序列的最大和
    //f2[i]是以-b[i]结尾的,数组b中的，正/负交替序列的最大和
    
    f1[1] = b[1];
    f2[1] = 0;
    LL res = b[1];
    for (int i = 2; i < n; i++) {
        f1[i] = max(0LL, f2[i - 1]) + b[i]; 
        f2[i] = f1[i - 1] - b[i];   
        res = max(res, max(f1[i], f2[i]));
    }
    printf("%lld\n", res);
    return 0;
}
