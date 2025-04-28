#include <iostream>
#include <cstdio>
using namespace std;
const int INF=1e6+5;
int n,m,a[INF],b[INF],la[INF][2],c[INF],tot,ans,ans1[INF][2];
int d[INF][5],tot1,ans11;
signed main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    scanf("%d",&m);
    for (int i=1;i<=m;i++)
        scanf("%d",&b[i]);
    la[n][0]=la[n][1]=n+1;
    for (int i=n-1;i>=1;i--) {
        la[i][0]=la[i+1][0];
        la[i][1]=la[i+1][1];
        la[i][a[i]]=i;
    }
    int j=1,i=1;int fl=0;
    for (i=1;i<=n;) {
        while (b[j]==a[i] && j<=m) {
            c[++tot]=b[j];
            d[++tot1][0]=j+n;
            j++;
        }
        if (j>m) break;
        int len=la[i][b[j]];
        if (len>n) len=n;
        int l=0;if (i==1) l=1;else l=i+1;
        for (int k=l;k<=len;k++) {
            c[++tot]=a[k];
            d[++tot1][0]=k;
        }
        i=la[i][b[j]];
        fl=1;
    }
    if (fl) i++;
    while (j<=m) c[++tot]=b[j],d[++tot1][0]=j+n,j++;
    while (i<=n) c[++tot]=a[i],d[++tot1][0]=i,i++;
    for (int i=1;i<=tot;i++)
        if (c[i]!=c[i+1]) ans1[++ans][0]=i;
    // cout<<ans<<"\n";
    la[m][0]=la[m][1]=m+1;
    for (int i=m-1;i>=1;i--) {
        la[i][0]=la[i+1][0];
        la[i][1]=la[i+1][1];
        la[i][b[i]]=i;
    }
    tot1=tot=0;
    j=1,i=1;fl=0;
    for (i=1;i<=m;) {
        while (b[i]==a[j] && j<=n) {
            c[++tot]=a[j];
            d[++tot1][1]=j;
            j++;
        }
        if (j>n) break;
        int len=la[i][a[j]];
        if (len>m) len=m;
        int l=0;if (i==1) l=1;else l=i+1;
        for (int k=l;k<=len;k++) {
            c[++tot]=b[k];
            d[++tot1][1]=k+n;
        }
        i=la[i][a[j]];
        fl=1;
        // cout<<i<<" "<<j<<"\n";
    }
    // for (int i=1;i<=tot;i++)
    //     cout<<c[i]<<" ";
    // cout<<"\n";
    if (fl) i++;
    while (j<=n) c[++tot]=a[j],d[++tot1][1]=j,j++;
    while (i<=m) c[++tot]=b[i],d[++tot1][1]=i+n,i++;
    // for (int i=1;i<=tot;i++)
    //     cout<<c[i]<<" ";
    for (int i=1;i<=tot;i++)
        if (c[i]!=c[i+1]) ans1[++ans11][1]=i;
    if (ans>ans11) {
        for (int i=1;i<=tot1;i++)
            cout<<d[i][1]<<" ";
        cout<<"\n"<<ans11<<"\n";
        for (int i=1;i<=ans11;i++)
            cout<<ans1[i][1]<<" ";
        cout<<"\n";
    } 
    else {
        for (int i=1;i<=tot1;i++)
            cout<<d[i][0]<<" ";
        cout<<"\n"<<ans<<"\n";
        for (int i=1;i<=ans;i++)
            cout<<ans1[i][0]<<" ";
        cout<<"\n";
    }
    return 0;
}
