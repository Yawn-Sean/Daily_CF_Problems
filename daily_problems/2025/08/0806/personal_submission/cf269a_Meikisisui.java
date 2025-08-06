import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        Node[] box = new Node[n];
        for (int ez = 0; ez < n; ez++) {
            st = new StringTokenizer(br.readLine());
            box[ez] = new Node(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }
        Arrays.sort(box, Comparator.comparingLong(x -> x.len));
        long res = box[n - 1].len;
        for (int ez = 1; ez < n; ez++) {
            long sub = box[ez].len - box[ez - 1].len, curNum = box[ez].num, mul = 1;
            for (long vn = 1; vn <= sub; vn++) {
                mul *= 4;
                if ((mul * curNum) >= box[ez - 1].num)
                    break;
            }
            if (mul * curNum < box[ez - 1].num) {
                box[ez - 1].num -= mul * curNum;
                box[ez].num += box[ez - 1].num / mul;
                if (box[ez - 1].num % mul != 0)
                    box[ez].num++;
            }
        }
        double tmp = (double) box[n - 1].num - 0.01;
        if (box[n - 1].num == 1)
            pw.println(res + 1);
        else {
            while (tmp >= 1) {
                res++;
                tmp /= 4;
            }
            pw.println(res);
        }
        pw.close();
    }

    private static class Node {
        long len;
        long num;

        Node(long len, long num) {
            this.len = len;
            this.num = num;
        }
    }

}
