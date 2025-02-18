import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int n = Integer.parseInt(st.nextToken());
        int p = Integer.parseInt(st.nextToken());
        double[] probabilities = new double[n];
        for (int ez = 0; ez < n; ez++) {
            st = new StringTokenizer(f.readLine());
            long l = Long.parseLong(st.nextToken());
            long r = Long.parseLong(st.nextToken());
            probabilities[ez] = calculateProbability(l, r, p);
        }
        double res = 0.0;
        for (int ez = 0; ez < n; ez++) {
            int vn = (ez + 1) % n;
            double totalProbability = 1 - (1 - probabilities[ez]) * (1 - probabilities[vn]);
            res += 2000 * totalProbability;
        }
        pw.printf("%.7f\n", res);
        pw.close();
        f.close();
    }

    private static double calculateProbability(long l, long r, int p) {
        long count = (r / p) - ((l - 1) / p);
        return (double) count / (r - l + 1);
    }

}
