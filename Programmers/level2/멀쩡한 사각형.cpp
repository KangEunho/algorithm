using namespace std;

int Gcd(int a, int b)
{
    while (b > 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long solution(int w, int h) {
    long long answer = (long long)w * (long long)h;
    return answer - (w + h - Gcd(w, h));
}