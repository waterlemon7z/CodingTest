fun main()
{
    val N = readln().toInt()
    for (i in 1..N)
    {
        val (wt, lt, we, le) = readln().split(" ").map { it.toLong() }
        val rstT: Long = wt * lt
        val rstE: Long = we * le
        if (rstT > rstE)
        {
            print("TelecomParisTech\n")
        }
        else if (rstT < rstE)
        {
            print("Eurecom\n")
        }
        else
        {
            print("Tie\n")
        }
    }
}