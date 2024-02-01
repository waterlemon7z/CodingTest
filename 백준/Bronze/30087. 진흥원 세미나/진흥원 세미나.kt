fun main(args: Array<String>)
{
    val N = readln().toInt()
    for (i in 1..N)
    {
        var str = readln()
        var room:String = when (str)
        {
            "Algorithm" -> "204"
            "DataAnalysis" -> "207"
            "ArtificialIntelligence" -> "302"
            "CyberSecurity" -> "B101"
            "Network" -> "303"
            "Startup" -> "501"
            "TestStrategy" -> "105"
            else -> ""
        }
        println(room)
    }
}