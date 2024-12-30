import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class B1056 {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        int M = in.nextInt();
        Map<Integer,Long> map = new HashMap<>();
        for (long m=1; m<=Math.min(M,N); m++) {
            long count = (N-m)/M + 1;
            int reminder = (int)((m*m)%M);
            long oldCount = map.getOrDefault(reminder, 0L);
            map.put(reminder, count+oldCount);
        }
        long answer = 0;
        for (int m=0; m<M; m++) {
            int otherM = (m == 0) ? 0 : (M-m);
            long count1 = map.getOrDefault(m, 0L);
            long count2 = map.getOrDefault(otherM, 0L);
            answer += count1*count2;
        }
        System.out.println(answer);
    }

}
