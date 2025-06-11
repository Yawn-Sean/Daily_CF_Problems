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
        int m = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int[] socks = new int[n];
        List<List<Integer>> list = new ArrayList<>();
        boolean[] visited = new boolean[n];
        st = new StringTokenizer(f.readLine());
        for (int ez = 0; ez < n; ez++) {
            socks[ez] = Integer.parseInt(st.nextToken()) - 1;
            list.add(new ArrayList<>());
        }
        for (int ez = 0; ez < m; ez++) {
            st = new StringTokenizer(f.readLine());
            int left = Integer.parseInt(st.nextToken()) - 1;
            int right = Integer.parseInt(st.nextToken()) - 1;
            list.get(left).add(right);
            list.get(right).add(left);
        }
        int count = 0;
        for (int ez = 0; ez < n; ez++) {
            if (visited[ez])
                continue;
            Map<Integer, Integer> map = new HashMap<>();
            helper(ez, visited, map, list, socks);
            int max = -1, total = 0;
            for (Integer key : map.keySet()) {
                total += map.get(key);
                max = Math.max(max, map.get(key));
            }
            count += total - max;
        }
        pw.println(count);
        pw.close();
        f.close();
    }

    private static void helper(int ez, boolean[] visited, Map<Integer, Integer> map, List<List<Integer>> list, int[] socks) {
        if (visited[ez])
            return;
        visited[ez] = true;
        map.put(socks[ez], map.getOrDefault(socks[ez], 0) + 1);
        for (int vn : list.get(ez))
            helper(vn, visited, map, list, socks);
    }

}
