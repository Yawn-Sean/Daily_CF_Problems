import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Test2 {

    private static int n;
    private static int[] nums;

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        n = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(f.readLine());
        nums = new int[n];
        for (int ez = 0; ez < n; ez++)
            nums[ez] = Integer.parseInt(st.nextToken());
        String res = tellYourWorld();
        pw.println(res);
        pw.close();
        f.close();
    }

    private static String tellYourWorld() {
        double k1 = (double) (nums[1] - nums[0]);
        double k2 = (double) (nums[2] - nums[1]);
        double k3 = (double) (nums[2] - nums[0]) / 2;
        if (xielv(k1) || xielv(k2) || xielv(k3))
            return "Yes";
        else
            return "No";
    }

    private static boolean xielv(double k) {
        Set<Double> set = new HashSet<>();
        for (int i = 0; i < n; i++) {
            double newK = (double) nums[i] - i * k;
            set.add(newK);
        }
        return set.size() == 2;
    }

}
