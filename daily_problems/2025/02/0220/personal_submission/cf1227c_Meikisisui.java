import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        while (t-- > 0) {
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());
            String str = br.readLine();
            List<int[]> res = new ArrayList<>();
            // 最左边的右括号的位置
            int pos = 1;
            // 括号个数
            int cnt = 0;
            boolean isRight = false;
            // 把字符串首先改成(((())))的形式，此时是1
            // 如果k为3，就把2和5对换，3和6对换
            for (int ez = 0; ez < n; ez++) {
                if (str.charAt(ez) == '(') {
                    cnt++;
                    if (!isRight)
                        pos++;
                    else {
                        if (ez + 1 < n && str.charAt(ez + 1) == '(')
                            continue;
                        else {
                            res.add(new int[]{pos, ez + 1});
                            isRight = false;
                            pos = cnt + 1;
                        }
                    }
                }
                if (str.charAt(ez) == ')')
                    isRight = true;
            }
            if (k != 1) {
                res.add(new int[]{k, n / 2 + k - 1});
                cnt = k - 2;
                int s = 2;
                while (cnt-- > 0) {
                    res.add(new int[]{s, s + cnt + 1});
                    s += 2;
                }
            }
            pw.println(res.size());
            for (int[] pair : res)
                pw.println(pair[0] + " " + pair[1]);
        }
        pw.close();
        br.close();
    }

}
