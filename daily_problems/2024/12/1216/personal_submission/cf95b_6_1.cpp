#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

const int N = 2e5+10;

void solve()
{
    string s;cin >> s;
    int n = s.size();

    auto print = [&](int cnt4,int cnt7)
    {
        for(int i = 1;i<=cnt4;i++)cout << 4;
        for(int i = 1;i<=cnt7;i++)cout << 7;
        cout << endl;
    };

    if(s.size()&1)
    {
        n++;
        print(n/2,n/2);
        return;
    }

    s = ' '+s;
    int endi = n;
    for(int i = 1;i<=n;i++)
    {
        if(s[i]=='4'||s[i]=='7')continue;
        if(s[i]<'4'){s[i] = '4',endi = i;break;}
        else if(s[i]<'7'){s[i] = '7',endi = i;break;}
        else
        {
            for(int j = i-1;j>=1;j--)
            {
                if(s[j]=='4'){s[j] = '7',endi = j;break;}
            }
            if(endi==n){print(n/2+1,n/2+1);return;}
            break;
        }
    }
    vector<int> cnt(20);
    cnt[4] = n/2,cnt[7] = n/2;
    int i7 = -1,num7 = 0,num4 = 0;
        for(int i = 1;i<=endi;i++)
        {
            cnt[s[i]-'0']--;
            if(cnt[7]>=1&&s[i]=='4')i7 = i,num4 = cnt[4],num7 = cnt[7];
            if(cnt[7]<0)
            {
                if(i7==-1){print(n/2+1,n/2+1);return;}
                else 
                {
                    s[i7] = '7',endi = i7,cnt[7]=num7-1,cnt[4]=num4+1;
                    break;
                }
            }
        }
        if(cnt[4]<0)
            for(int i = endi;i>=1;i--)
            {
                if(s[i]=='4')s[i] = '7',cnt[4]++,cnt[7]--;
                if(cnt[4]==0)break;
            }
        for(int i = 1;i<=endi;i++)cout << s[i];
        print(cnt[4],cnt[7]);
    
}
//74777
signed main()
{
    IOS
    int tt = 1;
    // cin >> tt;
    while(tt--)
    {
        solve();
    }
    return 0;
}
