public class cf317b_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int[][] g = new int[151][151];
        g[75][75] = n;
        int[] d = new int[]{-1, 1, 0, 0};
        int[] r = new int[]{0, 0, -1, 1};
        while (true){
            boolean f = false;
            for (int i = 0; i < 151; i++) {
                for (int j = 0; j < 151; j++) {

                    if(g[i][j]<4){
                        continue;
                    }
                    int c = g[i][j]/4;
                    g[i][j] = g[i][j]%4;
                    for (int k = 0; k < 4; k++) {
                        g[i+d[k]][j+r[k]] += c;
                        f = true;
                    }

                }
            }
            if(!f){
                break;
            }
        }
        int q = sc.ni();
        for (int i = 0; i < q; i++) {
            int a = Math.abs(sc.ni());
            int b = Math.abs(sc.ni());
            if(a>75 || b>75){
                out.println(0);
            }else {
                out.println(g[a+75][b+75]);
            }
        }
    }
}
