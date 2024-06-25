/*
5_10 https://codeforces.com/problemset/problem/1609/D
数据范围较小，直接暴力并查集
每一个重复的介绍关系我们都可以利用选择两个较大的连通块进行联通
那么答案就是联通之后的连通块的大小减一
*/
#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int N = 1010;
int p[N], sz[N];

int find(int x)
{
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    int n, m;
    cin >> n >> m;

    for(int i = 0; i <= n; i++)
    {
        p[i] = i, sz[i] = 1;
    }

    int buff = 0;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a = find(a), b = find(b);
        if(a != b)
        {
            p[a] = b;
            sz[b] += sz[a];
        }
        else buff++;

        // 将每一个连通块大小插入到set中
        multiset<int> h;
        int k = buff;
        for(int j = 1; j <= n; j++)
        {
            int a = find(j);
            h.insert(sz[a]);
        }

        int sum = 0;
        auto it = h.rbegin();
        sum += *it;
        it++;
        for(; it != h.rend() && k; it++)
        {
            sum += *it;
            k--;
        }
        cout << sum - 1 << endl;
    }

    return 0;
}
