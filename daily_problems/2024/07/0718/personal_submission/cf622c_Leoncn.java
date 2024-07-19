public class cf622c_Leoncn {
    int n = sc.ni();
    int m = sc.ni();
    int[] g = sc.na(n);
    int[] lefts = new int[n];
    for (int i = 0; i < n; i++) {
        lefts[i] = i;
    }
    for (int i = 1; i <n ; i++) {
        if(g[i] == g[i-1]){
            lefts[i] = lefts[i-1];
        }
    }

    for (int i = 0; i < m; i++) {
        int a = sc.ni() - 1;
        int b = sc.ni() - 1;
        int x = sc.ni();
        if(g[b]!=x){
            out.println( b+1);
        }else {
            out.println(lefts[b]<=a?-1:lefts[b]);
        }
    }
}
