import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Test3 {

    private static long sum;
    private static int[] c;
    private static int n, k, pre;

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        c = new int[n];
        sum = 0;
        st = new StringTokenizer(f.readLine());
        for (int ez = 0; ez < n; ez++) {
            c[ez] = Integer.parseInt(st.nextToken());
            sum += c[ez];
        }
        Arrays.sort(c);
        if (c[0] == c[n - 1])
            pw.println("0");
        else {
            // 分别找出最大值变成最小的数和最小值变成最大的数
            pre = (int) (sum / n);
            int left = pre, right = c[n - 1];
            if (sum % n != 0)
                left++;
            while (left < right) {
                int m = left + (right - left) / 2;
                if (isMax(m))
                    right = m;
                else
                    left = m + 1;
            }
            int max = left;
            left = c[0];
            right = pre;
            while (left < right) {
                int m = left + (right - left + 1) / 2;
                if (isMin(m))
                    left = m;
                else
                    right = m - 1;
            }
            pw.println(max - left);
        }
        pw.close();
        f.close();
    }

    private static boolean isMin(int x) {
        int tmp = k;
        int mid = lowerBound(c, n, x);
        for (int ez = 0; ez < mid; ez++) {
            tmp -= (x - c[ez]);
            if (tmp < 0) return false;
        }
        return true;
    }

    private static boolean isMax(int x) {
        int tmp = k;
        int mid = upperBound(c, n, x);
        for (int ez = mid; ez < n; ez++) {
            tmp -= (c[ez] - x);
            if (tmp < 0) return false;
        }
        return true;
    }

    private static int lowerBound(int[] array, int size, int value) {
        int left = 0, right = size;
        while (left < right) {
            int mid = (left + right) / 2;
            if (array[mid] < value)
                left = mid + 1;
            else
                right = mid;

        }
        return left;
    }

    private static int upperBound(int[] array, int size, int value) {
        int left = 0, right = size;
        while (left < right) {
            int mid = (left + right) / 2;
            if (array[mid] <= value)
                left = mid + 1;
            else
                right = mid;

        }
        return left;
    }

}
