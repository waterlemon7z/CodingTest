fun main()
{
    val N = readln().toInt()
    for(i in 1..N/5)
    {
        print("V")
    }
    for (i in 1..N%5)
    {
        print("I")
    }
}