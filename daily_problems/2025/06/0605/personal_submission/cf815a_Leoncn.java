public static void solve() {
    int n = sc.ni();
    int m = sc.ni();
    int[][] g = new int[n][m];
    int[][] copy = new int[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            g[i][j] = sc.ni();
            copy[i][j] = g[i][j];
        }
    }
    List<String> list1 = new ArrayList<>();
    for (int i = 0; i < n; i++) {
        int min = Integer.MAX_VALUE;
        for (int j = 0; j < m; j++) {
            min = Math.min(g[i][j], min);
        }
        if(min>0){
            for (int j = 0; j < m; j++) {
                g[i][j] -= min;
            }
            for (int j = 0; j < min; j++) {
                list1.add("row " + (i+1));
            }
        }
    }

    for (int i = 0; i < m; i++) {
        int min = Integer.MAX_VALUE;
        for (int j = 0; j < n; j++) {
            min = Math.min(g[j][i], min);
        }
        if(min>0){
            for (int j = 0; j < n; j++) {
                g[j][i] -= min;
            }
            for (int j = 0; j < min; j++) {
                list1.add("col " + (i+1));
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(g[i][j]>0){
                out.println(-1);
                return;
            }
        }
    }

    List<String> list2 = new ArrayList<>();
    for (int i = 0; i < m; i++) {
        int min = Integer.MAX_VALUE;
        for (int j = 0; j < n; j++) {
            min = Math.min(copy[j][i], min);
        }
        if(min>0){
            for (int j = 0; j < n; j++) {
                copy[j][i] -= min;
            }
            for (int j = 0; j < min; j++) {
                list2.add("col " + (i+1));
            }
        }
    }

    for (int i = 0; i < n; i++) {
        int min = Integer.MAX_VALUE;
        for (int j = 0; j < m; j++) {
            min = Math.min(copy[i][j], min);
        }
        if(min>0){
            for (int j = 0; j < m; j++) {
                copy[i][j] -= min;
            }
            for (int j = 0; j < min; j++) {
                list2.add("row " + (i+1));
            }
        }
    }

    if(list1.size()>list2.size()){
        out.println(list2.size());
        for(String s: list2){
            out.println(s);
        }
    }else {
        out.println(list1.size());
        for(String s: list1){
            out.println(s);
        }
    }

}