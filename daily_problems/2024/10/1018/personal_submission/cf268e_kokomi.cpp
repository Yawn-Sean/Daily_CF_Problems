#include<bits/stdc++.h>
using namespace std;
int n;
const int N = 5e4 + 10;
struct Song{
    double l;
    double p;
}song[N];
//贪心？ 期望播放时间长的尽可能放前面
bool cmp(Song a, Song b){
     return a.l * a.p * (1 - b.p / 100.00) - b.l * b.p * (1 - a.p / 100.00) > 1e-9;
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> song[i].l >> song[i].p;
    }
    sort(song + 1, song + n + 1, cmp);
//	   for(int i = 1; i <= n; i++){
//        cout << song[i].l << song[i].p << endl;
//    }
    //计算期望
    double ans = 0;
    double sum = 0;
    for(int i = 1; i <= n; i++){
        ans += song[i].l + (1.00 - song[i].p / 100.00) * sum;
//        cout << ans << endl;
        sum += (song[i].p / 100.00) * song[i].l;
    }
//    cout << ans << endl;
	printf("%.9f", ans);

}