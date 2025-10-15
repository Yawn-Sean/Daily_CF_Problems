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
        int n = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(f.readLine());
        String s = st.nextToken();
        int[] cnt = new int[100];
        for (int ez = 0; ez < n; ez++)
            cnt[s.charAt(ez) - '0']++;
        Deque<Character> dan = new ArrayDeque<>();
        Deque<Character> shuang = new ArrayDeque<>();
        for (int ez = 0; ez < 100; ez++) {
            if (cnt[ez] > 0) {
                if (cnt[ez] % 2 == 1) {
                    cnt[ez]--;
                    dan.add((char) ez);
                }
                while (cnt[ez] > 0) {
                    cnt[ez] -= 2;
                    shuang.add((char) ez);
                }
            }
        }
        char[] res = new char[n + 1];
        if (dan.size() == 0) {
            for (int ez = 0; ez < n / 2; ez++) {
                char tmp = (char) (shuang.getLast() + '0');
                res[ez] = res[n - ez - 1] = tmp;
                shuang.pollLast();
            }
            pw.println("1");
            pw.println(new String(res, 0, n));
        } else {
            while (shuang.size() % dan.size() != 0) {
                dan.add(shuang.getLast());
                dan.add(shuang.getLast());
                shuang.pollLast();
            }
            int m = dan.size();
            int len = n / m;
            pw.println(m);
            for (int ez = 0; ez < m; ez++) {
                res[len / 2] = (char) (dan.pollFirst() + '0');
                for (int vn = 0; vn < len / 2; vn++) {
                    char tmp = (char) (shuang.getLast() + '0');
                    res[vn] = res[len - vn - 1] = tmp;
                    shuang.pollLast();
                }
                pw.print(new String(res, 0, len) + " ");
            }
        }
        pw.close();
        f.close();
    }

}
