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
            long a = Long.parseLong(st.nextToken());
            long b = Long.parseLong(st.nextToken());
            st = new StringTokenizer(br.readLine());
            char[] s = st.nextToken().toCharArray();
            int left = 0, right = n - 1;
            long res = (n + 1) * b + n * a;
            boolean flag = false;
            while (left < n && s[left] == '0')
                left++;
            while (right > 0 && s[right] == '0') {
                right--;
                flag = true;
            }
            if (flag)
                right++;
            flag = false;
            for (int ez = left; ez <= right; ) {
                int tmp = 0;
                while (s[ez] == '1') {
                    res = res + b;
                    ez++;
                    flag = true;
                }
                while (ez <= right && s[ez] == '0') {
                    tmp++;
                    ez++;
                }
                if (tmp > 0)
                    res += b;
                if (tmp > 1)
                    // 连续0，比较管道降为1好还是保持为2好
                    res += Math.min((tmp - 1) * b, 2 * a);
            }
            if (flag)
                res = res + 2 * a;
            pw.println(res);
        }
        pw.close();
    }


}
