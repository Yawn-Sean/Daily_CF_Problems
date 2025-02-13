#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e3+10;
int a[MAXN][MAXN],b[MAXN][MAXN],n,m,x[MAXN][MAXN],va[MAXN],vb[MAXN],xa,ya;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&x[i][j]);//输入原矩阵 注意 一定要用scanf 用cin会超时
            a[i][j]=x[i][j];//行离散化数组
            b[j][i]=x[i][j];//列离散化数组
        }
    }
    for(int i=1;i<=n;i++){//离散化第 1......n 行
        sort(a[i]+1,a[i]+m+1);//将第i行从小到大排序
        va[i]=unique(a[i]+1,a[i]+m+1)-a[i]-1;//将去重完的长度存进va[i]
    }
    for(int i=1;i<=m;i++){//离散化第 1......m 列
        sort(b[i]+1,b[i]+n+1);//将第i列从小到大排序
        vb[i]=unique(b[i]+1,b[i]+n+1)-b[i]-1;//将去重完的长度存进vb[i]
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            xa=lower_bound(a[i],a[i]+va[i],x[i][j])-a[i];//二分查找x[i][j]在这一行从小到大排第几
            ya=lower_bound(b[j],b[j]+vb[j],x[i][j])-b[j];//二分查找x[i][j]在这一列从小到大排第几
            int xb=va[i]-xa;//xb表示在这一行有多少个比x[i][j]大的数
            int yb=vb[j]-ya;//yb表示在这一列有多少个比x[i][j]大的数
            printf("%d ",max(xa,ya)+max(xb,yb));//输出最终结果 
        }
        cout<<endl;
    }
    return 0;
}
