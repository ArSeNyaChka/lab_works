public class Main {
    public static void main(String[] args) {
        String command = args[0];

        switch (command) {
            case "fizzbuzz":
                FizzBuzz.fizzbuzz();
                break;
        
            case "reverse":
                Reverse.reverse(args[1]);
                break;
            
            case "quadratic":
                Quadratic.quadratic(Double.valueOf(args[1]), Double.valueOf(args[2]), Double.valueOf(args[3]));
                break;

            case "series":
                Series.series();
                break;

            case "palindrome":
                Palindrome.palindrome(args[1]);
                break;

            default:
                System.out.println("vvedite comady!");
                break;
        }
    }
}
