import java.io.*;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        Glass[] glasses = new Glass[n];
        for (int ez = 0; ez < n; ez++) {
            st = new StringTokenizer(br.readLine());
            int m = Integer.parseInt(st.nextToken());
            int t = Integer.parseInt(st.nextToken());
            glasses[ez] = new Glass(m, t);
        }
        int n1 = n / 2;
        int n2 = n - n1;
        Glass[] groupA = new Glass[n1];
        Glass[] groupB = new Glass[n2];
        for (int ez = 0; ez < n1; ez++)
            groupA[ez] = glasses[ez];
        for (int ez = 0; ez < n2; ez++)
            groupB[ez] = glasses[ez + n1];
        Map<Long, Integer> mapA = new HashMap<>();
        for (int mask = 0; mask < (1 << n1); mask++) {
            long totalM = 0;
            long totalT = 0;
            for (int ez = 0; ez < n1; ez++) {
                if ((mask & (1 << ez)) != 0) {
                    totalM += groupA[ez].m;
                    totalT += groupA[ez].t;
                }
            }
            long value = (long) b * totalM - (long) a * totalT;
            mapA.put(value, mapA.getOrDefault(value, 0) + 1);
        }
        Map<Long, Integer> mapB = new HashMap<>();
        for (int mask = 0; mask < (1 << n2); mask++) {
            long totalM = 0;
            long totalT = 0;
            for (int ez = 0; ez < n2; ez++) {
                if ((mask & (1 << ez)) != 0) {
                    totalM += groupB[ez].m;
                    totalT += groupB[ez].t;
                }
            }
            long value = (long) b * totalM - (long) a * totalT;
            mapB.put(value, mapB.getOrDefault(value, 0) + 1);
        }
        long res = 0;
        for (Map.Entry<Long, Integer> entry : mapA.entrySet()) {
            long key = entry.getKey();
            int countA = entry.getValue();
            if (mapB.containsKey(-key))
                res += (long) countA * mapB.get(-key);
        }
        res--;
        pw.println(res);
        pw.close();
    }

    private static class Glass {
        int m, t;

        Glass(int m, int t) {
            this.m = m;
            this.t = t;
        }
    }

}
