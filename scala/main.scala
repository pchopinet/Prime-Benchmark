object prime {
    def isPrime(n: Int) = {
        val s = Math.sqrt(n).toInt + 1
        (2 to s).forall(n % _ != 0)
    }

    def loop_prime(start: Int, max: Int): Int = (start to max).par.count(a => isPrime(a))

    def main(args: Array[String]): Unit = {
        val debut = System.currentTimeMillis

        val max: Int = args.head.toInt
        println("Prime Benchmark : " + max)
        val j = loop_prime(0, max)
        println("There are " + j + " prime numbers between " + 1 + " and " + max)

        val fin = System.currentTimeMillis
        val temps = (fin - debut) / 1000
        println(temps + " sec")
    }

}

