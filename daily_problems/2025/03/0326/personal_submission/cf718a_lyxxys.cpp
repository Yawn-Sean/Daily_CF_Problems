void solve(){
    int n, t;
    cin >> n >> t;
    string s;
    cin >> s;
    int point = -1;
    for (int i = 0; i < n; ++ i){
        if (s[i] == '.'){
            point = i;
        }
    }
    string tar = s;
    int chose = -1;
    for (int i = point+1; i < n; ++ i){
        if ((int)s[i] >= (int)'5'){
            chose = i;
            break;
        }
    }

    if (chose != -1){
        while (tar.size() > chose+1){
            tar.pop_back();
        }

        while (tar.size() >= point+2 && (int)tar.back() >= (int)'4' && t > 0){
            tar.pop_back();
            if (tar.back() == '.') tar.pop_back();
            t -= 1;
        }
        if (tar.back() == '9'){
            assert(tar.size() == point);
            int j = tar.size()-1;
            while (tar[j] == '9'){
                tar[j] = '0';
                j -= 1;
            }
            if (j >= 0){
                tar[j] = char((int)tar[j]+1);
            } else {
                tar = "1" + tar;
            }
        } else {
            tar.back() = char((int)tar.back()+1);
        }
    }

    cout << tar << "\n";
}
