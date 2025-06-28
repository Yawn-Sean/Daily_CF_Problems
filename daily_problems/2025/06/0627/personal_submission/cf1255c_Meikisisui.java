import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        Set<Integer>[] next = new HashSet[n + 1];
        Map<Integer, Integer> cnt = new HashMap<>();
        int[] res = new int[n + 1];
        boolean[] visited = new boolean[n + 1];
        for (int ez = 1; ez <= n; ez++)
            next[ez] = new HashSet<>();
        for (int ez = 0; ez < n - 2; ez++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            next[a].add(b);
            next[a].add(c);
            next[b].add(a);
            next[b].add(c);
            next[c].add(a);
            next[c].add(b);
            cnt.put(a, cnt.getOrDefault(a, 0) + 1);
            cnt.put(b, cnt.getOrDefault(b, 0) + 1);
            cnt.put(c, cnt.getOrDefault(c, 0) + 1);
        }
        for (int ez = 1; ez <= n; ez++) {
            if (cnt.getOrDefault(ez, 0) == 1) {
                res[1] = ez;
                break;
            }
        }
        for (int neighbor : next[res[1]])
            cnt.put(neighbor, cnt.getOrDefault(neighbor, 0) - 1);
        for (int neighbor : next[res[1]]) {
            if (cnt.getOrDefault(neighbor, 0) == 1) {
                res[2] = neighbor;
                break;
            }
        }
        for (int neighbor : next[res[1]]) {
            if (neighbor != res[2]) {
                res[3] = neighbor;
                break;
            }
        }
        visited[res[1]] = true;
        visited[res[2]] = true;
        visited[res[3]] = true;
        int index = 3;
        int now = index - 1;
        while (now <= n + 1) {
            boolean finish = true;
            now = index - 1;
            for (int neighbor : next[res[now]]) {
                if (!visited[neighbor]) {
                    res[++index] = neighbor;
                    finish = false;
                    visited[neighbor] = true;
                    break;
                }
            }
            if (finish)
                break;
        }
        for (int ez = 1; ez <= index; ez++)
            pw.print(res[ez] + " ");
        pw.close();
        br.close();
    }

}
