

public class cf1292b_Leoncn {
        public static void solve() {
        long x0 = sc.nl();
        long y0 = sc.nl();
        long ax = sc.nl();
        long ay = sc.nl();
        long bx = sc.nl();
        long by = sc.nl();

        long sx = sc.nl();
        long sy = sc.nl();
        long t = sc.nl();

        List<Long> listX = new ArrayList<>();
        List<Long> listY = new ArrayList<>();
        while (x0+ y0 - sx - sy <=t){
            listX.add(x0);
            listY.add(y0);
            x0 = x0 *ax + bx;
            y0 = y0 *ay+ by;
        }
        int n= listX.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <=i; j++) {
                for (int k = i; k <n ; k++) {
                    long sum = Math.abs(sx -listX.get(i)) + Math.abs(sy - listY.get(i)) + listX.get(k) - listX.get(j) + listY.get(k) - listY.get(j)
                            + Math.min(listX.get(i) - listX.get(j) + listY.get(i) - listY.get(j), listX.get(k) - listX.get(i) + listY.get(k) - listY.get(i));
                    if(sum<=t){
                        ans = Math.max(k-j+1, ans);
                    }
                }
            }
        }
        out.println(ans);


    }
}
