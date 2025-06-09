    public static void solve() {
        String s = sc.ns();
        int n = sc.ni();
        String[] arr = new String[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.ns();
        }
        int m = s.length();
        int l = -1, ans = 0, pos = 0;
        for (int i = 0; i < m; i++) {
            for(String a : arr){
                int len = a.length();
                if(i - len + 1 >=0 && s.substring(i-len+1,i+1).equals(a) ){
                    l = Math.max(l, i-len+1);
                }
            }
            if(ans < i - l){
                ans = i - l;
                pos = l+1;
            }
        }
        out.println(ans + " " + pos );
    }