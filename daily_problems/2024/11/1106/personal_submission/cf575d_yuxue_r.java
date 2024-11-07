import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        System.out.println("2000");

        for (int i = 1; i <= 1000; i++) {
            System.out.println(i + " 1 " + i + " 2");
        }

        for (int i = 1000; i >= 1; i--) {
            System.out.println(i + " 1 " + i + " 2");
        }

    }
}
