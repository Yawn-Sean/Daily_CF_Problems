    public static void solve(){
        int n = sc.nextInt();
        int a = sc.nextInt(), b = sc.nextInt();
        List<Integer> lists = new ArrayList<>();
        int []ts = new int[n];
        int []ans = new int[n];
        for (int i = 0; i < n; ++ i){
            ts[i] = sc.nextInt();
            lists.add(i);
        }

        if (a > b){
            Collections.sort(lists, (u, v) -> ts[u] != ts[v] ? Integer.compare(ts[u], ts[v]) : Integer.compare(u, v));
        } else {
            Collections.sort(lists, (u, v) -> ts[u] != ts[v] ? Integer.compare(ts[u], ts[v]) : Integer.compare(v, u));
        }

        if (a < b){
            for (int i = 0; i < n; ++ i){
                int j = lists.get(i);
                if (i < b) ans[j] = 2;
                else ans[j] = 1;
            }
        } else if (a > b) {
            for (int i = 0; i < n; ++ i){
                int j = lists.get(i);
                if (i < a) ans[j] = 1;
                else ans[j] = 2;
            }
        } else {
            for (int i = 0; i < n; ++ i){
                if (i < a) ans[i] = 1;
                else ans[i] = 2;
            }
        }

        for (int i = 0; i < n; ++ i){
            if (i > 0) out.print(" ");
            out.print(ans[i]);
        }
        out.println();
    }
