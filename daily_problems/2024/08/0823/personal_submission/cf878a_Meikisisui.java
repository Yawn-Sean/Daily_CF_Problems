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
        int a = 0, b = 1023;
        for (int ez = 0; ez < n; ez++) {
            st = new StringTokenizer(f.readLine());
            char ch = st.nextToken().charAt(0);
            int x = Integer.parseInt(st.nextToken());
            if (ch == '|') {
                a |= x;
                b |= x;
            } else if (ch == '^') {
                a ^= x;
                b ^= x;
            } else if (ch == '&') {
                a &= x;
                b &= x;
            }
        }
        // or, xor, and
        int c = 0, d = 0, e = 0;
        for (int i = 0; i <= 10; i++) {
            int tmp = 1 << i;
            int x = (a & tmp) >> i;
            int y = (b & tmp) >> i;
            if (x == 1 && y == 1) {
                c |= tmp;
                e |= tmp;
            } else if (x == 1 && y == 0) {
                d |= tmp;
                e |= tmp;
            } else if (x == 0 && y == 1)
                e |= tmp;
        }
        pw.println(3);
        pw.println("| " + c);
        pw.println("^ " + d);
        pw.println("& " + e);
        pw.close();
        f.close();
    }

}
