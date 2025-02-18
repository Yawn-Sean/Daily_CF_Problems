import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        String str = st.nextToken();
        str = str.toLowerCase();
        int n = str.length();
        int[] pre = new int[n + 1];
        int[] back = new int[n + 2];
        pre[0] = 0;
        for (int ez = 0; ez < n; ez++) {
            pre[ez + 1] = pre[ez];
            if (check(str.charAt(ez)))
                pre[ez + 1]++;
            else
                pre[ez + 1] -= 2;
        }
        back[n + 1] = Integer.MAX_VALUE;
        for (int ez = n; ez >= 0; ez--)
            back[ez] = Math.min(back[ez + 1], pre[ez]);
        int res = 0;
        int cnt = 0;
        for (int ez = 0; ez < n; ez++) {
            int left = ez, right = n + 1;
            while (left + 1 < right) {
                int mid = left + (right - left) / 2;
                if (back[mid] <= pre[ez])
                    left = mid;
                else
                    right = mid;
            }
            if (res < left - ez) {
                res = left - ez;
                cnt = 1;
            } else if (res == left - ez)
                cnt++;
        }
        if (res == 0)
            pw.println("No solution");
        else
            pw.println(res + " " + cnt);
        pw.close();
        f.close();
    }

    private static boolean check(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
        return false;
    }

}
