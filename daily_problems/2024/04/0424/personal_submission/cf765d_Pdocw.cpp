#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, a[100005], mp[100005], f[100005];
int main()
{
    scanf("%d", &n);
    int idx = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] == i)
        {
            mp[i] = ++idx;
            f[idx] = i;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!mp[a[i]])
        {
            puts("-1");
            return 0;
        }
    }
    printf("%d\n", idx);
    for (int i = 1; i <= n; i++)
        printf("%d%c", mp[a[i]], " \n"[i == idx]);
    for (int i = 1; i <= idx; i++)
        printf("%d%c", f[i], " \n"[i == idx]);
    return 0;
}
