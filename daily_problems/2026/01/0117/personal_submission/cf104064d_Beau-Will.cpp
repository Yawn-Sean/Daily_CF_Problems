#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<std::pair<int,int>> a(n);
    for(int i = 0; i < n; i++){
        std::cin >> a[i].first >> a[i].second;
    }

    if(n == 1){
        std::cout << "4\n";
        return 0;
    }

    int addMax = -1E9,addMin = 1E9;
    int minusMax = -1E9,minusMin = 1E9;

    for(int i = 0; i < n; i++){
        addMax = std::max(addMax,a[i].first+a[i].second);
        addMin = std::min(addMin,a[i].first+a[i].second);
        minusMax = std::max(minusMax,a[i].first-a[i].second);
        minusMin = std::min(minusMin,a[i].first-a[i].second);
    }

    if(addMax==addMin || minusMax==minusMin){
        std::cout << addMax-addMin+minusMax-minusMin+5 << "\n";
    }else{
        std::cout << addMax-addMin+minusMax-minusMin+4 << "\n";
    }
}
