//https://codeforces.com/problemset/submission/183/328315189
import java.util.Arrays;
import java.util.Scanner;
 
public class B183 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();
        int[]x=new int[m];
        int[]y=new int[m];
        for (int i = 0; i < m; i++) {
            x[i]=sc.nextInt();
            y[i]=sc.nextInt();
        }
        int[]cnt=new int[n+1];
        Arrays.fill(cnt, 1);
        cnt[0]=0;
        //ax+by+c=0->ab-ba=0,
        for (int i = 0; i < m; i++) {
            for (int j = i+1; j < m; j++) {
                long a=y[i]-y[j];
                long b=x[j]-x[i];
                long c=-((long)a*x[i]+(long)b*y[i]);
                int same=0;
                for (int k = 0; k < m; k++) {
                    if(a*x[k]+b*y[k]+c==0){
                        same++;
                    }
                }
                if(a!=0&&c%a==0){
                    long val=-c/a;
                    if(val>=1&&val<=n){
                        cnt[(int)val]=Math.max(cnt[(int)val], same);
                    }
                }
            }
        }
        long ans=0;
        for (int i : cnt) {
            ans+=i;
        }
        System.out.println(ans);
        sc.close();
    }
}
