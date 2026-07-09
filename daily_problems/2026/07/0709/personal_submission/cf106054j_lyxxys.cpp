void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> ivec(2), jvec(2);
    std::map <int,int> M1, M2;


    for (int i = 0, k; i < n; ++ i){
        std::cin >> k;
        for (int j = 0, x; j < k; ++ j){
            std::cin >> x;
            M1[x] += 1;
            if (n <= 2){
                ivec[i].emplace_back(x);
            }
        }
    }
    for (int i = 0, k; i < n; ++ i){
        std::cin >> k;
        for (int j = 0, x; j < k; ++ j){
            std::cin >> x;
            M2[x] += 1;
            if (n <= 2){
                jvec[i].emplace_back(x);
            }
        }
    }

    if (M1.size() != M2.size()){
        std::cout << "N\n";
        return;
    }
    for (auto &[k, v] : M1){
        if (M2[k] != v){
            std::cout << "N\n";
            return;
        }
    }

    if (n == 2){
        int dir = ivec[0].size() - jvec[0].size();
        while (ivec[0].size() != jvec[0].size()){
            bool flg{false};
            if (dir > 0){
                if (ivec[1].empty() || ivec[0].back() <= ivec[1].back()){
                    flg = true;
                    ivec[1].emplace_back(ivec[0].back());
                    ivec[0].pop_back();
                }
            } else {
                if (ivec[0].empty() || ivec[1].back() <= ivec[0].back()){
                    flg = true;
                    ivec[0].emplace_back(ivec[1].back());
                    ivec[1].pop_back();
                }
            }
            if (!flg){
                std::cout << "N\n";
                return;
            }
        }

        bool flg{true};
        for (int i = 0; i < ivec[0].size(); ++ i){
            if (ivec[0][i] != jvec[0][i]){
                flg = false;
            }
        }
        for (int i = 0; i < ivec[1].size(); ++ i){
            if (ivec[1][i] != jvec[1][i]){
                flg = false;
            }
        }

        if (!flg){
            std::cout << "N\n";
            return;
        }
    }

    std::cout << "S\n";
}
