//思路就是用二维数组存下每个人他的所有出价
//用mx存下的是每个人的最高出价，方便存入mp里面去
//然后用mp存下key:每个人的最高出价,element:该人的编号
//最后记得记录下每个被删除的人(便于复原)
//详情见注释

int n,m;

int main(){
    cin >> n;
    vector<vector<int>>p(n + 1); //所有参与者他对应的所有出价
    //比如1对应10 10000 || 2对应 100 和 100000
    vector<int>mx(n + 1);
    map<int,int>mp; //存入每个人的拍卖最高价对应的每个人
    for(int i = 1;i <= n;i++){
        int a,b;
        cin >> a >>b;
        p[a].push_back(b);
        mx[a] = b; //每个人的最高价
    }
    for(int i = 1;i <= n;i++){
        if(mx[i]){ //如果i出价了的话
            mp[mx[i]] = i;
        }
    }
    cin >> m;
    for(int i = 1;i <= m;i++){
        int k;
        cin >> k;
        vector<int>ban(k); // 被删除的人
        for(auto &it : ban){ //这里用引用，相当于顺便存入了
            cin >> it;
            if(mx[it]){ //有出价的话
                mp.erase(mx[it]);
            }
        }
        if(mp.empty()){ //删完了没人出价
            cout << "0 0" << endl;
        }else if(mp.size() == 1){ //剩下最后一个人,取他的最小值
            auto it = (*mp.begin()).second;
            cout << it << " " << p[it][0] << endl;
        }else{ //剩下俩个人，我们找到倒数第二个人然后取他的后一位
            //这样可以防止被
            //3 100
            //2 1000
            //4 1005
            //2 1010 删4的数据hack
            auto largest = mp.rbegin(); //最后一个元素
            auto second_largest = largest; //倒数第二个元素
            second_largest++;
            auto it = upper_bound(p[(*largest).second].begin(),p[(*largest).second].end(),p[(*second_largest).second].back());
            cout << (*largest).second << " " << *it << endl;
        }
        //复原
        for (auto &bi : ban){
			if (mx[bi]){
				mp[mx[bi]] = bi;
			}
		}
    }


}
