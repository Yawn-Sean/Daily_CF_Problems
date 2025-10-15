import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Test3 {

    private static int n, pn, xn;
    private static int[] ppre;
    private static int[] xpre;
    private static char[] ch;

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        n = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(f.readLine());
        String s = st.nextToken();
        ch = s.toCharArray();
        pn = 0;
        xn = 0;
        ppre = new int[n + 1];
        xpre = new int[n + 1];
        for (int ez = 0; ez < n; ez++) {
            if (ch[ez] == 'P')
                ppre[pn++] = ez;
            if (ch[ez] == '*')
                xpre[xn++] = ez;
        }
        int left = 0, right = 2 * n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (check(mid))
                right = mid;
            else
                left = mid + 1;
        }
        pw.println(right);
        pw.close();
        f.close();
    }

    private static int calc(int left, int right, int pos) {
        return Math.min(Math.abs(pos - left), Math.abs(pos - right)) + Math.abs(right - left);
    }

    private static boolean check(int temp) {
        int pre = -1, pos = -1;
        for (int ez = 0; ez < pn; ez++) {
            while (pos < xn - 1 && calc(xpre[pre + 1], xpre[pos + 1], ppre[ez]) <= temp)
                ++pos;
            pre = pos;
        }
        return pos == xn - 1;
    }

}
