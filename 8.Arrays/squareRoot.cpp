#include<cmath>
long long int floorSqrt(long long int N)
{
    // Write your code here.
    long roundSqrt = sqrt(N);
    int floorSquare = floor(roundSqrt);
    return floorSquare;
}