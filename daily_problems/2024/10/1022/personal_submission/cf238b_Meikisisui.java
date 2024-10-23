import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Test2 {

    static class Node {
        int x;
        int id;
        int val;

        Node(int x, int id) {
            this.x = x;
            this.id = id;
            this.val = 0;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int n = Integer.parseInt(st.nextToken());
        int h = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(f.readLine());
        Node[] a = new Node[n + 1];
        for (int ez = 1; ez <= n; ez++) {
            int x = Integer.parseInt(st.nextToken());
            a[ez] = new Node(x, ez);
        }
        Arrays.sort(a, 1, n + 1, (x, y) -> Integer.compare(x.x, y.x));
        if (n == 2) {
            pw.println("0");
            pw.println("1 1");
        } else {
            if (Math.max(a[n].x + a[n - 1].x, a[1].x + a[n].x + h) - Math.min(a[1].x + a[2].x + h, a[2].x + a[3].x)
                    < a[n].x + a[n - 1].x - a[1].x - a[2].x)
                a[1].val = 1;
            int result = Math.min(Math.max(a[n].x + a[n - 1].x, a[1].x + a[n].x + h)
                    - Math.min(a[1].x + a[2].x + h, a[2].x + a[3].x), a[n].x + a[n - 1].x - a[1].x - a[2].x);
            pw.println(result);
            Arrays.sort(a, 1, n + 1, (x, y) -> Integer.compare(x.id, y.id));
            for (int i = 1; i <= n; i++) {
                pw.print(a[i].val == 0 ? 2 : 1);
                pw.print(i == n ? "\n" : " ");
            }
        }
        pw.close();
        f.close();
    }

}
