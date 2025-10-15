import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        String s = st.nextToken();
        int cnt1 = 0, cnt2 = 0;
        for (int ez = 0; ez < n; ez++) {
            int one = s.charAt(ez) - '0';
            if (ez % 2 == one)
                cnt1++;
            else
                cnt2++;
        }
        pw.println(Math.min(cnt1, cnt2));
        pw.close();
        br.close();
    }


}
