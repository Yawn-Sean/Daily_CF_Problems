#include <bits/stdc++.h>
int main() {
    int n;
    std::cin >> n;
    int ans = 0;
    int cur_speed = 0;
    std::vector<int> speed_limit;
    int forbiden_over_car = 0;
    for(int i=0; i <n; ++i){
        int t,speed;
        std::cin >> t;
        if(t == 1){
            std::cin >> cur_speed;
            while(!speed_limit.empty() && speed_limit.back() < cur_speed){
                speed_limit.pop_back();
                ans++;
            }
        }else if (t == 2){
            ans += forbiden_over_car;
            forbiden_over_car = 0;
        }else if (t == 3){
           std::cin >> speed;
           if(cur_speed > speed) ans++;
           else speed_limit.push_back(speed);
        }else if (t == 4){
            forbiden_over_car = 0;
        }else if (t == 5){
            speed_limit.clear();
        }else{
            forbiden_over_car += 1;
        }

    }
    std::cout << ans << std::endl;
}