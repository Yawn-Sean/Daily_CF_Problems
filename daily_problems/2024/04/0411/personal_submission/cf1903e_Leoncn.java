package daily_problems.2024.04.0411.personal_submission;

public class cf1903e_Leoncn {
    static RealFastReader sc = new RealFastReader(System.in);
    static PrintWriter out = new PrintWriter(System.out);
    public static void main(String[] args) {
        int t = sc.ni();
        while (t-->0){
            solve();
        }
        out.close();
    }
 
    private static void solve() {
        int n = sc.ni();
        int x = sc.ni();
        int y = sc.ni();
        Stack<Integer> s1 = new Stack<>();
        Stack<Integer> s2 = new Stack<>();
        boolean[] vis = new boolean[n+1];
        for (int i = 0; i < n; i++) {
            int a = sc.ni();
            int b = sc.ni();
            int mat = Math.abs(a+b -x-y);
            if((mat&1)==1){
                s1.add(i+1);
            }else {
                s2.add(i+1);
            }
        }
        if(s2.size()>=s1.size()){
            out.println("First");
            out.flush();
            for (int i = 0; i < n; i++) {
                if((i&1)==0){
                    while ((s1.size()>0) && (vis[s1.peek()])){
                        s1.pop();
                    }
                    int res = 0;
                    if(s1.size()==0){
                        while ((s2.size()>0) && (vis[s2.peek()])){
                            s2.pop();
                        }
                        res = s2.pop();
 
                    }else {
                        res = s1.pop();
                    }
                    vis[res] = true;
                    out.println(res);
                    out.flush();
                }else {
                    vis[sc.ni()] = true;
                }
 
            }
        }else {
            out.println("Second");
            out.flush();
            for (int i = 0; i < n; i++) {
                if((i&1)==1){
                    while ((s2.size()>0) && (vis[s2.peek()])){
                        s2.pop();
                    }
                    int res = 0;
                    if(s2.size()==0){
                        while ((s1.size()>0) && (vis[s1.peek()])){
                            s1.pop();
                        }
                        res = s1.pop();
 
                    }else {
                        res = s2.pop();
                    }
                    vis[res] = true;
                    out.println(res);
                    out.flush();
                }else {
                    vis[sc.ni()] = true;
                }
            }
        }
 
    }
}
