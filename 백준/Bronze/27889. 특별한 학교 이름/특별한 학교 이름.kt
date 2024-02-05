fun main()
{
    val str = readln()
    print(
        when (str)
        {
            "NLCS" -> "North London Collegiate School"
            "BHA" -> "Branksome Hall Asia"
            "KIS" -> "Korea International School"
            "SJA" -> "St. Johnsbury Academy"
            else -> ""
        }
    )
}