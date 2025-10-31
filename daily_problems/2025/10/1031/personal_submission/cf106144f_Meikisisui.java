import java.io.*;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        while (t-- > 0) {
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int halfLine = 0, line = 0;
            for (int ez = 0; ez < n; ez++) {
                String str = br.readLine();
                str = str.replaceAll("===", "");
                if ("xxx".equals(str))
                    line++;
                else if (".xx".equals(str) || "xx.".equals(str))
                    halfLine++;
            }
            if (halfLine % 2 == 0 && line % 2 == 0)
                pw.println("Polycarp");
            else
                pw.println("Monocarp");
        }
        pw.close();
    }

}
