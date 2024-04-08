public class cf492d_Leoncn {
    static RealFastReader sc = new RealFastReader(System.in);
    static PrintWriter out = new PrintWriter(System.out);


    public static void main(String[] args) {
        int t = 1;
        while (t-- > 0) {
            solve();
        }
        out.close();
    }
    public static void solve() {
        int n = sc.ni();
        int x = sc.ni();
        int y = sc.ni();
        int g = gcd(x,y);
        int a = x/g;
        int b = y/g;
        int min = Math.min(a, b);
        int max = Math.max(a, b);
        for (int i = 0; i < n; i++) {
            int f = sc.ni();
            f = f%(min + max);
            if(max == min || f == 0 || f == min + max -1){
                out.println("Both");
            }else {
                long c = ((long)f*min)/(max+min);

                if( (c)*(min+max)/min == f || (c+1)*(max+min)/min == f){
                    out.println(max == a?"Vova":"Vanya");
                }else {
                    out.println(max == a?"Vanya":"Vova");
                }

            }


        }

    }
    public static int gcd(int m, int n){
        return  n!=0?gcd(n,m%n):m;
    }

}
