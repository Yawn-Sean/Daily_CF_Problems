#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
    --这边的贪心很巧妙--
    1，首先我们要找到b[i]==0的i(从小到大找)-因为小的在前面可能对后面大的数有贡献度，所以我们先创建一个小根堆，把小的先放在新建数组b中
    然后i就已经放进去了vis[i]==1标记一下（这个数别忘记从堆中弹出）
    2，然后我们要找1~j（已进被找的不需要再判断）其中如果 x>=j+k就说明这个加入的数对当前有1的贡献度，所以b[j]--
    如果b[j]==0 那么就说前面的数已经满足他的贡献度了，那就加入小根堆就行了
    
    贪心思想：就是先放入小的数同时这个数的b[i]==0，因为后面没放入b数组的数比当前的数大，那就不会产生贡献度，这边很巧妙的把，之前有贡献度的数，进过
    层层递减刚好考虑到了前面先放到数对后面的数的贡献度
*/
void solve()
{
    int n = 0, m = 0, k = 0;
    string s;
    cin >> n >> k;
    vector<int> a(n + 1, 0), b;
    vector<bool>vis(n+1,0);
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] == 0)
        {
            pq.push(i);
        }
    }
    while (!pq.empty())
    {
        auto x=pq.top();
        pq.pop();
        b.push_back(x);
        vis[x]=1;
        for(int i=1;i<=n;i++){
            if(!vis[i]&&x>=i+k){
                a[i]--;
                if(!a[i]){
                    pq.push(i);
                }
            }
        }
    }
    for(auto x:b){
        cout<<x<<" ";
    }
    cout<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}
