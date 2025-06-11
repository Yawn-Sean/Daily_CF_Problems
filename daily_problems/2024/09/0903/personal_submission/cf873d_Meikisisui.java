import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Test2 {

    private static final int M = 100001;
    private static int[] a = new int[M];
    private static int cnt, n, k, kCnt;

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        for (int i = 0; i < n; i++)
            a[i] = i + 1;
        kCnt = 1;
        spring(0, n);
        if (k % 2 == 1 && k <= kCnt) {
            cnt = 1;
            dfs(0, n);
            for (int i = 0; i < n; i++)
                pw.print(a[i] + " ");
        } else
            pw.println("-1");
        pw.close();
        f.close();
    }

    static void dfs(int left, int right) {
        if (left == right - 1 || cnt == k)
            return;
        int mid = left + (right - left) / 2;
        swap(mid, mid - 1);
        cnt += 2;
        dfs(left, mid);
        dfs(mid, right);
    }

    static void spring(int left, int right) {
        int mid = left + (right - left) / 2;
        if (left == right - 1)
            return;
        kCnt += 2;
        spring(left, mid);
        spring(mid, right);
    }

    static void swap(int i, int j) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

}
