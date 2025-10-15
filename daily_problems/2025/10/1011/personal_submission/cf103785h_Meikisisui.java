import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        List<Integer> nums = new ArrayList<>();
        st = new StringTokenizer(br.readLine());
        for (int ez = 0; ez < n; ez++)
            nums.add(Integer.parseInt(st.nextToken()));
        List<Integer> list = new ArrayList<>();
        for (int ez = n - 1; ez >= 0; ez--) {
            boolean isFound = false;
            for (int vn = ez; vn >= 0; vn--) {
                if (nums.get(vn) == vn + 1) {
                    isFound = true;
                    list.add(nums.get(vn));
                    nums.remove(vn);
                    break;
                }
            }
            if (!isFound) {
                pw.println("NO");
                pw.close();
                return;
            }
        }
        pw.println("YES");
        Collections.reverse(list);
        for (int ez = 0; ez < list.size(); ez++)
            pw.print(list.get(ez) + (ez == list.size() - 1 ? "" : " "));
        pw.close();
    }

}
