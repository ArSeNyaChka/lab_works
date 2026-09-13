public class Reverse {
    public static void reverse(String s) {
        int length = s.length();
        for (int i = 0; i < length; i++) {
            System.out.print(s.charAt(length - i - 1));
        }
        System.out.print('\n');
    }
}
