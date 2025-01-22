#include <bits/stdc++.h>

struct UF{
    std::vector<int> p;
    UF(int n){
        p.resize(n);
        for(int i = 0; i < n; i++){
            p[i] = i;
        }
    }
    int find(int x){
        if(p[x] == x){
            return x;
        }else{
            return p[x] = find(p[x]);
        }
    }
    void merge(int x, int y){
        x = find(x);
        y = find(y);
        if(x != y){
            p[x] = y;
        }
    }
};
int main(){
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    UF uf(n);
    std::vector<int*> b; // 保存需要更新的节点
    int root = -1;
    int ans = 0; // flag
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
        a[i]--;
        if(a[i] == i){
            root = i;
        }
    }
    for(int i = 0; i < n; i++){
        if(uf.find(i) != uf.find(a[i])){
            uf.merge(i, a[i]);
        }else{
            if(root == -1){
                root = i;
                ++ans;
            }
            b.push_back(&a[i]);
        }
    }
    for(auto x: b){
        *x = root;
    }
    std::cout << b.size() - 1  + ans << std::endl;
    for(auto x: a){
        std::cout << x + 1 << " ";
    }

}