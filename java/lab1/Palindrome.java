public class Palindrome {
    public static void palindrome(String s) {
        s = s.toLowerCase();
        s = s.replaceAll("[\\s\\p{P}]", "");
        int length = s.length();
        for (int i = 0; i <= length / 2; i++) {
            if (s.charAt(i) != s.charAt(length - i - 1)) {
                System.out.println(false);
                return ;
            }
        }

        System.out.println(true);
    }
}