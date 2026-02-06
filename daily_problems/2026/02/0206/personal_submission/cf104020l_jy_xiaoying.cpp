// #include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <array>
#include <climits>


using namespace std;

//链接：https://codeforces.com/gym/104020/problem/L

//    2026-2-6-(计算几何+排序+数学)- cfgym104020L 
//

//日期： 2026-2-6 
//格式化： ctrl+shift+ a

typedef long long ll;
const int MAX=2e6+10;

int n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr); 
    
    cin>>n;
    vector<array<ll,3>> g(n);
    for(auto &[x,y,z]:g){
    	cin>>x>>y>>z;
	}
	
	sort(g.begin(),g.end());  //排x轴坐标排序
	
	ll ans=LLONG_MAX;
	for(int i=0;i<n;i++){
		auto [x1,y1,z1]=g[i];
		for(int j=max(0,i-100);j<i;j++){
			auto [x2,y2,z2]=g[j];
			ans=min(ans,(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2));
		}
	} 
	cout << fixed << setprecision(10) << sqrtl(ans)<<endl;

    return 0;
}

/*



*/

