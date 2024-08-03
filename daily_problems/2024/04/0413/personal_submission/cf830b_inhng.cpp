#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100000;
int A[maxn*4+10],n;
vector<int>v[maxn*4];
void update(int id,int v)
{
    while(id<=maxn*4){
        A[id]+=v;
        id+=(id&(-id));
    }
}
int query(int id)
{
    int sum=0;
    while(id){
        sum+=A[id];
        id-=(id&(-id));
    }
    return sum;
}
int main()
{
    scanf("%d",&n);
    memset(A,0,sizeof(A));
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        v[x].push_back(i);
        update(i,1);
    }
    int last=0;
    ll ans=0;
    for(int i=1;i<=maxn;i++){
        int Size=v[i].size(),tmp=-1;
        if(Size==0) continue;
        for(int j=0;j<Size;j++){
            if(v[i][j]<last)
                tmp=v[i][j];
        }
        if(tmp==-1){
            ans+=query(v[i][Size-1])-query(last);
            last=v[i][Size-1];
        }
        else{
            ans+=query(maxn)-(query(last)-query(tmp));
            last=tmp;
        }
        for(int j=0;j<Size;j++)
            update(v[i][j],-1);
    }
    printf("%lld\n",ans);
    return 0;
}
