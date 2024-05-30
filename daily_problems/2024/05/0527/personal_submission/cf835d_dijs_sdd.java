import java.util.Scanner;

public class cf835D {
    static char[] s;
    static int n;
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String str = scan.next();
        s = str.toCharArray();
        n = s.length;
        int[][] dp = new int[n + 2][n + 2];
        int[] ans = new int[n + 1];
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if(s[i]==s[j]&&(len==2||dp[i+1][j-1]>0))
                    dp[i][j]=dp[i][i+len/2-1]+1;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                ans[dp[i][j]]++;
            }
        }
        for(int i=n;i>0;i--){
            ans[i-1]+=ans[i];
        }
        for(int i = 1; i <= n; i++) {
            System.out.print(ans[i] + " ");
        }
    }
}



