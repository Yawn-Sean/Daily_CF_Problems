/*------------------------------------------------------------------------------
 * @file    CF1013C_PDOCW.CPP
 * @author  Pdocw
 * @date    2024/04/20 21:09:22
 * -----------------------------------------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    long long a, b;
    scanf("%lld%lld", &a, &b);
    int n = (sqrt(8 * (a + b) + 1) - 1) / 2;
    vector<int> ans1, ans2;
    for (int i = n; i >= 1; i--)
    {
        if (a >= i)
            ans1.push_back(i), a -= i;
        else
            ans2.push_back(i);
    }
    printf("%d\n", ans1.size());
    for (int i = 0; i < ans1.size(); i++)
        printf("%d%c", ans1[i], i == ans1.size() - 1 ? '\n' : ' ');
    printf("%d\n", ans2.size());
    for (int i = 0; i < ans2.size(); i++)
        printf("%d%c", ans2[i], i == ans2.size() - 1 ? '\n' : ' ');
    return 0;
}
