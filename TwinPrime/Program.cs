using System.Numerics;

BigInteger lastNumber;
Console.WriteLine("What number should I look up to?");
lastNumber = Convert.ToInt32(Console.ReadLine());

static bool isPrime(BigInteger x)
{
    if (x == 2 || x == 3) { return true; }
    if (x <= 1 || x % 2 == 0 || x % 3 == 0) { return false; }
    for (BigInteger i = 5; i * i < x; i++)
    {
        if (x % i == 0 || x % (i + 2) == 0) { return false; }
    }
    return true;
}
BigInteger a = 0;
BigInteger b = 0;
bool count = true;
for (BigInteger i = 2; i < lastNumber; i++)
{
    if (isPrime(i))
    {
        if (count)
        {
            a = i;
            count = !count;
        }
        else
        {
            b = i;
            count = !count;
        }
        if (BigInteger.Abs(a - b) < 3)
        {
            Console.WriteLine(a + " " + b);
        }
    }
}


