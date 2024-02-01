fun main()
{
    val (N, M) = readln().split(" ").map{it.toDouble()}
    println(String.format("%.1f",N * M / 2))
}