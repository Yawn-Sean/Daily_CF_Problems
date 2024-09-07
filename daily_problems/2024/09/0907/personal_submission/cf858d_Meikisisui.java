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
        int n = Integer.parseInt(st.nextToken());
        String[] res = new String[n + 1];
        Map<String, Integer> cntMap = new HashMap<>();
        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(f.readLine());
            String s = st.nextToken();
            res[i] = s;
            for (int j = 0; j < 9; j++) {
                for (int k = 1; k + j <= 9; k++) {
                    String sub = s.substring(j, j + k);
                    // 保存所有的子串分别是第几个s的
                    int t = cntMap.getOrDefault(sub, 0);
                    if (t == 0 || t == i)
                        cntMap.put(sub, i);
                    else
                        // 如果这个子串多于1个则舍弃
                        cntMap.put(sub, -1);
                }
            }
        }
        for (Map.Entry<String, Integer> entry : cntMap.entrySet()) {
            int index = entry.getValue();
            // 遍历map更新答案到最小值，不知道会不会tle
            if (index > 0) {
                String key = entry.getKey();
                if (res[index].length() > key.length())
                    res[index] = key;
            }
        }
        for (int i = 1; i <= n; i++)
            pw.println(res[i]);
        pw.close();
        f.close();
    }

}
