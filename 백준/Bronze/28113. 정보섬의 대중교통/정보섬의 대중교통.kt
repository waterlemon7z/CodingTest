fun main()
{
    val (N, A,B) = readln().split(" ").map {it.toInt() }
    if(A < B)
    {
        println("Bus")
    }
    else if(A == B)
    {
        println("Anything")
    }
else
        println("Subway")
}