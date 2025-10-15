import java.io.*;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Test3 {

    private static int[][] a = new int[12][1001];
    private static int[] cnt = new int[12];

    public static void main(String[] args) throws IOException {
        Scanner sc=new Scanner(new File("input.txt"));
        PrintWriter pw = new PrintWriter("output.txt");
        int n = Integer.parseInt(sc.next());
        int res = 0;
        while ((1 << res) < n) {
            res++;
        }
        Arrays.fill(cnt, 0);
        pw.println(res);
        dfs(1, n, 1);
        for (int ez = 1; ez <= res; ez++) {
            pw.print(cnt[ez]);
            for (int vn = 0; vn < cnt[ez]; vn++) 
                pw.print(" " + a[ez][vn]);
            pw.println();
        }
        pw.close();
        sc.close();
    }

    private static void dfs(int left, int right, int d) {
        int mid = left + (right - left) / 2;
        for (int ez = left; ez <= mid; ez++) {
            a[d][cnt[d]++] = ez;
        }
        if (left < right) {
            dfs(left, mid, d + 1);
            dfs(mid + 1, right, d + 1);
        }
    }

}
