import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        List<List<Integer>> graph = new ArrayList<>();
        for (int ez = 0; ez <= n; ez++)
            graph.add(new ArrayList<>());
        int next = 100000000;
        for (int ez = 0; ez < m; ez++) {
            st = new StringTokenizer(f.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            graph.get(a).add(next);
            graph.get(b).add(next);
            next--;
        }
        for (int ez = 1; ez <= n; ez++) {
            pw.println(graph.get(ez).size() + 1);
            pw.println(ez + " " + ez);
            for (int vn = 0; vn < graph.get(ez).size(); vn++)
                pw.println(ez + " " + graph.get(ez).get(vn));
        }
        pw.close();
        f.close();
    }

}
