#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//#define int ll
void solve()
{
	 int la,lb;
	 cin>>la>>lb;
	 vector<int>a(la),b(lb),pos(1E6+5,-1);
	 for(int i=0;i<la;i++)
	 {
	 	cin>>a[i];
	 }
	 for(int i=0;i<lb;i++)
	 {
		cin>>b[i];
		pos[b[i]]=i;
	 }
	int ans=0;
	 for(int l=0,r=-1;l<la;l++)
	 {
	 	 //首先,判断[l,r+1]是否可行,Y则r++,否则continue
	 	 //如何判断可行
	 	 //第一,要在上一个"前面",第二,要在l的"后面"
	 	 if(r<l)
	 	 {
	 	 	r=l;
	 	 	if(pos[a[r]]==-1)
	 	 	{
	 	 		continue;
	 	 	}
	 	 }  
	 	 while(r<l+la-1)
	 	 {
	 	 	int d1=pos[a[(r+1)%la]]-pos[a[r%la]];
	 		int d2=pos[a[(r+1)%la]]-pos[a[l%la]];
	 		if(d1<0)
	 		{
	 			d1+=lb;
	 		}
	 		if(d2<0)
	 		{
	 			d2+=lb;
	 		}
	 		if(d1<=d2&&pos[a[(r+1)%la]]>=0)
	 		{
	 			r++;
	 		}
	 		else
	 		{
	 			break;
	 		}
	 	 }
	 	 //cerr<<l<<" "<<r<<"\n";
	 	 ans=max(ans,r-l+1);
	 }
	 cout<<ans;
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}
