import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Test3 {

    private static class Node {
        int left;
        int index;
        int right;

        Node(int left, int index) {
            this.left = left;
            this.index = index;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        Node[] c = new Node[n + 1];
        int[] color = new int[m + 1];
        st = new StringTokenizer(br.readLine());
        for (int ez = 1; ez <= n; ez++) {
            int left = Integer.parseInt(st.nextToken());
            c[ez] = new Node(left, ez);
            color[left]++;
        }
        int cnt = 0, index = -1;
        for (int ez = 1; ez <= m; ez++) {
            if (cnt < color[ez]) {
                cnt = color[ez];
                index = ez;
            }
        }
        if (cnt * 2 > n) {
            // 最多的颜色超过一半，能交换出不同颜色的孩子数量(n-cnt)*2
            pw.println((n - cnt) * 2);
            int tmp = n - cnt, vn = 0;
            for (int ez = 1; ez <= n; ez++) {
                if (c[ez].left == index) {
                    pw.print(index + " ");
                    if (tmp > 0) {
                        for (vn++; vn <= n && c[vn].left == index; vn++) ;
                        pw.println(c[vn].left);
                        tmp--;
                    } else
                        pw.println(index);
                } else
                    pw.println(c[ez].left + " " + index);
            }
        } else {
            // 最多的颜色不超过一半，所有孩子都能交换出不同颜色
            pw.println(n);
            // 先颜色排序
            Arrays.sort(c, 1, n + 1, Comparator.comparingInt(a -> a.left));
            for (int ez = 1; ez <= n; ez++) {
                // 因为相同颜色在同一堆，而且这一堆的数目最大为cnt，所以+cnt再对n取模，就不会匹配到相同颜色
                int tmp = (ez + cnt) % n;
                if (tmp == 0)
                    tmp = n;
                c[ez].right = c[tmp].left;
            }
            Arrays.sort(c, 1, n + 1, Comparator.comparingInt(a -> a.index));
            for (int ez = 1; ez <= n; ez++)
                pw.println(c[ez].left + " " + c[ez].right);
        }
        pw.close();
    }

}
