package daily_problems.2024.04.0420.personal_submission;

public class cf1031c_Leoncn {
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
        long q = (long)Math.sqrt(2L*(n+m));
        if(q*(q+1)>2L*(n+m)){
            q--;
        }
        List<Long> ans1 = new ArrayList<>();
        List<Long> ans2 = new ArrayList<>();
        while ((n>0 || m>0)&&q>0){
            if(n>=q){
                ans1.add(q);
                n-=q;

            }else {
                ans2.add(q);
                m-=q;
            }
            q--;
        }
        out.println(ans1.size());
        out.println(print(ans1));
        out.println(ans2.size());
        out.println(print(ans2));


    }
    private static String print(List<Long> ans){
        StringBuilder sb = new StringBuilder();
        for(long a: ans){
            sb.append(a).append(" ");
        }
        return sb.toString();
    }
}
