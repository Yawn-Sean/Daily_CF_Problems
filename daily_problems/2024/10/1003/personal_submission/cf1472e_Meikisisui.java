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
        int t = Integer.parseInt(st.nextToken());
        for (int ez = 0; ez < t; ez++) {
            st = new StringTokenizer(f.readLine());
            int n = Integer.parseInt(st.nextToken());
            int edge[][] = new int[n][3];
            for (int vn = 0; vn < n; vn++) {
                st = new StringTokenizer(f.readLine());
                edge[vn][0] = Integer.parseInt(st.nextToken());
                edge[vn][1] = Integer.parseInt(st.nextToken());
                edge[vn][2] = vn;
            }
            int res[] = new int[n];
            int right[][] = new int[n][2];
            Arrays.fill(res, -1);
            Arrays.sort(edge, (a, b) -> {
                return b[0] - a[0];
            });
            right[n - 1][0] = edge[n - 1][1];
            right[n - 1][1] = edge[n - 1][2];
            for (int vn = n - 2; vn >= 0; vn--) {
                if (edge[vn][1] < right[vn + 1][0]) {
                    right[vn][0] = edge[vn][1];
                    right[vn][1] = edge[vn][2];
                } else {
                    right[vn][0] = right[vn + 1][0];
                    right[vn][1] = right[vn + 1][1];
                }
            }
            for (int vn = 0; vn < edge.length; vn++) {
                int ks = vn;
                while (ks < edge.length && edge[ks][0] == edge[vn][0])
                    ks++;
                for (int k = vn; k < ks; k++) {
                    if (ks < edge.length && right[ks][0] < edge[k][1])
                        res[edge[k][2]] = right[ks][1] + 1;
                }
                vn = ks - 1;
            }
            int arr[][] = new int[edge.length][3];
            for (int vn = 0; vn < edge.length; vn++) {
                arr[vn][0] = edge[vn][0];
                arr[vn][1] = edge[vn][1];
                arr[vn][2] = edge[vn][2];
            }
            Arrays.sort(arr, (a, b) -> {
                return b[1] - a[1];
            });
            right[n - 1][0] = arr[n - 1][0];
            right[n - 1][1] = arr[n - 1][2];
            int ks = 0;
            for (int vn = n - 2; vn >= 0; vn--) {
                if (arr[vn][0] < right[vn + 1][0]) {
                    right[vn][0] = arr[vn][0];
                    right[vn][1] = arr[vn][2];
                } else {
                    right[vn][0] = right[vn + 1][0];
                    right[vn][1] = right[vn + 1][1];
                }
            }
            for (int vn = 0; vn < edge.length; vn++) {
                int h = edge[vn][0];
                int w = edge[vn][1];
                int index = edge[vn][2];
                while (ks < arr.length && arr[ks][1] >= h)
                    ks++;
                if (ks < arr.length && right[ks][0] < w)
                    res[index] = right[ks][1] + 1;
            }
            for (int vn : res)
                pw.print(vn + " ");
            pw.println();
        }

        pw.close();
        f.close();
    }

}
