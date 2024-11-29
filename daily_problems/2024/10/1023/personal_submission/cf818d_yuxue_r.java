import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int a = Integer.parseInt(st.nextToken());

        int M = (int) 1e6 + 1;
        List<List<Integer>> tmp = new ArrayList<>(M);
        for (int i = 0; i < M; i++) {
            tmp.add(new ArrayList<>());
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            int x = Integer.parseInt(st.nextToken());
            tmp.get(x).add(i);
        }

        for (int i = 1; i < M; i++) {
            if (i != a && tmp.get(i).size() >= tmp.get(a).size()) {
                boolean flg = true;
                for (int j = 0; j < tmp.get(a).size(); j++) {
                    if (tmp.get(i).get(j) > tmp.get(a).get(j)) {
                        flg = false;
                        break;
                    }
                }
                if (flg) {
                    System.out.println(i);
                    return;
                }
            }
        }
        System.out.println(-1);
    }
}
