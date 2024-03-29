/*
16561 - 3의 배수

-TEST CASE-
12

3
*/

/*
-EXPLANATION-
9
3+3+3 -> 1
12
6 3 3, 3 6 3, 3 3 6 -> 3 = 1 + 2
15
9 3 3, 3 9 3, 3 3 9, 3 6 6, 6 3 6, 6 6 3 -> 
18
12 3 3 + 9 6 3 + 6 6 6 -> 10
21
15 3 3 + 12 6 3 + 9 9 3 + 9 6 6 -> 15
3 x n
-> 1 ~ n - 2 까지의 합 -> (n - 1)(n - 2) / 2
*/

#include <iostream>
using namespace std;

int main()
{
    int n; cin >> n;
    cout << ((n / 3) - 1) * ((n / 3) - 2) / 2;
}