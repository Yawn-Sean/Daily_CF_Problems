#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define u64 unsigned long long
#define debug(x) cout<<x<<endl;
#define endl "\n"
#define pii pair<int,int>
const int N=3e5+9;

int n,a[N*2];
i64 ans;
pii rmp[20][N*2];//st表，用于区间最大值查询
int nxt[N*2][20];//倍增数组，从i跳2^p的位置

//查询l,r中i+a[i]的最大值的索引（修正p的计算）
int query(int l, int r) 
{
    if (l > r) return l;
    int len = r - l + 1;
    int p = 31 - __builtin_clz(len);
    return max(rmp[p][l], rmp[p][r - (1 << p) + 1]).second;
}

int main() 
{
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[n - i];

    for(int i=0;i<n;++i) a[n + i] = a[i];

    // 初始化st表：rmp[0][i]存储(i+a[i], i)
    for(int i=0;i<2*n;++i) rmp[0][i] = pii(i + a[i], i);

    // 构建st表
    for(int p=1, len=2; p<20; p++, len*=2) 
    {
        for(int i=0; i + len - 1 < 2*n; ++i) 
        { 
            rmp[p][i] = max(rmp[p-1][i], rmp[p-1][i + len/2]);
        }
    }

    for(int p=0; p<20; ++p) nxt[2*n - 1][p] = 2*n - 1;

    // 预处理倍增数组（从后往前计算）
    for(int i=2*n - 2; i>=0; --i) 
    {
        int r = min(2*n - 1, i + a[i]);
        nxt[i][0] = query(i + 1, r);
        // 递推计算2^p步的位置
        for(int p=1; p<20; ++p) {
            nxt[i][p] = nxt[nxt[i][p-1]][p-1];
        }
    }

    for(int i=0; i<n; ++i) 
    {
        // 特殊情况：一步就能从i传到末尾（覆盖长度n-1）
        if(a[i] >= n - 1) 
        {
            ans++;
            continue;
        }

        int now = i; // 当前位置
        i64 steps = 0; // 记录当前i的总步数
        for(int p=19; p>=0; --p) 
        {
            int t = nxt[now][p]; 
            if(t + a[t] - i < n - 1) 
            {
                steps += (1 << p);
                now = t;
            }
        }
        steps += 2;
        ans += steps; // 累加当前i的步数到总答案
    }

    cout << ans << endl; // 输出总结果
    return 0;
}
