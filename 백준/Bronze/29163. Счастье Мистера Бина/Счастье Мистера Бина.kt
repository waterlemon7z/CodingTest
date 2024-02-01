fun main()
{
    var even:Int = 0; var odd:Int = 0
     readln().toInt()
    val arr = readln().split(" ").map{it.toInt()}
    for (i in arr)
    {
        if(i%2 == 0)
        {
            even++
        }
        else
        {
            odd++
        }
    }
    if(even > odd)
    {
        println("Happy")
    }
    else
    {
        println("Sad")
    }
}