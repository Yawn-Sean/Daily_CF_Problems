#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int maxn=1e5+100;
struct node{
    int id,val;
}a[maxn];

bool cmp(node a, node b)
{
    if(a.val!=b.val)
        return a.val<b.val;
    return a.id<b.id;
}
int p[maxn];
int main()
{
    int n,x;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        a[i].id=i;
        a[i].val=x;
    }
    sort(a+1,a+n+1,cmp);
    int pre=0; 
    for(int i=1;i<=n;i++)
    {
        if(a[i].id>pre)
            p[a[i].id]=-1;
        else
            p[a[i].id]=pre;
        pre=max(pre,a[i].id);
    }
    int l=1;
    int ans=0;
    while(l<=n)
    {
        if(p[l]==-1) 
            l++;
        else
        {
            int temp=p[l];
            for(int i=l;i<=temp;i++)
                temp=max(temp,p[i]);
            l=temp+1;
        }
        ans++;
    }
    printf("%d\n",ans);
    return 0;
}
