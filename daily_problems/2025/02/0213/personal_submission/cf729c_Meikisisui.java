import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Test3 {

    private static int n, k, s, t, isOk = 0;
    private static Cars[] car;
    private static int[] ki;
    private static int[] cha;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        s = Integer.parseInt(st.nextToken());
        t = Integer.parseInt(st.nextToken());
        car = new Cars[n + 1];
        for (int ez = 1; ez <= n; ez++) {
            st = new StringTokenizer(br.readLine());
            int c = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            car[ez] = new Cars(c, v);
        }
        ki = new int[k + 1];
        cha = new int[k + 2];
        st = new StringTokenizer(br.readLine());
        for (int ez = 1; ez <= k; ez++)
            ki[ez] = Integer.parseInt(st.nextToken());

        Arrays.sort(car, 1, n + 1);
        Arrays.sort(ki, 1, k + 1);
        cha[0] = ki[1];
        for (int ez = 1; ez <= k - 1; ez++)
            cha[ez] = ki[ez + 1] - ki[ez];
        cha[k] = s - ki[k];

        int left = 1, right = n + 1, result = 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (check(mid)) {
                result = mid;
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        int maxValue = car[result].value;
        List<Cars> ans = new ArrayList<>();
        for (int ez = 1; ez <= n; ez++) {
            if (car[ez].value >= maxValue)
                ans.add(car[ez]);
        }
        if (isOk == 0)
            pw.println("-1");
        else {
            int res = Integer.MAX_VALUE;
            for (Cars now : ans)
                res = Math.min(res, now.cost);
            pw.println(res);
        }
        pw.close();
        br.close();
    }

    private static class Cars implements Comparable<Cars> {
        int cost, value;

        Cars(int cost, int value) {
            this.cost = cost;
            this.value = value;
        }

        @Override
        public int compareTo(Cars other) {
            return Integer.compare(this.value, other.value);
        }
    }

    private static boolean check(int nw) {
        int limit = car[nw].value;
        int time = 0;
        for (int ez = 0; ez <= k; ez++) {
            if (2 * cha[ez] <= limit)
                time += cha[ez];
            else if (cha[ez] > limit / 2 && cha[ez] <= limit)
                time += (3 * cha[ez] - limit);
            else
                return false;
        }
        if (time <= t) {
            isOk = 1;
            return true;
        }
        return false;
    }

}
