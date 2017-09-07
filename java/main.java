public class main {

    public static boolean est_premier(int nombre) {
        if (nombre % 2 == 0)
            return false;

        for (int i = 3; i < Math.sqrt(nombre) + 1; i += 2) {
            if (nombre % i == 0) {
                return false;
            }
        }
        return true;
    }

    public static void boucle_nb_premier(int start_number, int max, int pas) {
        int j = 0;
        for (int i = start_number; i < max; i += pas) {
            if (est_premier(i)) {
                j++;
            }
        }
        System.out.println("Il y a " + j + " nombres premier entre " + start_number + " et " + max);
    }


    public static void main(String[] args) {
        long debut = System.currentTimeMillis();

        boucle_nb_premier(1, 100000000, 1);

        long fin = System.currentTimeMillis();
        double temps = (fin - debut) / 1000;
        System.out.println(temps + " sec");
    }


}
