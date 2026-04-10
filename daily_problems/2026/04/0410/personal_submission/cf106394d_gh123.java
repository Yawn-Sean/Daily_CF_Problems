import java.util.Scanner;

public class cf106394d {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while (t-->0) {
            int n=sc.nextInt();
            int ans=n-1;
            int cur=0,v=0;
            while (n-->0) {
                int x=sc.nextInt();
                if(cur<0){
                    cur+=v;
                    ans++;
                }
                v=Math.max(v, x);
                cur--;
            }
            System.out.println(ans);
        }
        sc.close();
    }
}
