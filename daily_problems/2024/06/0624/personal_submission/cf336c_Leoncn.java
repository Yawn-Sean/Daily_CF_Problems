public class cf336c_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int[] g = sc.na(n);

        for (int i = 29; i >=0 ; i--) {
            int mask = -1;
            List<Integer> list = new ArrayList<>();
            for (int j = 0; j < n; j++) {
                if(((g[j]>>i)&1)==1){
                    mask &= g[j];
                    list.add(g[j]);
                }
            }
            if((mask & -mask) == (1<<i)){
                out.println(list.size());
                for(int l: list){
                    out.print( l+" ");
                }
                return;
            }
        }
        out.println(-1);
    }
}
