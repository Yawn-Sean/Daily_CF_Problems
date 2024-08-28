import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Test2 {

    private static final int maxn = 200002;
    private static char[] str = new char[maxn];
    private static int[][] pre = new int[maxn][26];

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        Arrays.fill(str, '#');
        String s = st.nextToken();
        int len = s.length();
        for (int i = 1; i <= len; i++) {
            str[i] = s.charAt(i - 1);
            // 每个位置每种字符的数量前缀和
            pre[i][str[i] - 'a']++;
            for (int j = 0; j < 26; j++)
                pre[i][j] += pre[i - 1][j];
        }
        st = new StringTokenizer(f.readLine());
        int q = Integer.parseInt(st.nextToken());
        while (q-- > 0) {
            st = new StringTokenizer(f.readLine());
            int left = Integer.parseInt(st.nextToken());
            int right = Integer.parseInt(st.nextToken());
            if (right == left || str[left] != str[right])
                pw.println("Yes");
            else {
                int cnt = 0;
                for (int i = 0; i < 26; i++) {
                    if (pre[left - 1][i] != pre[right][i])
                        cnt++;
                }
                // 区间两端的字符数量不相等的字符种类至少要有3个
                pw.println(cnt >= 3 ? "Yes" : "No");
            }
        }
        pw.close();
        f.close();
    }

}
