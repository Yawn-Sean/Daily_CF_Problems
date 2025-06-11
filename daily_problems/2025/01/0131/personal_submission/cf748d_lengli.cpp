#include<bits/stdc++.h>
#define INF 0x7fffffff
#define LL long long
#define N 100005
#define pill pair<int ,int >
using namespace std;
inline int ra()
{
    int x=0,f=1; char ch=getchar();
    while (ch<'0' || ch>'9') {if (ch=='-') f=-1; ch=getchar();}
    while (ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}
struct Node{
    int val;
    string s;
}node[N];
map<string, multiset<int > > dic;
LL ans;
int n,k,m;
bool cmp(Node a, Node b)
{
    return a.val>b.val;
}
int main()
{
    n=ra(); m=ra();
    for (int i=0; i<n; i++)
    {
        cin>>node[i].s>>node[i].val;
        dic[node[i].s].insert(node[i].val);
    }
    int k=0,x=0,tmp=0;
    for (int i=0; i<n; i++)
    {
        string s1=node[i].s;
        if (dic[s1].size()==0) continue;
        int val=(*dic[s1].rbegin());
        if (val<0) continue;
        reverse(s1.begin(),s1.end());
        dic[node[i].s].erase(dic[node[i].s].find(val));
        if (dic[s1].size()!=0)
        {
            tmp=(*dic[s1].rbegin());
            dic[s1].erase(dic[s1].find(tmp));
            if (val+tmp>=0)
            {
                ans+=val+tmp;
                if (s1==node[i].s)
                    x=max(-tmp,x);
            }
            else if (s1==node[i].s)
                x=max(x,val);
        }
        else if (s1==node[i].s) x=max(val,x);
    }
    cout<<ans+x;
    return 0;
}
