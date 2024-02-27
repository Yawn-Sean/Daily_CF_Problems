//题意转化为从1~n个不同数字中选择r-l+1个不同数字，使得总和为s。
//首先分析s的可能取值。下面令len=r-l+1;
//上界为len*(2*n-len+1)/2;(取包含n的连续len个数)
//下届为len*(len+1)/2;(取包含1的连续len个数)
//如果满足上述条件，我们将n-len+1到n这len个不同数字按顺序放入l~r后进行调整。
//调整时使第一个数字最小调整为1，第二个数字最小调整为2，并与调整后的数字交换位置即可。

/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define all(x) x.begin(),x.end()
#define pb push_back

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) "lengli"
#endif

const int N=100010;

void solve(){
	int n,l,r,s;
	cin>>n>>l>>r>>s;
	
	int len=r-l+1;
	int mi=len*(len+1)/2;
	int ma=len*(2*n-len+1)/2;
	if(s<mi or s>ma){
		cout<<-1<<endl;
		return;
	}
	
	vector<int> id(n+2),res(n+2);
	for(int i=1;i<=n;i++) id[i]=i,res[i]=i;
	int sum=0;
	for(int i=l,j=n-len+1;i<=r;i++,j++){
		swap(id[res[i]],id[j]);
		swap(res[i],res[j]);
		sum+=j;
	}
	sum-=s;
	for(int i=l,flr=1;i<=r and sum;i++,flr++){
		int d=res[i]-flr;
		if(sum>=d){
			int now=res[i];
			swap(res[id[flr]],res[id[now]]);
			swap(id[flr],id[now]);
			sum-=d;
		}else{
			int now=res[i];
			flr=res[i]-sum;
			swap(res[id[flr]],res[id[now]]);
			swap(id[flr],id[now]);
			sum=0;
		}
		debug(res,sum);
	}
	for(int i=1;i<=n;i++) cout<<res[i]<<" ";
	cout<<endl;
}

signed main(){
    fastio;
    
    int T;
    cin>>T;
    while(T--) solve();
    
    return 0;
}
