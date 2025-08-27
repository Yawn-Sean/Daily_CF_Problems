import java.io.*;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        while (t-- > 0) {
            st = new StringTokenizer(br.readLine());
            char[] ch = st.nextToken().toCharArray();
            int n = ch.length;
            int res = 0;
            for (int len = 1; len <= n / 2; len++) {
                int nowLen = 0;
                for (int ez = 0; ez < n - len; ez++) {
                    if (ch[ez] == ch[ez + len] || '?' == ch[ez] || '?' == ch[ez + len]) {
                        nowLen++;
                        if (nowLen == len) {
                            res = Math.max(res, nowLen);
                            break;
                        }
                    } else
                        nowLen = 0;
                }
            }
            pw.println(res * 2);
        }
        pw.close();
    }

}
