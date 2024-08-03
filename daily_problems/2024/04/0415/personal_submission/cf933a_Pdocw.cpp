/*------------------------------------------------------------------------------
 * @file    CF933A_PDOCW.CPP
 * @author  Pdocw
 * @date    2024/04/15 19:22:35
 * -----------------------------------------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n;
    scanf("%d", &n);
    vector<int> nums(n);
    for (int &x : nums)
        scanf("%d", &x);
    int dp1 = 0, dp12 = 0, dp121 = 0, dp1212 = 0;
    for (auto x : nums)
    {
        if (x == 1)
        {
            dp1 += 1;
            dp121 += 1;
        }
        else
        {
            dp12 += 1;
            dp1212 += 1;
        }
        dp12 = max(dp12, dp1);
        dp121 = max(dp121, dp12);
        dp1212 = max(dp1212, dp121);
    }
    printf("%d\n", dp1212);
    return 0;
}
