/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

struct Person
{
    int num, time, id;
} in[110];
bool operator<(Person a, Person b)
{
    if (a.num == b.num) return a.time < b.time;
    return a.num > b.num;
}
int t[110], id[110], r[110];

void solve()
{
    int n, k, m, a;
    std::cin >> n >> k >> m >> a;
    for (int i = 1; i <= a; i++)
    {
        int g;
        std::cin >> g;
        in[g].num++;
        in[g].time = i;
    }
    for (int i = 1; i <= n; i++) 
        in[i].id = i;
    std::sort(in + 1, in + n + 1);
    for (int i = 1; i <= n; i++)
    {
        t[i] = in[i].num;
        id[i] = in[i].id;
    }
    for (int i = 1; i <= k; i++)
    {
        if (t[i] == 0)
        {
            if (m == a)
                r[id[i]] = 3;
            else
                r[id[i]] = 2;
        }
        else
        {
            if (n == k)
                r[id[i]] = 1;
            else
            {
                int sum = 0;
                for (int j = i + 1; j <= k + 1; j++)
                {
                    sum += t[i] - t[j] + 1;
                }
                if (m - a >= sum)
                    r[id[i]] = 2;
                else
                    r[id[i]] = 1;
            }
        }
    }
    for (int i = k + 1; i <= n; i++)
    {
        if (m - a > t[k] - t[i])
            r[id[i]] = 2;
        else
            r[id[i]] = 3;
    }
    for (int i = 1; i <= n; i++) 
        std::cout << r[i] << " ";
    std::cout << "\n";
}

signed main()
{
    fastio;
    
    solve();
    
    return 0;
}
 		    							     			   		 		
