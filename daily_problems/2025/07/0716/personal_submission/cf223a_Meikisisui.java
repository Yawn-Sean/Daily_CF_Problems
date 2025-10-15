import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        char[] str = st.nextToken().toCharArray();
        int tot = 0;
        Deque<Data> dq = new ArrayDeque<>();
        Deque<Character> stack = new ArrayDeque<>();
        int max = 0;
        int start = 0;
        int length = 0;
        dq.addLast(new Data(0, 0));
        for (int ez = 0; ez < str.length; ez++) {
            char c = str[ez];
            if (c == '(') {
                stack.addLast(c);
                dq.addLast(new Data(tot, ez + 1));
                continue;
            }
            if (c == '[') {
                stack.addLast(c);
                tot++;
                dq.addLast(new Data(tot, ez + 1));
                continue;
            }
            boolean isOk = false;
            if (c == ')') {
                if (!stack.isEmpty()) {
                    char cc = stack.pollLast();
                    if (cc == '(')
                        isOk = true;
                }
            }
            if (c == ']') {
                if (!stack.isEmpty()) {
                    char cc = stack.pollLast();
                    if (cc == '[')
                        isOk = true;
                }
            }
            if (isOk) {
                dq.pollLast();
                Data data = dq.peekLast();
                int cand = tot - data.count;
                if (cand > max) {
                    max = cand;
                    start = data.pos;
                    length = ez - data.pos + 1;
                }
            } else {
                dq.clear();
                dq.addLast(new Data(0, ez + 1));
                tot = 0;
                stack.clear();
            }
        }
        pw.println(max);
        pw.println(new String(str, start, length));
        pw.close();
        br.close();
    }

    private static class Data {
        int count;
        int pos;

        Data(int count, int pos) {
            this.count = count;
            this.pos = pos;
        }
    }

}
