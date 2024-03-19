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
const int N=2e5+10;
using PII = pair<int, int>; 
int n, q, m;
int a[N];

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> n >> q >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<array<int, 3>> qs(q + 1);
    for (int i = 1; i <= q; i++)
        cin >> qs[i][0] >> qs[i][1] >> qs[i][2];
    
    vector<int> idx(m + 1);
    for (int i = 1; i <= m; i++)
        cin >> idx[i];

    for (int i = q; i >= 1; i--) {
        int t = qs[i][0], l = qs[i][1], r = qs[i][2];
        //cout << t << " " << l << " " << r << '\n';
        if (t == 1) {   //循环右移
            for (int i = 1; i <= m; i++) {
                if (idx[i] >= l && idx[i] <= r) {
                    if (idx[i] == l) idx[i] = r;
                    else idx[i]--;
                }
            }
        } else {    //翻转
            for (int i = 1; i <= m; i++) {
                if (idx[i] >= l && idx[i] <= r) {
                    idx[i] = r - (idx[i] - l);
                }            
            }
        }
    }
    for (int i = 1; i <= m; i++)
        cout << a[idx[i]] << " ";
    cout << '\n';
    return 0;
}
