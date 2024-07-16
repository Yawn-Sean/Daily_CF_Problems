import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
 
public class Test2 {
 
    public static void main(String[] args) throws Exception {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int n = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(f.readLine());
        Double p[] = new Double[n];
        for (int ez = 0; ez < n; ez++)
            p[ez] = Double.parseDouble(st.nextToken());
        Test2 test = new Test2();
        double res = test.andreyProblem(n, p);
        pw.println(res);
        pw.close();
    }
 
    private double andreyProblem(int n, Double[] p) {
        Arrays.sort(p);
        double res = 0, nc = 1;
        for (int ez = n - 1; ez >= 0; ez--) {
            double temp = res * (1 - p[ez]) + p[ez] * nc;
            if (temp >= 0.5)
                return temp;
            else if (temp > res) {
                res = temp;
                nc = nc * (1 - p[ez]);
            }
        }
        return res;
    }
 
}
