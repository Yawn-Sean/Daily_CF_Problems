
import java.util.Scanner;

public class cf104408c {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while (t-->0) {
         int n=sc.nextInt(),m=sc.nextInt();
         int[]cnt=new int[m];
         for (int i = 0; i < n; i++) {
            String s=sc.next();
            if(s.charAt(m-1)=='1'){
                cnt[m-1]++;
            }
            for (int j = 0; j < m-1; j++) {
                if(s.charAt(j)!=s.charAt(j+1)){
                    cnt[j]++;
                }
            }
         }
         int ans=0;
         for (int c : cnt) {
            ans+=Math.min(c, n-c);
         }
         System.out.println(ans);
        }
        sc.close();
    }    
}
