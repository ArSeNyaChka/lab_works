public class Quadratic {
    public static void quadratic(double a, double b, double c) {
        double D = b*b - 4*a*c;

        if (D < 0) { System.out.println("Вещественных корней нет"); }
        else if (D == 0) { System.out.println(-b/(2*a)); }
        else {
            System.out.println((-b+Math.sqrt(D))/(2*a));
            System.out.println((-b-Math.sqrt(D))/(2*a));
        }
    }
}
