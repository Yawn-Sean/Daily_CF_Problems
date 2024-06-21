import java.util.PriorityQueue;
import java.util.Scanner;

public class Test2 {

    public static void main(String[] args) throws Exception {
        Test2 test = new Test2();
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        int n = Integer.parseInt(str);
        int[][] arr = new int[n][2];
        for (int ez = 0; ez < n; ez++) {
            String temp = sc.nextLine();
            String[] tempArr = temp.split(" ");
            arr[ez][0] = Integer.parseInt(tempArr[0]);
            arr[ez][1] = Integer.parseInt(tempArr[1]);
        }
        long res = test.stasAndQueue(n, arr);
        System.out.println(res);
    }

    private long stasAndQueue(int n, int[][] arr) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((x, y) -> {
            return y[1] - x[1];
        });
        for (int ez = 0; ez < n; ez++)
            pq.offer(new int[]{ez, arr[ez][0] - arr[ez][1]});
        long res = 0;
        int ez = 0;
        while (!pq.isEmpty()) {
            int[] now = pq.poll();
            int index = now[0];
            int ai = arr[index][0], bi = arr[index][1];
            res += (long) ai * ez + (long) bi * (n - ez - 1);
            ez++;
        }
        return res;
    }

}
