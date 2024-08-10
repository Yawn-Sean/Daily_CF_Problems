#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
int ga[10][10];
int gb[10][10];
int memo[10][10];
int win[10][10];
vector<PII> seq;

void init()
{
    win[1][1]=0;
    win[1][2]=-1;
    win[1][3]=1;
    win[2][1]=1;
    win[2][2]=0;
    win[2][3]=-1;
    win[3][1]=-1;
    win[3][2]=1;
    win[3][3]=0;
    return;
}

vector<LL> calc(int l,int r)
{
    vector<LL> res={0,0};
    for(int i=l;i<r;i++)
    {
        int x=seq[i].first;
        int y=seq[i].second;
        if(win[x][y]==1)
            res[0]++;
        else if(win[x][y]==-1)
            res[1]++;
    }
    return res;
}

void solve()
{
    memset(memo,-1,sizeof(memo));
    seq.clear();
    
    LL k,a,b;
    cin>>k>>a>>b;
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
            cin>>ga[i][j];
        }
    }
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
            cin>>gb[i][j];
        }
    }
    seq.push_back({0,0});
    seq.push_back({a,b});
    memo[a][b]=1;
    int cycle=-1;
    for(int i=2;i<=k;i++)
    {
        int x=ga[seq[i-1].first][seq[i-1].second];
        int y=gb[seq[i-1].first][seq[i-1].second];
        if(memo[x][y]==-1)
        {
            seq.push_back({x,y});
            memo[x][y]=i;
        }
        else
        {
            cycle=memo[x][y];
            break;
        }
    }
    int m=seq.size();
    if(cycle==-1)
    {
        auto res=calc(1,m);
        cout<<res[0]<<' '<<res[1]<<'\n';
    }
    else
    {
        LL tk=k;
        tk-=cycle;
        LL l=m-cycle;
        LL t=tk/l;
        LL r=tk%l;

        auto res1=calc(1,cycle);
        auto res2=calc(cycle,m);
        auto res3=calc(cycle,cycle+r+1);
        
        vector<LL> res={0,0};
        res[0]=res1[0]+t*res2[0]+res3[0];
        res[1]=res1[1]+t*res2[1]+res3[1];
        cout<<res[0]<<' '<<res[1]<<'\n';
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    init();
    
    int t;
    t=1;
    while(t--)
    {
        solve();
    }
    return 0;
}
