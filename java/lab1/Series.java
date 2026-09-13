public class Series {
    public static void series() {
        int n = 2;
        double result = 0;
        while (true) {
            double element = 1. / (n*n + n - 2);
            if (Math.abs(element) < 1E-6) { break; }
            result += element;
            n++;
        }
        System.out.println(result);
    }
}