//https://codeforces.com/problemset/submission/1948/335742791
import java.util.Scanner;

public class D1948 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while (t-->0) {
            char[] cs=sc.next().toCharArray();
            int n=cs.length;
            int[]dp=new int[n+1];
            int ans=0;
            for (int i = n-1; i >=0; i--) {
                for (int j = i+1; j < n; j++) {
                    if(cs[j]==cs[i]||cs[i]=='?'||cs[j]=='?'){
                        dp[j]=dp[j+1]+1;
                        if(dp[j]>=j-i){
                            ans=Math.max(ans, j-i);
                        }
                    }else{
                        dp[j]=0;
                    }
                }
            }
            System.out.println(ans*2);
        }   
        sc.close();
    }
}
