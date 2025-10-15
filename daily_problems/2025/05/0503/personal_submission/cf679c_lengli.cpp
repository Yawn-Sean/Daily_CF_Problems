#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
#include<math.h>
//#include<vector>
//#include<iostream>
using namespace std;

int n,K;
#define maxn 511
char mp[maxn][maxn];
int id[maxn][maxn];

int ufs[maxn*maxn],size[maxn*maxn];
int find(int x) {return x==ufs[x]?x:(ufs[x]=find(ufs[x]));}
void Union(int x,int y) {x=find(x),y=find(y); if (x==y) return; size[y]+=size[x]; ufs[x]=y;}

int bud[maxn*maxn]; bool vis[maxn][maxn];
int quex[maxn*maxn],quey[maxn*maxn],head,tail;
const int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
void bfs(int x,int y)
{
    vis[x][y]=1; int ff=id[x][y];
    head=0; tail=1; quex[0]=x; quey[0]=y;
    while (head!=tail)
    {
        const int xx=quex[head],yy=quey[head]; head++;
        for (int i=0;i<4;i++)
        {
            int nx=xx+dx[i],ny=yy+dy[i];
            if (nx<0 || nx>n || ny<0 || ny>n || vis[nx][ny] || mp[nx][ny]!='.') continue;
            vis[nx][ny]=1; quex[tail]=nx; quey[tail]=ny; tail++;
            int idid=id[nx][ny]; Union(idid,ff);
        }
    }
}

void insert(int x,int y,int &tot)
{
    int now=id[x][y],ff=find(now);
    if (!bud[ff]) tot+=size[ff]; bud[ff]++;
}
void Delete(int x,int y,int &tot)
{
    int now=id[x][y],ff=find(now);
    bud[ff]--; if (!bud[ff]) tot-=size[ff];
}
int main()
{
    scanf("%d%d",&n,&K);
    for (int i=1;i<=n;i++) scanf("%s",mp[i]+1);
    for (int i=1,tot=0;i<=n;i++)
        for (int j=1;j<=n;j++)
            id[i][j]=++tot;
    for (int i=1;i<=n*n;i++) ufs[i]=i,size[i]=1;

    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (mp[i][j]=='.' && !vis[i][j]) bfs(i,j);
    int ans=0;
    for (int i=K;i<=n;i++)
    {
        memset(bud,0,sizeof(bud));
        int tot=0,xx=0;
        for (int j=i-K+1;j<=i;j++)
            for (int k=1;k<=K;k++) if (mp[j][k]=='.') insert(j,k,tot);
            else xx++;
        if (K<n) for (int j=i-K+1;j<=i;j++) if (mp[j][K+1]=='.') insert(j,K+1,tot);
        if (i>K) for (int k=1;k<=K;k++) if (mp[i-K][k]=='.') insert(i-K,k,tot);
        if (i<n) for (int k=1;k<=K;k++) if (mp[i+1][k]=='.') insert(i+1,k,tot);
        ans=max(ans,tot+xx);

        for (int k=K+1;k<=n;k++)
        {
            for (int j=i-K+1;j<=i;j++) xx-=(mp[j][k-K]=='X');
            for (int j=i-K+1;j<=i;j++) xx+=(mp[j][k]=='X');
            if (k>K+1) for (int j=i-K+1;j<=i;j++) if (mp[j][k-K-1]=='.') Delete(j,k-K-1,tot);
            if (k<n) for (int j=i-K+1;j<=i;j++) if (mp[j][k+1]=='.') insert(j,k+1,tot);
            if (i>K)
            {
                if (mp[i-K][k]=='.') insert(i-K,k,tot);
                if (mp[i-K][k-K]=='.') Delete(i-K,k-K,tot);
            }
            if (i<n)
            {
                if (mp[i+1][k]=='.') insert(i+1,k,tot);
                if (mp[i+1][k-K]=='.') Delete(i+1,k-K,tot);
            }
            ans=max(ans,tot+xx);
//            cout<<i<<' '<<k<<' '<<tot<<' '<<xx<<endl;
        }
    }
    printf("%d\n",ans);
    return 0;
}
