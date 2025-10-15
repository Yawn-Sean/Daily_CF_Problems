import java.io.*;
import java.util.*;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        while (t-- > 0) {
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            Integer[] arr = new Integer[x];
            int res = x - 2;
            st = new StringTokenizer(br.readLine());
            for (int ez = 0; ez < x; ez++)
                arr[ez] = Integer.parseInt(st.nextToken());
            Arrays.sort(arr);
            List<Integer> odd = new ArrayList<>(), even = new ArrayList<>();
            for (int ez = 1; ez < x; ez++) {
                int diff = arr[ez] - arr[ez - 1];
                if (diff == 2)
                    res++;
                else if (diff > 2) {
                    diff--;
                    if (diff % 2 == 1)
                        odd.add(diff);
                    else
                        even.add(diff);
                }
            }
            int diff = arr[0] + (n - arr[x - 1]) - 1;
            if (diff == 1)
                res++;
            else if (diff != 0 && diff % 2 == 0)
                even.add(diff);
            else if (diff % 2 != 0)
                odd.add(diff);

            if (!odd.isEmpty())
                Collections.sort(odd);

            for (Integer tmp : odd) {
                if (y == 0)
                    break;
                int max = tmp / 2;
                if (y >= max) {
                    res += ((2 * max) + 1);
                    y -= max;
                } else {
                    res += (2 * y);
                    y = 0;
                    break;
                }
            }
            for (Integer tmp : even) {
                if (y == 0)
                    break;
                int max = tmp / 2;
                int req = Math.min(max, y);
                y -= req;
                res += (2 * req);
            }
            pw.println(res);
        }
        pw.close();
    }

}
