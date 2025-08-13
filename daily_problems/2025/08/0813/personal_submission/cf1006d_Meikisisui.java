import java.io.*;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        String a = st.nextToken();
        st = new StringTokenizer(br.readLine());
        String b = st.nextToken();
        int cnt = 0;
        if (n % 2 == 1)
            cnt = a.charAt(n / 2) == b.charAt(n / 2) ? 0 : 1;
        for (int ez = 0; ez < n / 2; ez++) {
            if ((a.charAt(ez) == a.charAt(n - ez - 1) && b.charAt(ez) == b.charAt(n - ez - 1))
                    || (a.charAt(ez) == b.charAt(ez) && a.charAt(n - ez - 1) == b.charAt(n - ez - 1))
                    || (a.charAt(ez) == b.charAt(n - ez - 1) && a.charAt(n - ez - 1) == b.charAt(ez)))
                continue;
            Set<Character> cntSet = new HashSet<>();
            cntSet.add(a.charAt(ez));
            cntSet.add(a.charAt(n - ez - 1));
            cntSet.add(b.charAt(ez));
            cntSet.add(b.charAt(n - ez - 1));
            if (cntSet.size() == 4)
                cnt += 2;
            else if (cntSet.size() == 3) {
                if (a.charAt(ez) == a.charAt(n - ez - 1))
                    cnt += 2;
                else
                    cnt++;
            } else if (cntSet.size() == 2)
                cnt++;
        }
        pw.println(cnt);
        pw.close();
    }

}
