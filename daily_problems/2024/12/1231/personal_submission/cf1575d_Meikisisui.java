import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Test3 {

    private static int n;
    private static char[] ch = new char[10];

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        String s = " " + st.nextToken();
        ch = s.toCharArray();
        n = s.length() - 1;
        if (n == 1)
            pw.println((ch[1] == '_' || ch[1] == 'X' || ch[1] == '0') ? "1" : "0");
        else {
            int k = 1;
            int res = 0;
            for (int ez = 2; ez <= n; ez++)
                k *= 10;
            for (int ez = k + (25 - k % 25) % 25; ez < k * 10; ez += 25) {
                if (check(ez))
                    res++;
            }
            pw.println(res);
        }
        pw.close();
        f.close();
    }

    private static boolean check(int wei) {
        int diwei = -1;
        for (int ez = n; ez >= 1; ez--) {
            // 枚举每一位
            int yu = wei % 10;
            wei /= 10;
            if (Character.isDigit(ch[ez]) && ch[ez] - '0' != yu)
                return false;
            if (ch[ez] == 'X') {
                // 记录x表示的数
                if (diwei == -1)
                    diwei = yu;
                    // x表示的数不一样
                else if (diwei != yu)
                    return false;
            }
        }
        return true;
    }

}
