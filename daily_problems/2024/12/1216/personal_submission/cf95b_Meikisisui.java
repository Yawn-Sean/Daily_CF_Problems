import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Test3 {

    private static char[] a;
    private static char[] res;
    private static int len;

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        String n = st.nextToken();
        a = n.toCharArray();
        len = a.length;
        res = new char[len + 2];
        if (len % 2 != 0 || !dfs(0, len / 2, len / 2, false)) {
            if (len % 2 != 0)
                len++;
            else
                len += 2;
            for (int ez = 0; ez < len / 2; ez++)
                res[ez] = '4';
            for (int ez = len / 2; ez < len; ez++)
                res[ez] = '7';
        }
        pw.println(new String(res, 0, len));
        pw.close();
        f.close();
    }

    private static boolean dfs(int index, int fourCnt, int sevenCnt, boolean limit) {
        if (index >= len)
            return true;
        if (limit) {
            // 随意装剩下的了
            for (int ez = 0; ez < fourCnt; ez++)
                res[index++] = '4';
            for (int ez = 0; ez < sevenCnt; ez++)
                res[index++] = '7';
            return true;
        }
        if (fourCnt > 0 && a[index] <= '4') {
            if (dfs(index + 1, fourCnt - 1, sevenCnt, a[index] != '4')) {
                res[index] = '4';
                return true;
            }
        }
        if (sevenCnt > 0 && a[index] <= '7') {
            if (dfs(index + 1, fourCnt, sevenCnt - 1, a[index] != '7')) {
                res[index] = '7';
                return true;
            }
        }
        // 都不行了得加len+=2
        return false;
    }

}
