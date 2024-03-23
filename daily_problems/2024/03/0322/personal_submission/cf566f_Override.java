import java.io.*;

public class Main {
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
	public static long nextLong()throws Exception{
		in.nextToken();
		return (long) in.nval;
	}
	public static int nextInt()throws Exception{
		in.nextToken();
		return (int) in.nval;
	}
  public static void main(String[] args)throws Exception {
        
        int n = nextInt();
        int[] st = new int[n];
        for (int i = 0; i < n; ++i) {
            st[i] = nextInt();
        }
        int[] dp = new int[1000010];
        int i;
        for (i = n - 1; i >= 0; --i) {
            dp[st[i]] = 1;
            for (int j = 2; st[i] * j <= st[n - 1]; ++j) {
                dp[st[i]] = Math.max(dp[st[i]], dp[st[i] * j] + 1);
            }
        }
        int sum = 0;
        for (i = 0; i < n; ++i) {
            sum = Math.max(sum, dp[st[i]]);
        }
        pw.println(sum);
        pw.flush();
    }
}
