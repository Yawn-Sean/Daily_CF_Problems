https://codeforces.com/problemset/submission/573/258324006
    import java.util.Scanner;

    public class B573 {
        public static void main(String[] args) {
            Scanner sc= new Scanner(System.in);
            int n=sc.nextInt();
            int[]a=new int[n+2];
            for (int i = 1; i <=n; i++) {
                a[i]=sc.nextInt();
            }
            sc.close();
            int[]l=new int[n+2];
            int[]r=new int[n+2];
            for (int i = 1; i <=n; i++) {
                l[i]=Math.min(l[i-1]+1,a[i]);
            }
            for (int i = n; i >=1; i--) {
                r[i]=Math.min(r[i+1]+1, a[i]);
            }
            int ans=0;
            for (int i = 1; i <=n; i++) {
                ans=Math.max(ans, Math.min(l[i], r[i]));
            }
            System.out.println(ans);
        }
        
    }
