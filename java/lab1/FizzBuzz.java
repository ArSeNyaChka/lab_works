public class FizzBuzz {
    public static void fizzbuzz() {
        for (int i = 1; i <= 500; i++) {
            if (i % 5 == 0) {
                System.out.print("fizz");
            } if (i % 7 == 0) {
                System.out.print("buzz");
            } if (i % 5 != 0 && i % 5 != 0) {
                System.out.print(i);
            }
            System.out.print('\n');
        }
    }
}
