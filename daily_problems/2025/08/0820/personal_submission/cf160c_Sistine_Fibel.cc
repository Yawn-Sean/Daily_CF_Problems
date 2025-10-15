/**/int n;i64 k; cin >> n >> k;
  	auto a = getv<i64>(n);
  	sort(a);
  	vector<pll> v;
  	for(int i = 0; i < n; ) {
  		int j = i;
  		while(j < n && a[j] == a[i])
  			j ++;
  		v.emplace_back(a[i], j - i);
  		i = j;
  	}

  	for(auto& [x, y] : v) {
  		i64 bb = y * (i64)n;
  		if(k > bb)
  			k -= bb;
  		else {
  			for(auto xx : a) {
  				if(k > y)
  					k -= y;
  				else 
  					return(cout << x << ' ' << xx << endl);	
  			}
  		}
  	}
