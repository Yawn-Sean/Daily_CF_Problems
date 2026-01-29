import java.util.Arrays;
import java.util.Scanner;

public class F105244 {

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int m=1000;
        int[]ops=new int[m+1];
        Arrays.fill(ops, m);
        ops[0]=ops[1]=0;
        for (int i = 1; i <=m; i++) {
            for (int j = 1; j <=i; j++) {
                int next=i+i/j;
                if(next<=m){
                    ops[next]=Math.min(ops[next], ops[i]+1);
                }
            }
        }   
        int n=sc.nextInt();
        int k=sc.nextInt();
        int[]target=new int[n];
        int[]gains=new int[n];
        for (int i = 0; i < n; i++) {
            target[i]=sc.nextInt();
        }
        for (int i = 0; i < n; i++) {
            gains[i]=sc.nextInt();
        }
        int[]dp=new int[12001];
        for (int i = 0; i < n; i++) {
            int val=ops[target[i]];
            int g=gains[i];
            for (int j = 12000; j >=val; j--) {
                dp[j]=Math.max(dp[j], dp[j-val]+g);
            }
        }
        int ans=0;
        for (int i = 0; i <=12000&&i<=k; i++) {
            ans=Math.max(ans, dp[i]);
        }
        System.out.println(ans);
        sc.close();
    }
}
