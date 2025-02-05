import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class factorization {

    public static void main(String args[]) {
        Scanner myObj = new Scanner(System.in);
        System.out.println("Enter a number (n):");
        int n = myObj.nextInt();
        myObj.close();

        List<Integer> factors = new ArrayList<>();

        for (int i = 2; i <= n; i++) {
            while (n % i == 0) {
                factors.add(i);
                n /= i;
            }
        }

        System.out.print("num = ");
        for (int i = 0; i < factors.size(); i++) {
            System.out.print(factors.get(i));
            if (i < factors.size() - 1) {
                System.out.print("*");
            }
        }
        System.out.println();
    }

}
