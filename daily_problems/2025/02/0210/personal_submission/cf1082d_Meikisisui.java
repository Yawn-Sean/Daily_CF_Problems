import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int res = 1;
        Pair[] a = new Pair[n + 1];
        int[] side = new int[n + 1];
        int[] from = new int[n + 1];
        int[] to = new int[n + 1];
        int total = 0;
        int index = 0;
        st = new StringTokenizer(br.readLine());
        for (int ez = 1; ez <= n; ez++)
            a[ez] = new Pair(Integer.parseInt(st.nextToken()), ez);
        Arrays.sort(a, 1, n + 1);
        // 度要求最小的两个点做直径端点
        side[++index] = a[1].second;
        side[++index] = a[2].second;
        int pre = side[1], back = 0;
        for (int ez = 3; ez <= n; ez++) {
            if (a[ez].first > 1) {
                from[++total] = pre;
                to[total] = a[ez].second;
                pre = a[ez].second;
                res++;
                if (back == 0)
                    back = ez;
            }
        }
        total++;
        from[total] = pre;
        to[total] = side[2];
        // 变量写的有点多了应该能省省
        int pos = back;
        boolean isFalse = true;
        for (int ez = 3; ez < back; ez++) {
            if (a[ez].first == 1) {
                while (a[pos].first <= 2) {
                    pos++;
                    if (pos == n + 1) {
                        isFalse = false;
                        break;
                    }
                }
                if (!isFalse)
                    break;
                a[pos].first--;
                total++;
                from[total] = a[ez].second;
                to[total] = a[pos].second;
            } else
                break;
        }
        if (!isFalse || total != n - 1) {
            pw.println("NO");
        } else {
            pw.println("YES " + res);
            pw.println(n - 1);
            for (int ez = 1; ez <= total; ez++)
                pw.println(from[ez] + " " + to[ez]);
        }
        pw.close();
        br.close();
    }

    private static class Pair implements Comparable<Pair> {
        int first, second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }

        @Override
        public int compareTo(Pair other) {
            return Integer.compare(this.first, other.first);
        }
    }

}
