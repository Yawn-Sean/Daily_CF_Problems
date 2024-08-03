package daily_problems.2024.04.0415.personal_submission;

public class cf933a_Leoncn {
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
        int[] g = sc.na(n);
        int dp1 = 0, dp12 = 0, dp121 = 0, dp1212 = 0;
        for(int a: g){
            if(a == 1){
                dp1 ++;
                dp121++;
            }else {
                dp12++;
                dp1212++;
            }
            dp12 = Math.max(dp1, dp12);
            dp121 = Math.max(dp12, dp121);
            dp1212 = Math.max(dp1212 , dp121);
        }
        out.println(dp1212);


    }

}
