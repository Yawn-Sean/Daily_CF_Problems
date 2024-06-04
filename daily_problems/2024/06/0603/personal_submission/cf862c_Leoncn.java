public class cf862c_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int x = sc.ni();
        if(n == 1){
            out.println("YES");
            out.println(x);
            return;
        }
        if(n == 2){
            if(x == 0 ){
                out.println("NO");
                return;
            }
            out.println("YES");
            out.println(0 + " " + x);
            return;
        }
        out.println("YES");
        int num = 1<<17, xor = 0;
        for (int i = 1; i < n-2; i++) {
            out.print(i + " " );
            xor^=i;
        }
        if(xor == x){
            int s = 2*num;
            int t = num ^ s;
            out.print(num + " " + s + " " + t);
        }else {
            int s = xor^ num ^x;
            out.print(0 + " " + num + " " + s);
        }
    }
}
