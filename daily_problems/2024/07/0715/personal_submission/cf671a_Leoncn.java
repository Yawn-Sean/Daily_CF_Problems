public class cf671a_Leoncn {
    public static void solve() {
        int a1 = sc.ni();
        int a2 = sc.ni();
        int b1 = sc.ni();
        int b2 = sc.ni();
        int t1 = sc.ni();
        int t2 = sc.ni();
        int n = sc.ni();
        double ans = 0;
        double[][] f1 = new double[n][3];
        double[][] f2 = new double[n][3];
        for (int i = 0; i < n; i++) {
            int a = sc.ni();
            int b = sc.ni();
            double dif = Math.sqrt(Math.pow(a-t1, 2) + Math.pow(b-t2, 2));
            double x = Math.sqrt(Math.pow(a-a1, 2) + Math.pow(b-a2, 2));
            double y = Math.sqrt(Math.pow(a-b1, 2) + Math.pow(b-b2, 2));
            f1[i][0] = x;
            f1[i][1] = dif;
            f1[i][2] = i;

            f2[i][0] = y;
            f2[i][1] = dif;
            f2[i][2] = i;
            ans += 2* dif;
        }

        Arrays.sort(f1, (a,b)->Double.compare(a[0]-a[1],b[0]-b[1]));
        Arrays.sort(f2, (a,b)->Double.compare(a[0]-a[1],b[0]-b[1]));
        double d1 = f1[0][0]- f1[0][1];
        double d2 = f2[0][0] -f2[0][1];
        if(n == 1){
            out.println(ans + Math.min(d1, d2));
            return;
        }
        if(f1[0][2]!=f2[0][2]){

            if(d1<=0){
                ans += d1;
            }
            if(d2<=0){
                ans += d2;
            }
            if(d1>0 && d2>0){
                ans += Math.min(d1, d2);
            }
        }else {
            ans += Math.min(d1 + Math.min(0, f2[1][0] - f2[1][1]) , d2 + Math.min(0, f1[1][0] - f1[1][1]));
        }
        out.println(ans);


    }
}
