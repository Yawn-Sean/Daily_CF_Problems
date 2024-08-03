package daily_problems.2024.04.0412.personal_submission;

public class cf916c_Leoncn {
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
        int m = sc.ni();
        if(n == 2){
            out.println(2 + " " + 2);
            out.println(1 + " " + 2 + " " + 2);
            return;
        }
        List<String> ans = new ArrayList<>();
 
        for (int i = 3; i <= n; i++) {
            ans.add( i + " " + 1 + " " + 2);
        }
        ans.add(1 + " " + 2 + " " + (5735731-2*(n-2)));
        long sum = 5735731;
        m -= n-1;
        int h = 2;
        out:while (m>0){
 
            for (int i = h+1; i <= n; i++) {
                ans.add(h + " " + i +" " + (sum + sum));
                m--;
                if(m == 0){
                    break out;
                }
            }
            h++;
        }
        out.println(2 + " " + sum);
        for(String s: ans){
            out.println(s);
        }
 
    }
}
