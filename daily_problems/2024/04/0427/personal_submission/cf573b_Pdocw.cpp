#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, a[100005];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    a[0] = a[n + 1] = 0;
    for (int i = 1; i <= n; i++)
    {
        a[i] = min(a[i], a[i - 1] + 1);
    }
    for (int i = n; i >= 1; i--)
    {
        a[i] = min(a[i], a[i + 1] + 1);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, a[i]);
    }
    printf("%d\n", ans);
    return 0;
}
