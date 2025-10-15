import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Deque;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int n = Integer.parseInt(st.nextToken());
        int q = Integer.parseInt(st.nextToken());
        // 每个应用产生消息的时间队列的数组
        Deque<Integer>[] queue = new LinkedList[n + 1];
        // 产生消息的时间-产生消息的应用的队列
        Deque<Pair> time = new LinkedList<>();
        // 消息已读时间
        boolean[] visit = new boolean[q + 1];
        // 未读消息（类型）数量，目前时刻(只在type==1时自增)
        int res = 0, now = 1;
        for (int ez = 0; ez <= n; ez++)
            queue[ez] = new LinkedList<>();
        while (q-- > 0) {
            st = new StringTokenizer(f.readLine());
            int type = Integer.parseInt(st.nextToken());
            int num = Integer.parseInt(st.nextToken());
            if (1 == type) {
                // 把应用进入的时间放进queue[num]队列中，把该时间和应用的序号放入time中
                time.add(new Pair(now, num));
                queue[num].add(now++);
                res++;
            } else if (2 == type) {
                // 弹出queue[num]的全部元素，并且记录着弹出元素的位置到visit中
                while (!queue[num].isEmpty()) {
                    visit[queue[num].pollFirst()] = true;
                    res--;
                }
            } else if (3 == type) {
                // 从time队列依次取数到num，如果该时刻已经visit，跳过
                // 否则弹出queue[取时刻数所对应的应用]的最早元素
                // 如果弹出全部元素，会在第4的用例的第48行查询wa……刚好在要数死还没数死我的边缘
                while (!time.isEmpty() && time.peekFirst().first <= num) {
                    if (!visit[time.peekFirst().first]) {
//                        while (!queue[time.peekFirst().second].isEmpty()) {
//                            queue[time.peekFirst().second].pollFirst();
//                            res--;
//                        }
                        queue[time.peekFirst().second].pollFirst();
                        res--;
                    }
                    time.pollFirst();
                }
            }
            pw.println(res);
        }
        pw.close();
        f.close();
    }

    private static class Pair {
        int first, second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

}
