import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        String[] str = new String[3];
        Map<Character, Integer>[] cntMap = new HashMap[3];
        int[] cnt = new int[3];
        for (int ez = 0; ez < 3; ez++)
            str[ez] = br.readLine();
        int len = str[0].length();
        for (int ez = 0; ez < 3; ez++) {
            int tmpMax = 0;
            cntMap[ez] = new HashMap<>();
            for (int vn = 0; vn < len; vn++) {
                char ch = str[ez].charAt(vn);
                cntMap[ez].put(ch, cntMap[ez].getOrDefault(ch, 0) + 1);
                tmpMax = Math.max(tmpMax, cntMap[ez].get(ch));
            }
            cnt[ez] = tmpMax;
        }
        for (int ez = 0; ez < 3; ez++) {
            if (len == cnt[ez] && 1 == n)
                cnt[ez]--;
            else {
                cnt[ez] += n;
                cnt[ez] = Math.min(cnt[ez], len);
            }
        }
        if (cnt[0] > cnt[1] && cnt[0] > cnt[2])
            pw.println("Kuro");
        else if (cnt[1] > cnt[2] && cnt[1] > cnt[0])
            pw.println("Shiro");
        else if (cnt[2] > cnt[0] && cnt[2] > cnt[1])
            pw.println("Katie");
        else
            pw.println("Draw");
        pw.close();
        br.close();
    }

}
