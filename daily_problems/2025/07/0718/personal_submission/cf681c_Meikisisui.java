import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        String[] in = new String[n + 1];
        int[] inInt = new int[n + 1];
        List<String> out = new ArrayList<>();
        List<Integer> outInt = new ArrayList<>();
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int ez = 1; ez <= n; ez++) {
            String[] input = br.readLine().split(" ");
            in[ez] = input[0];
            if (in[ez].charAt(0) != 'r') inInt[ez] = Integer.parseInt(input[1]);
        }
        for (int ez = 1; ez <= n; ez++) {
            if (in[ez].charAt(0) == 'i') {
                pq.add(inInt[ez]);
                out.add("insert");
                outInt.add(inInt[ez]);
            } else if (in[ez].charAt(0) == 'r') {
                // 堆为空此时不能删除堆顶元素，插入一个1
                // 否则弹出堆顶元素1次
                if (pq.isEmpty()) {
                    out.add("insert");
                    outInt.add(1);
                } else
                    pq.poll();
                out.add("removeMin");
                outInt.add(-1);
            } else {
                if (pq.isEmpty()) {
                    pq.add(inInt[ez]);
                    out.add("insert");
                    outInt.add(inInt[ez]);
                } else if (pq.peek() != inInt[ez]) {
                    while (!pq.isEmpty() && pq.peek() < inInt[ez]) {
                        // 如果堆顶元素小于getMin值不同，弹出堆顶元素直至堆为空或堆顶元素大于等于getMin值
                        pq.poll();
                        out.add("removeMin");
                        outInt.add(-1);
                    }
                    if (pq.isEmpty() || pq.peek() > inInt[ez]) {
                        // 此时如果堆为空，或堆顶元素大于getMin的值，则插入getMin的值
                        pq.add(inInt[ez]);
                        out.add("insert");
                        outInt.add(inInt[ez]);
                    }
                }
                // 最后把getMin输出
                out.add("getMin");
                outInt.add(inInt[ez]);
            }
        }
        int m = out.size();
        pw.println(m);
        for (int ez = 0; ez < m; ez++) {
            pw.print(out.get(ez));
            if (out.get(ez).charAt(0) == 'r')
                pw.println();
            else
                pw.println(" " + outInt.get(ez));
        }
        pw.close();
        br.close();
    }

}
