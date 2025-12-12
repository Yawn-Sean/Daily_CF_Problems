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
        long[][] stars = new long[n][2];
        for (int ez = 0; ez < n; ez++) {
            st = new StringTokenizer(br.readLine());
            stars[ez][0] = Long.parseLong(st.nextToken());
            stars[ez][1] = Long.parseLong(st.nextToken());
        }
        Set<String> starSet = new HashSet<>();
        for (long[] tmp : stars)
            starSet.add(tmp[0] + "," + tmp[1]);
        int res = 0;
        for (int ez = 0; ez < n; ez++) {
            for (int vn = 0; vn < ez; vn++) {
                long x1 = stars[ez][0];
                long y1 = stars[ez][1];
                long x2 = stars[vn][0];
                long y2 = stars[vn][1];
                long dx = x2 - x1;
                long dy = y2 - y1;
                if (starSet.contains((x1 + dx - dy) + "," + (y1 + dx + dy)) &&
                        starSet.contains((x1 - dy) + "," + (y1 + dx)))
                    res++;
                if (starSet.contains((x1 + dy) + "," + (y1 - dx)) &&
                        starSet.contains((x1 + dx + dy) + "," + (y1 + dy - dx)))
                    res++;
            }
        }
        pw.println(res / 4);
        pw.close();
    }

}
