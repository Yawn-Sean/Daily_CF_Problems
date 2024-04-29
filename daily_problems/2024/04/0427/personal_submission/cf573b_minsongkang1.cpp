#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e5 +7;
int n;
int a[N], sum[N];
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i ++)
    {
        sum[i] = min(sum[i - 1] + 1,  a[i]);
    }
    for(int i = n; i >= 0; i --)
    {
        sum[i] = min(sum[i + 1] + 1,  sum[i]);
    }
    int res = 0;
    for(int i = 1; i <= n; i ++) res = max(res, sum[i]);
    cout << res;
    return 0;
}
