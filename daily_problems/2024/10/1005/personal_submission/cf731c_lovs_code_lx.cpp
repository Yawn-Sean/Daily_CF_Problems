#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef long long ll;
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;
class UnionFind
{
public:
    vector<int> parent;
    vector<int> rank;
    UnionFind(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int index)
    {
        if (index == parent[index])
        {
            return index;
        }
        parent[index] = find(parent[index]);
        return parent[index];
    }
    void merge(int index1, int index2)
    {
        int root1 = find(index1);
        int root2 = find(index2);
        if (root1 != root2)
        {
            if (rank[root1] > rank[root2])
            {
                parent[root2] = root1;
            }
            else if (rank[root1] < rank[root2])
            {
                parent[root1] = root2;
            }
            else
            {
                parent[root2] = root1;
                rank[root1]++;
            }
        }
    }
};
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> arr(n);
    UnionFind f(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<pii> num(m); 
    for (int i = 0; i < m; i++)
    {
        cin >> num[i].first >> num[i].second;
        num[i].first--;
        num[i].second--;
        f.merge(num[i].first, num[i].second);
    }

    map<int, set<int>> unifind; 
    for (int i = 0; i < n; i++)
    {
        int rootx = f.find(i);
        unifind[rootx].insert(i);
    }

    ll ans = 0;
    for (auto x : unifind) 
    {
        int p = x.second.size(); 
        map<int, int> mynum;     
        ll ma = 0;               
        for (auto y : x.second) 
        {
            mynum[arr[y]]++;
            if (mynum[arr[y]] > ma)
            {
                ma = mynum[arr[y]];
            }
        }
        ans = ans + p - ma; 
    }

    cout << ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
