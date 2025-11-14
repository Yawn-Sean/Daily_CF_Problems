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
            int n = Integer.parseInt(st.nextToken());
            String s = br.readLine();
            char[] ch = s.toCharArray();
            int index = 0;
            for (; index < n; index++) {
                if (ch[index] != '?')
                    break;
            }
            if (index == n)
                pw.println(0);
            else {
                int len = 0, res = 1;
                char last = ch[index];
                for (int ez = index + 1; ez < n; ez++) {
                    char now = ch[ez];
                    if ('?' != now) {
                        res++;
                        if ((last != now && len == 1) || len > 1)
                            // 前后两个字母不同且中间问号为1个，或者连续问号大于1个
                            res++;
                        last = now;
                        len = 0;
                    } else
                        len++;
                }
                pw.println(res);
            }
        }
        pw.close();
    }

}
