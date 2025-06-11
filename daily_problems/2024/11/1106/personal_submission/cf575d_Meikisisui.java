import java.io.IOException;

public class Test5 {

    public static void main(String[] args) throws IOException {
        System.out.println("2000");
        for (int i = 1; i <= 1000; i++)
            System.out.println(i + " 1 " + i + " 2");
        for (int i = 1000; i >= 1; i--)
            System.out.println(i + " 1 " + i + " 2");
    }
}
