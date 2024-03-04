#include <iostream>
#include <windows.h>
#include <math.h>

using namespace std;

#define START 1.0
#define END 5.0

long double factorial(int n)
{
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

long double dividedDifference(int n, int k, long double result[][12])
{
    if (k == 0) return result[n][1];
    return dividedDifference(n + 1, k - 1, result) - dividedDifference(n, k - 1, result);
}

long double interpolateFirst(int n, long double x, long double result[][12])
{
    long double value = result[0][1];
    long double term = 1;

    for (int k = 1; k <= n - 1; k++)
    {
        term *= (x - result[k - 1][0]) / (k);
        value += term * dividedDifference(0, k, result);
    }

    return value;
}

long double interpolateSecond(int n, long double x, long double result[][12])
{
    long double value = result[n - 1][1];
    long double q = (x - result[n - 1][0]) / (result[1][0] - result[0][0]);
    long double term = q;

    for (int k = 2; k <= n - 1; k++)
    {
        term *= (q - k + 1) / factorial(k);
        value += term * dividedDifference(n, k, result);
    }

    return value;
}

void printInterpolationResult(long double x, long double h, long double result[][12], int n)
{
    if (x < 3)
    {
        cout << "\nВычисленные по первой интерполяционной формуле Ньютона:";
        cout << "\nx = " << x << "\n";
        cout << "x = x0 - " << h << "h = " << interpolateFirst(n, x, result) << "\n";
    }
    else
    {
        cout << "\nВычисленные по второй интерполяционной формуле Ньютона:";
        cout << "\nx = " << x << "\n";
        cout << "x = x0 + " << h << "h = " << interpolateSecond(n, x, result) << "\n";
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    long double result[11][12];
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            result[i][j] = 3990355.0;
        }
    }

    int i = 0;
    for (long double x = START; x < END + START / 10; x += 0.4)
    {
        result[i][0] = x;
        result[i][1] = atanl(1.0 / 2.0 * x);
        i++;
    }

    int j = 0;
    int m = 10;
    int n = 11;
    for (j = 2; j < 12; j++)
    {
        for (i = 0; i < m; i++)
        {
            result[i][j] = result[i + 1][j - 1] - result[i][j - 1];
        }
        m--;
    }

    printf("   x       y         dy(x)    d^2y(x)   d^3y(x)   d^4y(x)   d^5y(x)   d^6y(x)   d^7y(x)   d^8y(x)   d^9(x)   d^10y(x)\n");
    for (i = 0; i < 11; i++)
    {
        for (j = 0; j < 12; j++)
        {
            if (result[i][j] == 3990355.0)
            {
                printf("     -    ");
            }
            else
            {
                printf("%9.6lf ", result[i][j]);
            }
        }
        cout << "\n";
    }

    long double x0 = result[0][0];
    long double h = 0.1;

    printInterpolationResult(x0 - 0.2 * h, 0.2 * h, result, n);
    printInterpolationResult(x0 + 0.2 * h, 0.2 * h, result, n);
    printInterpolationResult(x0 - 0.5 * h, 0.5 * h, result, n);
    printInterpolationResult(x0 + 0.5 * h, 0.5 * h, result, n);
    printInterpolationResult(result[10][0] - 0.25 * h, 0.25 * h, result, n);
    printInterpolationResult(result[10][0] + 0.25 * h, 0.25 * h, result, n);
    printInterpolationResult(result[10][0] - 0.5 * h, 0.5 * h, result, n);
    printInterpolationResult(result[10][0] + 0.5 * h, 0.5 * h, result, n);

    cout << "\nЭмперическая формула для arctan(1 / 2x):\n";
    cout << "P(x) = " << result[0][1];
    for (int k = 1; k < n; k++)
    {
        cout << " + (" << dividedDifference(0, k, result) / factorial(k) << ")";
        for (i = 0; i < k; i++)
        {
            cout << "(x - " << result[i][0] << ")";
        }
    }
    cout << "\n";
}
