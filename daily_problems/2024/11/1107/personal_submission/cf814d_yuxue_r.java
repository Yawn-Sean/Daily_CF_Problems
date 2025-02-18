import java.util.*;
import java.io.*;
import java.util.function.BiFunction;
import java.util.function.LongUnaryOperator;

public class cf1201h {
    public static void main(String[] args) {
        FastReader fr = new FastReader();
        PrintWriter out = new PrintWriter(System.out);

        int n = fr.nextInt();
        int[][] circles = new int[n][3];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                circles[i][j] = fr.nextInt();
            }
        }

        Arrays.sort(circles, (x, y) -> y[2] - x[2]);
        LongUnaryOperator sqr = x -> 1L * x * x;
        BiFunction<Integer, Integer, Boolean> isin = (x, y) ->
                sqr.applyAsLong(circles[x][0] - circles[y][0]) +
                        sqr.applyAsLong(circles[x][1] - circles[y][1]) <=
                        sqr.applyAsLong(circles[x][2] - circles[y][2]);

        int[] times = new int[n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (isin.apply(i, j)) {
                    times[i]++;
                }
            }
        }

        long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += sqr.applyAsLong(circles[i][2]) * ((Math.max(0, times[i] - 1) & 1) == 1 ? -1 : 1);
        }

        double pi = Math.acos(-1);
        out.printf("%.20f", pi * ans);

        out.flush();
    }
}
