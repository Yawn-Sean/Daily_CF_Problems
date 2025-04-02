//https://codeforces.com/problemset/submission/766/313558622
import java.util.Arrays;
import java.util.Scanner;

public class C766 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        String s=sc.next();
        int[]a=new int[26];
        for (int i = 0; i < a.length; i++) {
            a[i]=sc.nextInt();
        }
        sc.close();
        int[]dp=new int[n+1];
        dp[0]=1;
        int mod=(int)1e9+7;
        for (int i = 0; i < n; i++) {
            int max=n;
            for (int j = i; j < n; j++) {
                max=Math.min(max, a[s.charAt(j)-'a']);
                if(j-i+1>max){
                    break;
                }
                dp[j+1]+=dp[i];
                if(dp[j+1]>=mod){
                    dp[j+1]%=mod;
                }
            }
        }
        System.out.println(dp[n]);
        Arrays.fill(dp, 0);
        for (int i = 0; i < n; i++) {
            int max=n;
            for (int j = i; j < n; j++) {
                max=Math.min(max, a[s.charAt(j)-'a']);
                if(j-i+1>max){
                    break;
                }
                dp[j+1]=Math.max(dp[j+1], Math.max(dp[i],j-i+1));
            }
        }
        System.out.println(dp[n]);
        Arrays.fill(dp, n);
        dp[0]=0;
        for (int i = 0; i < n; i++) {
            int max=n;
            for (int j = i; j < n; j++) {
                max=Math.min(max, a[s.charAt(j)-'a']);
                if(j-i+1>max){
                    break;
                }
                dp[j+1]=Math.min(dp[j+1], dp[i]+1);
            }
        }
        System.out.println(dp[n]);
    }
}
