import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class Test4 {

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(f.readLine());
        PrintWriter pw = new PrintWriter(System.out);
        int left = 0;
        int right = 1_000_000_000;
        pw.println("0 0");
        pw.flush();
        String last = f.readLine();
        for (int ez = 1; ez < n; ez++) {
            int middle = left + (right - left) / 2;
            pw.println(middle + " " + middle);
            pw.flush();
            String color = f.readLine();
            if (color.equals(last))
                left = middle;
            else
                right = middle;
        }
        pw.println(left + " " + right + " " + right + " " + left);
        pw.flush();
    }

}
