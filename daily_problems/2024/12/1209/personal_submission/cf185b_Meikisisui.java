import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        double s = Double.parseDouble(st.nextToken());
        st = new StringTokenizer(f.readLine());
        double a = Double.parseDouble(st.nextToken());
        double b = Double.parseDouble(st.nextToken());
        double c = Double.parseDouble(st.nextToken());
        double res = 0, sum = a + b + c;
        if (sum == 0)
            pw.println("0 0 0");
        else {
            double x = a * s / sum;
            double y = b * s / sum;
            double z = c * s / sum;
            pw.println(x + " " + y + " " + z);
        }
        pw.close();
        f.close();
    }

}
