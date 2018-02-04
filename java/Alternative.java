import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.concurrent.ConcurrentLinkedQueue;

/**
 * Created by Pierre on 15/09/2017.
 */
public class Alternative {

    public static boolean is_prime(int number, ConcurrentLinkedQueue<Integer> tab) {

        if (number % 2 == 0)
            return false;
        int i = 0;
        double max = Math.sqrt(number) + 1;

        Iterator<Integer> iter = tab.iterator();
        int p;
        while (iter.hasNext()) {
            p = iter.next();

            if (number % p == 0) {
                return false;
            } else if (i > max) {
                return true;
            }
            i++;
        }
        return true;
    }

    public static void loop_prime(int start_number, int max, int pas, int j[], ConcurrentLinkedQueue<Integer> tab) {
        int jj = 0;

        for (int i = start_number; i < max; i += pas) {
            if (is_prime(i, tab)) {
                tab.add(i);
                jj++;
                //System.out.println(i);
            }
        }
        System.out.println(jj);
        j[0] += jj;
    }

    public static void go(int max, int number_thread) {
        int j[] = new int[1];
        j[0] = 0;
        System.out.println("Prime Benchmark : " + max);
        Thread tab_t[] = new Thread[number_thread];

        ConcurrentLinkedQueue<Integer> tab = new ConcurrentLinkedQueue<>();

        tab.add(2);
        tab.add(3);
        tab.add(5);
        tab.add(7);

        for (int i = 0; i < number_thread; i++) {
            int k = i + 7;
            tab_t[i] = new Thread(() -> loop_prime(k, max, number_thread, j, tab));
            tab_t[i].start();
        }

        try {
            for (int i = 0; i < number_thread; i++) {
                tab_t[i].join();
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("There are " + j[0] + " prime numbers between " + 1 + " and " + max);

    }

}
