#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
using i128 = __int128;
using ull = unsigned long long;
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define pqi priority_queue<int> // 优先队列

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
// #define int long long
int n, x, mask, a, b, b1, b2, b3;
char op[10];
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s%d", op, &x);
        if (op[0] == '|')
        {
            for (int i = 0; i < 10; i++)
                if (x & (1 << i))
                {
                    mask |= (1 << i);
                    a |= (1 << i);
                }
        }
        else if (op[0] == '&')
        {
            for (int i = 0; i < 10; i++)
                if ((x & (1 << i)) == 0)
                {
                    mask |= (1 << i);
                    a &= (1 << 10) - 1 - (1 << i);
                }
        }
        else if (op[0] == '^')
        {
            for (int i = 0; i < 10; i++)
                if ((x & (1 << i)))
                {
                    if (mask & (1 << i))
                        a ^= (1 << i);
                    b ^= (1 << i);
                }
        }
    }
    puts("3");
    b1 = 1023;
    for (int i = 0; i < 10; i++)
        if (mask & (1 << i))
        {
            if (a & (1 << i))
                b2 += (1 << i);
            else
                b1 -= (1 << i);
        }
        else if (b & (1 << i))
            b3 += (1 << i);
    printf("& %d\n| %d\n^ %d\n", b1, b2, b3);
}
