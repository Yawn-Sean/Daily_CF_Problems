#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/gym/106351/problem/K

//    2026-2-6-(质因子枚举+数学)- cfgym106351K 
//

//日期： 2026-2-6 
//格式化： ctrl+shift+ a

typedef long long ll;
typedef vector<int> vv;
const int MAX=1e5+10;

int n,x,y;
int cnt[MAX];
vector<vv> fac=vector<vv>(MAX,vv(0));

void init(){
	for(int i=1;i<MAX;i++){
		for(int j=i;j<MAX;j+=i){
			fac[j].push_back(i);
		}
	}
}

ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}

void solve(){
	init();
	ll ans=0;
	
	for(int i=x;i<=y;i++){                   //固定lcm
		ans+=1LL*cnt[i]*(cnt[i]-1)/2;
		
		int len=fac[i].size();
		for(int j=0;j<len;j++){
			for(int k=0;k<j;k++){
				ll p1=fac[i][j],p2=fac[i][k];     //固定lcm后，候选的数对（p1,p2）必须都是 lcm 的因子 
				
				int g=gcd(p1,p2);
				if(g>=x && p1*p2/g==i){
					ans+=cnt[p1]*cnt[p2];
				}
			}
		}
	}
	
	cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0); 
    
    cin>>n>>x>>y;
    for(int i=0;i<n;i++){
    	int tmp;
    	cin>>tmp;
    	cnt[tmp]++;
	}
   solve();

    return 0;
}

/*



*/

