//天坑！！！cf这里stoken和br混用的时候，卡win的两字符换行，eclipse和idea可能效果不同，蓝桥官网评测不受此影响。
//小心即可
import java.io.*;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;

public class d1878 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StreamTokenizer cin = new StreamTokenizer(br);
    static PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
    static int nextInt()throws  Exception{
        cin.nextToken();
        return (int) cin.nval;
    }
    public static void main(String[] args) throws Exception{
        int t = nextInt();
        while (t-- > 0) {
            solve();
        }
    }

    private static void solve() throws Exception {
        int n = nextInt();
        int k = nextInt();
        String huanhnag = br.readLine();
        char[] s = br.readLine().toCharArray();
        int[] l = new int[k+2];
        int[] r = new int[k+2];
        int[] num = new int[n + 100];

        for (int i = 1; i <= k; i++) {
            l[i]=nextInt();
        }
        for (int i = 1; i <= k; i++) {
            r[i]=nextInt();
        }
        int q = nextInt();

        for (int i = 1; i <= q; i++) {
            int x = nextInt();
            num[x]++;
        }

        int now = 1;
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            if (i > r[now]) {
                now++;
            }
            int x = Math.min(l[now] + r[now] - i, i);
            int y = Math.max(l[now] + r[now] - i, i);
            sum += num[x] + num[y];

            if (i > x) {
                continue;
            }

            if (sum % 2 == 1) {
                char temp = s[x - 1];
                s[x - 1] = s[y - 1];
                s[y - 1] = temp;
            }
        }

        pw.println(new String(s));
        pw.flush();
    }
}
