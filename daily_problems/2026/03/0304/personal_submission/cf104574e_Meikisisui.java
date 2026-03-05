import java.io.*;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] poker = new int[52];
        for (int ez = 0; ez < 52; ez++)
            poker[ez] = Integer.valueOf(st.nextToken());
        for (int ez = 0; ez < 8; ez++) {
            poker = shuffle(poker);
            int cnt = 0;
            for (int vn = 0; vn < 26; vn++) {
                if (poker[vn] == 1)
                    cnt++;
            }
            if (cnt == 4) {
                pw.println("YES");
                pw.close();
                return;
            }
        }
        pw.println("NO");
        pw.close();
    }

    private static int[] shuffle(int[] poker) {
        int[] res = new int[52];
        for (int ez = 0; ez < 26; ez++) {
            res[ez * 2] = poker[ez];
        }
        for (int ez = 26; ez < 52; ez++) {
            res[(ez - 26) * 2 + 1] = poker[ez];
        }
        return res;
    }

}
