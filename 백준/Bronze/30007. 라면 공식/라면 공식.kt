fun main()
{
    val N: Int = readln().toInt()
    for (i in 1..N)
    {
        val (A, B, X) = readln().split(" ").map{it.toInt()}
        println(A * (X - 1) + B)
    }
}