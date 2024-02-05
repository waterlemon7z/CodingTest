fun main()
{
    val N = readln().toInt()
    for (i in 1..N)
    {
        val (a,b,c) = readln().split(" ").map{it.toDouble()}
        println("\$"+ String.format("%.2f",a*b*c))
    }
}