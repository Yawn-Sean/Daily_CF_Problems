
public class cf863c_Leoncn {
        public static void solve() {
        long k = sc.nl();
        int a = sc.ni() - 1;
        int b = sc.ni() - 1;

        int[][] nextA = new int[3][3];
        int[][] nextB = new int[3][3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int f = sc.ni() - 1;
                nextA[i][j] = f;
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int f = sc.ni() - 1;
                nextB[i][j] = f;
            }
        }

        long[][] cnt = new long[3][3];
        long[][][] r = new long[3][3][2];
        for(long[]c: cnt){
            Arrays.fill(c,-1);
        }
        long ans1 = 0, ans2 = 0;
        long step = 0;

        while (step<k){
            if(cnt[a][b]>=0 && step-cnt[a][b]<=k-step){
                long f = k-step;
                long t = step - cnt[a][b];
                long d = f/t;
                ans1 += d *(ans1 - r[a][b][0]);
                ans2 += d*(ans2 - r[a][b][1]);
                step += d *(t);
            }else {
                cnt[a][b] = step++;
                r[a][b] = new long[]{ans1, ans2};
                ans1 += getV(a,b);
                ans2 += getV(b,a);
                int g = nextA[a][b];
                int h = nextB[a][b];
                a = g;
                b = h;
            }

        }
        out.println(ans1 + " " + ans2);
    }

    private static int getV(int a, int b){
        if(a == 2 && b == 0){
            return 0;
        }
        if (a == 0 && b == 2) {
            return 1;
        }
        return a>b?1:0;
    }
}
