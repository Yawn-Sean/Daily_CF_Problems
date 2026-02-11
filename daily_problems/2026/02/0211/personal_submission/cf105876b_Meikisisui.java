import java.io.*;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        if (n % 4 == 3)
            pw.println("-1");
        else {
            for (int ez = 1; ez <= n; ez++) {
                if (ez % 4 == 3)
                    pw.print((ez + 1) + " ");
                else if (ez % 4 == 0)
                    pw.print((ez - 1) + " ");
                else
                    pw.print(ez + " ");
            }
        }
        pw.close();
    }

}
