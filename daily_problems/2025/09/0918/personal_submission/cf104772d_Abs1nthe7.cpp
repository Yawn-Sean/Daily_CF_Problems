#pragma GCC optimize(3, "Ofast", "inline", "unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define u64 unsigned long long
#define debug(x) cout<<x<<endl;
#define endl "\n"
//构造题，d<=1000,最大能到100位，考虑将每一位都构造成一样的数，这样直接构造d位数就一定是
//直接暴力跑bfs是d2，可以实现
void sol()
{
    int d;cin>>d;
    if(d==1)
    {
        cout<<1<<endl;
        return;
    }
    int D=d;
    int tot=d*d;
    vector<int>pa(tot,-2);//记录前驱状态，起点为-1
    vector<int>pa_d(tot,-1);//记录前驱到现在所加的数字
    deque<int>q;
    for(int i=1;i<=9;++i)
    {
        int r=i%D;//当前构造数对i的余数
        int s=i%D;//当前位数和对i的余数
        int id=r*d+s;//二维转一维
        if(pa[id]!=-2)continue;
        pa[id]=-1;
        pa_d[id]=i;
        q.emplace_back(id);
        if(r==0&&s==0)
        {
            cout<<i<<endl;
            return;
        }
    }
    int ans_id=0;
    bool ok=false;
    while(!q.empty()&&!ok)
    {
        int now=q.front();q.pop_front();
        int r=now/D;
        int s=now%D;
        for(int i=0;i<=9;++i)
        {
            int new_r=(r*10+i)%D;
            int new_s=(s+i)%D;
            int new_id=new_r*D+new_s;
            if(pa[new_id]!=-2)continue;
            pa[new_id]=now;
            pa_d[new_id]=i;
            if(new_id==ans_id)
            {
                ok=true;
                break;
            }
            q.emplace_back(new_id);
        }
    }
    string ans;
    int now=ans_id;
    while(now!=-1)
    {
        int dig=pa_d[now];
        ans.push_back(char('0'+dig));
        now=pa[now];
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
}
signed main()
{
    //freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int _=1;
    //cin>>_;
    while(_--)sol();
    return 0;
}
