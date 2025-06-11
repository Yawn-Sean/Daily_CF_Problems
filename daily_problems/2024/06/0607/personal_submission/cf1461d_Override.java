
import java.io.*;
import java.util.*;

public class d1461 {
    static Scanner scanner;

    public static void main(String[] args) {
        scanner = new Scanner(System.in);
        int testCases = scanner.nextInt();
        while (testCases-- > 0)
            processTestCase();
    }

    static Integer[] array;
    static HashSet<Long> resultSet;

    public static void processTestCase() {
        resultSet = new HashSet<>();
        int size = scanner.nextInt();
        int queries = scanner.nextInt();
        array = new Integer[size];

        for (int i = 0; i < size; i++) {
            array[i] = scanner.nextInt();
        }

        List<Integer> tempList = Arrays.asList(array);
        Collections.sort(tempList);
        tempList.toArray(array);

        explore(0, size - 1);

        for (int i = 0; i < queries; i++) {
            if (resultSet.contains((long)scanner.nextInt())) {
                System.out.println("Yes");
            } else {
                System.out.println("No");
            }
        }
    }

    public static void explore(int left, int right) {
        long totalSum = 0;
        long middle = (array[left] + array[right]) / 2;
        int position = -1;

        for (int i = left; i <= right; i++) {
            totalSum += array[i];
        }

        resultSet.add(totalSum);

        for (int i = left; i <= right; i++) {
            if (array[i] <= middle) {
                position = i;
            }
        }

        if (position == -1 || position == right) {
            return;
        }

        explore(left, position);
        explore(position + 1, right);
    }
}
