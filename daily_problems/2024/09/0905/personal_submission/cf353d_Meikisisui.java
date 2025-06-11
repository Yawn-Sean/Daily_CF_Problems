import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Test2 {

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        String str = st.nextToken();
        int n = str.length();
        long res = 0;
        int startF = 0, preM = 0;
        while (startF < n && str.charAt(startF) == 'F')
            startF++;
        for (int ez = startF; ez < n; ez++) {
            if (str.charAt(ez) == 'M')
                preM++;
            else
                res = Math.max(res + 1, preM);
        }
        pw.println(res);
        pw.close();
        f.close();
    }

}
