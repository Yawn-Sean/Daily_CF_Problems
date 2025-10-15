import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
//        BufferedReader f = new BufferedReader(new InputStreamReader(Files.newInputStream(Paths.get("input.txt"))));
//        PrintWriter pw = new PrintWriter(Files.newOutputStream(Paths.get("output.txt")));
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int L = Integer.parseInt(st.nextToken());
        char[] a = new char[1000001];
        char[] ans = new char[1000001];
        char[] jie = new char[1000001];
        st = new StringTokenizer(f.readLine());
        String A = st.nextToken();
        System.arraycopy(A.toCharArray(), 0, a, 1, A.length());
        int len = A.length();
        boolean flag = false;
        for (int ez = 1; ez <= len; ez++) {
            if (a[ez] != '9') {
                flag = true;
                break;
            }
        }
        if (len % L != 0 || !flag) {
            ans[1] = '1';
            for (int ez = 2; ez <= L; ez++)
                ans[ez] = '0';
            ans[L + 1] = '\0';
            int temp = 0;
            while (temp <= len) {
                pw.print(new String(ans, 1, L));
                temp += L;
            }
        } else {
            for (int ez = 1; ez <= L; ez++)
                ans[ez] = a[ez];
            ans[L + 1] = '\0';
            boolean tak = false;
            int temp = 1;
            while (true) {
                if (temp >= len / L) break;
                int j = 1;
                for (int ez = temp * L + 1; ez <= (temp + 1) * L; ez++)
                    jie[j++] = a[ez];
                jie[j] = '\0';
                int k = new String(ans, 1, L).compareTo(new String(jie, 1, L));
                if (k > 0) {
                    tak = true;
                    break;
                } else if (k != 0)
                    break;
                temp++;
            }
            if (!tak) {
                for (int ez = L; ez >= 1; ez--) {
                    if (a[ez] == '9')
                        ans[ez] = '0';
                    else {
                        ans[ez] = (char) (a[ez] + 1);
                        for (int j = ez - 1; j >= 1; j--)
                            ans[j] = a[j];
                        break;
                    }
                }
                if (ans[1] == '0') {
                    for (int ez = 1; ez <= L; ez++)
                        ans[ez] = '9';
                }
                ans[L + 1] = '\0';
            }
            for (int ez = 1; ez <= len / L; ez++)
                pw.print(new String(ans, 1, L));
        }
        pw.close();
        f.close();
    }

}
