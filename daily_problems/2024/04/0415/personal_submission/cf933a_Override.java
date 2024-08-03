

import java.io.*;

public class a933 {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StreamTokenizer cin = new StreamTokenizer(br);
    static PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
    static int nextInt()throws  Exception{
        cin.nextToken();
        return (int) cin.nval;
    }
    static int maxe = 2003+100;
    static int[][][] dp = new int[maxe][maxe][3];
    static int[] a = new int[maxe];
    static int[] pre = new int[maxe];
    static int[] suf = new int[maxe];

    public static void main(String[] args)throws Exception {
        int n=nextInt();
        for(int i=1;i<=n;i++) a[i]=nextInt();
        for(int i=1;i<=n;i++) pre[i]=pre[i-1]+((a[i]==1)? 1:0);
        for(int i=n;i>=1;i--) suf[i]=suf[i+1]+((a[i]==2)? 1:0);
        int ans = 0;
        for(int l=1;l<=n;l++){
            for(int r=l;r<=n;r++){
                dp[l][r][2]=dp[l][r-1][2]+((a[r]==2)? 1:0);
                dp[l][r][1]=Math.max(dp[l][r-1][1],dp[l][r-1][2])+((a[r]==1)? 1:0);
                ans = Math.max(ans,pre[l-1]+Math.max(dp[l][r][1],dp[l][r][2])+suf[r+1]);
            }
        }
        pw.println(ans);
        pw.flush();
    }
}
