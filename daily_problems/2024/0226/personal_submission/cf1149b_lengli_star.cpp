//定义dp(i,j,k)表示字符串1匹配了前i位，字符串2匹配了前j位，字符串3匹配了前k位时，所需模板串的最短长度。
//当其中某一个串长度加1时，我们只需要在其对应长度len的情况下，枚举另外两个串的匹配长度，更新dp数组即可。
//预处理ne(i,j)，定义为模板串中第i个位置后面首次出现字符j的位置。方便更新dp数组。
//状态转移时，考虑字符串1，则有f[i][j][k]=min(f[i][j][k],ne[f[i-1][j][k]][str[1][len[1]]-'a'])。(j,k同理)。
//如果操作后dp(len[1],len[2],len[3])<=n代表存在合法方案。

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

int ne[N][26];
int n,q;
int f[300][300][300];

void solve(){
	cin>>n>>q;
	string s;
	cin>>s;
	vector<int> la(26,1e9);
	for(int i=n;i>=0;i--){
		int c=s[i-1]-'a';
		for(int j=0;j<26;j++) ne[i][j]=la[j];
		la[c]=i;
	}
	vector<int> len(4,0);
	vector<string> str(4,"");
	
	
	for(int i=0;i<=250;i++)
		for(int j=0;j<=250;j++)
			for(int k=0;k<=250;k++) f[i][j][k]=1e9;
	f[0][0][0]=0;
	while(q--){
		char op;
		cin>>op;
		if(op=='+'){
			int id;
			char c;
			cin>>id>>c;
			str[id]+=c;
			len[id]++;
			for(int i=(id==1 ? len[1] : 0);i<=len[1];i++)
				for(int j=(id==2 ? len[2] : 0);j<=len[2];j++)
					for(int k=(id==3 ? len[3] : 0);k<=len[3];k++){
						f[i][j][k]=1e9;
						if(i>=1 and f[i-1][j][k]<=n) f[i][j][k]=min(f[i][j][k],ne[f[i-1][j][k]][str[1][i-1]-'a']);
						if(j>=1 and f[i][j-1][k]<=n) f[i][j][k]=min(f[i][j][k],ne[f[i][j-1][k]][str[2][j-1]-'a']);
						if(k>=1 and f[i][j][k-1]<=n) f[i][j][k]=min(f[i][j][k],ne[f[i][j][k-1]][str[3][k-1]-'a']);
					}
		}else{
			int id;
			cin>>id;
			len[id]--;
			str[id].pop_back();
		}
		debug(f[len[1]][len[2]][len[3]]);
		cout<<(f[len[1]][len[2]][len[3]]<=n ? "YES" : "NO")<<endl;
	}
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
