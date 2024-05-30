
public class cf1148c_Leoncn {
    static RealFastReader sc = new RealFastReader(System.in);
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) {
        int t = 1;
        while (t-- > 0) {
            solve();
        }
        out.close();
    }


    static List<String> list;
    public static void solve() {
        int n = sc.ni();
        Integer[] g = new Integer[n];
        for (int i = 0; i < n; i++) {
            g[i] = sc.ni() - 1;
        }

        Integer[] pos = new Integer[n];
        for (int i = 0; i < n; i++) {
            pos[g[i]] = i;
        }
        list = new ArrayList<>();

        for (int i = 0; i < n/2; i++) {
            if(pos[i]!=i){
                if(pos[i]<n/2){
                    swap(g, pos, pos[i] , n-1);
                }else {
                    swap(g, pos,0, pos[i]);
                    swap(g, pos,0, n - 1);
                }
                swap(g,pos, i, n-1);
            }
        }

        for (int i = n/2; i < n; i++) {
            if (pos[i] != i){
                if (pos[i] >= n / 2){
                    swap(g,pos,0, pos[i]);
                }else {
                    swap(g,pos,pos[i], n - 1);
                    swap(g,pos,0, n - 1);
                }
                swap(g,pos,0, i);
            }
        }
        out.println(list.size());
        for(String s: list){
            out.println(s);
        }
    }

    private static void swap (Integer[] g, Integer[] pos, int a, int b){
        int temA = g[a];
        int temB = g[b];
        pos[temA] = b;
        pos[temB] = a;
        g[a] = temB;
        g[b] = temA;
        list.add((a+ 1) +  " " + (b+1));
    }
}
