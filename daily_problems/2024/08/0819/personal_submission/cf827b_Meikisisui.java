import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Test2 {

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        n--;
        int len1 = n / k;
        int len2 = (n % k == 0) ? len1 : (len1 + 1);
        int res = (n % k >= 2) ? (len2 * 2) : (len1 + len2);
        pw.println(res);
        n++;
        // 以1为根，第一层有k个节点
        for (int ez = 2; ez <= k; ez++)
            pw.println(1 + " " + ez);
        // 之后每个第一层的节点，都只往下落一支子节点，始终保持k个节点度为1
        for (int ez = k + 1; ez <= n; ez++)
            pw.println(ez - k + " " + ez);
        pw.close();
        f.close();
    }

}
