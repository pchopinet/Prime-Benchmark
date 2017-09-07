public class main {

    public static boolean is_prime(int nombre) {
        if (nombre % 2 == 0)
            return false;

        for (int i = 3; i < Math.sqrt(nombre) + 1; i += 2) {
            if (nombre % i == 0) {
                return false;
            }
        }
        return true;
    }

    public static void loop_prime(int start_number, int max, int pas, int j[]) {
        int jj = 0;
        for (int i = start_number; i < max; i += pas) {
            if (is_prime(i)) {
                jj++;
                //System.out.println(i);
            }
        }
        j[0] += jj;
    }

    public static void go(int max, int nombre_thread) {
        int j[] = new int[1];
        j[0] = 0;
        System.out.println("Prime Benchmark : " + max);
        Thread tab_t[] = new Thread[nombre_thread];
        for (int i = 0; i < nombre_thread; i++) {
            int k = i;

            tab_t[i] = new Thread(() -> loop_prime(k, max, nombre_thread, j));
            tab_t[i].start();
        }

        try {
            for (int i = 0; i < nombre_thread; i++) {
                tab_t[i].join();
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("There are " + j[0] + " prime numbers between " + 1 + " and " + max);

    }

    public static void main(String[] args) {
        long debut = System.currentTimeMillis();

        go(100000000, 8);

        long fin = System.currentTimeMillis();
        double temps = (fin - debut) / 1000;
        System.out.println(temps + " sec");
    }


}
