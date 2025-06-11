#include<bits/stdc++.h>
using namespace std;
int h1, a1, d1;
int h2, a2, d2;
int h, a, d;
int ceil(int a, int b){
	return (a+b-1)/b;
}
// 枚举增加的攻击力和防御力
int main(){
    cin >> h1 >> a1 >> d1;
    cin >> h2 >> a2 >> d2;
    cin >> h >> a >> d;
    int ans = 1e8 + 10;
    for(int i = max(0, d2 - a1 + 1); i <= max(0, h2 - (a1 - d2)); i++){
        for(int j = 0; j <= max(a2 - d1, 0); j++){
            int mtime = ceil(h2 , (a1 + i - d2));
            if(a2 - d1 - j <= 0){
            	ans = min(ans, i * a + j * d);//已能无伤
            	continue;
			}
            int l = max(0, mtime * (a2 - d1 - j) - h1 + 1);
            ans = min(ans, h * l + i * a + j * d);
        }
    }
    cout << ans;
    return 0;
}