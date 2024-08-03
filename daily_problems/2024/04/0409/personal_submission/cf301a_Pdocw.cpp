/*------------------------------------------------------------------------------
 * @file    CF301A_PDOCW.CPP
 * @author  Pdocw
 * @date    2024/04/09 20:24:38
 * -----------------------------------------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int sum = 0, min_abs = 1005, neg_cnt = 0;
    for (int i = 0; i < 2 * n - 1; i++)
    {
        cin >> a[i];
        if (abs(a[i]) < min_abs)
            min_abs = abs(a[i]);
        if (a[i] < 0)
            neg_cnt++;
        sum += abs(a[i]);
    }
    if (n % 2 == 0 && neg_cnt % 2)
        cout << sum - 2 * min_abs;
    else
        cout << sum;
    return 0;
}
