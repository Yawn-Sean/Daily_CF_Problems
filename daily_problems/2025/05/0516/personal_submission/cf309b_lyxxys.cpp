
void solve(){
    int n, row, c;
    cin >> n >> row >> c;
    vector <string> s(n);
    vector <int> A(n), rs(n);
    vector<vector<int>> f(n, vector<int>(20, -1));

    for (int i = 0; i < n; ++ i){
        cin >> s[i];
        A[i] = s[i].size();
    }

    for (int i = 0, j = -1, tot = 0; i < n; ++ i){
        while (i > j || (j+1 < n && tot+j+1-i + A[j+1] <= c)){
            j += 1;
            tot += A[j];
        }
        
        if (tot+j-i <= c) rs[i] = j;
        else rs[i] = -1;

        tot -= A[i];
    }

    int chose = -1, ma = 0, chose_r;
    row -= 1;
   	/*
		为了保证跳 r-1 次，符合预期答案：
		如果它将要跳的那个单词长度大于 c(一行也构造不了)，则不管跳2的多少次方，都应该是它自己
		如果我这一行已经选完了最后一个单词，则我不管跳多少次，都应该表示选完了单词
		
		这样总能保证向父节点跳多少次都符合预期答案
	*/
    for (int i = n-1; i >= 0; -- i){
        int nxt = rs[i];
        bool jug = 0;
        if (nxt == -1){
            continue;
        } else if (nxt+1 < n){
            if (rs[nxt+1] == -1){  
                for (int u = 0; u < 20; ++ u){
                    f[i][u] = i;
                }
                jug = 1;
            } else {
                f[i][0] = nxt+1;
            }
        } else {  // 父节点大于等于 n, 设为 n-1
            for (int u = 0; u < 20; ++ u){
                f[i][u] = n-1;
            }
            jug = 1;
        }
        
        if (!jug){
            for (int u = 1; u < 20; ++ u){
                assert(f[i][u-1] != -1);
                f[i][u] = f[f[i][u-1]][u-1];
            }
        }

        int cur = i;

        for (int u = 19; u >= 0; -- u){
            if ((row>>u) & 1){
                cur = f[cur][u];
            }
        }

        int v = rs[cur]-i+1;
        if (v > ma){
            ma = v;
            chose = i;
            chose_r = rs[cur];
        }
    }


    if (chose != -1){
        vector<vector<string>> ans;
        vector <string> curs;
        for (int i = chose; i <= chose_r; ++ i){
            int j = i-1;

            while (j+1 <= rs[i]){
                j += 1;
                curs.push_back(s[j]);
            }

            i = j;
            ans.push_back(curs);
            curs.clear();
        }
        for (auto &chs : ans){
            for (int j = 0; j < chs.size(); ++ j){
                if (j) cout << " ";
                cout << chs[j];
            }
            cout << "\n";
        }
    }
}
