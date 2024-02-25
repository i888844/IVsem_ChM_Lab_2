//#include <iostream>
//#include <windows.h>
//#include <math.h>
//
//using namespace std;
//
//#define START 0.0
//#define END 1.0
//
//long double factorial(int n) {
//	if (n == 0 || n == 1) return 1;
//	return n * factorial(n - 1);
//}
//
//long double dividedDifference(int n, int k, long double result[][12]) {
//	if (k == 0) return result[n][1];
//	return dividedDifference(n + 1, k - 1, result) - dividedDifference(n, k - 1, result);
//}
//
//long double interpolateFirst(long double x, long double result[][12]) {
//	long double value = result[0][1];
//	long double term = 1;
//
//	for (int k = 1; k <= 11; k++) {
//		term *= (x - result[k - 1][0]) / (k);
//		value += term * dividedDifference(0, k, result);
//	}
//
//	return value;
//}
//
//long double interpolateSecond(long double x, long double result[][12]) {
//	long double value = result[11][1];
//	long double q = (x - result[11][0]) / (result[1][0] - result[0][0]);
//	long double term = q;
//
//	for (int k = 2; k <= 11; k++) {
//		term *= (q - k + 1) / k;
//		value += term * dividedDifference(11, k, result);
//	}
//
//	return value;
//}
//
//int main()
//{
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//	long double result[11][12];
//	for (int i = 0; i < 11; i++)
//	{
//		for (int j = 0; j < 12; j++)
//		{
//			result[i][j] = 3990355.0;
//		}
//	}
//
//	int i = 0;
//	for (long double x = START; x < END + START / 10; x += 0.1)
//	{
//		result[i][0] = x;
//		result[i][1] = tanl(i);
//		i++;
//	}
//
//	int j = 0;
//	int maximum = 10;
//	for (j = 2; j < 12; j++)
//	{
//		for (i = 0; i < maximum; i++)
//		{
//			result[i][j] = result[i + 1][j - 1] - result[i][j - 1];
//		}
//		maximum--;
//	}
//
//	for (i = 0; i < 11; i++)
//	{
//		for (j = 0; j < 12; j++)
//		{
//			if (result[i][j] == 3990355.0)
//			{
//				printf("    -    ");
//			}
//			else
//			{
//				printf("%8.2lf ", result[i][j]);
//			}
//		}
//		cout << "\n";
//	}
//
//	cout << "\nВычисленные по первой интерполяционной формуле Ньютона:\n";
//	cout << "x = x0 - 0.2h = " << interpolateFirst(result[0][1] - 0.2 * 0.1, result) << "\n";
//	cout << "x = x0 + 0.2h = " << interpolateFirst(result[0][1] + 0.2 * 0.1, result) << "\n";
//	cout << "x = x0 - 0.5h = " << interpolateFirst(result[0][1] - 0.5 * 0.1, result) << "\n";
//	cout << "x = x0 + 0.5h = " << interpolateFirst(result[0][1] + 0.5 * 0.1, result) << "\n";
//	cout << "x = x10 - 0.25h = " << interpolateFirst(result[0][1] - 0.25 * 0.1, result) << "\n";
//	cout << "x = x10 + 0.25h = " << interpolateFirst(result[0][1] + 0.25 * 0.1, result) << "\n";
//	cout << "x = x10 - 0.5h = " << interpolateFirst(result[0][1] - 0.5 * 0.1, result) << "\n";
//	cout << "x = x10 + 0.5h = " << interpolateFirst(result[0][1] + 0.5 * 0.1, result) << "\n";
//
//	cout << "\nВычисленные по второй интерполяционной формуле Ньютона:\n";
//	cout << "x = x0 - 0.2h = " << interpolateSecond(result[0][1] - 0.2 * 0.1, result) << "\n";
//	cout << "x = x0 + 0.2h = " << interpolateSecond(result[0][1] + 0.2 * 0.1, result) << "\n";
//	cout << "x = x0 - 0.5h = " << interpolateSecond(result[0][1] - 0.5 * 0.1, result) << "\n";
//	cout << "x = x0 + 0.5h = " << interpolateSecond(result[0][1] + 0.5 * 0.1, result) << "\n";
//	cout << "x = x10 - 0.25h = " << interpolateSecond(result[0][1] - 0.25 * 0.1, result) << "\n";
//	cout << "x = x10 + 0.25h = " << interpolateSecond(result[0][1] + 0.25 * 0.1, result) << "\n";
//	cout << "x = x10 - 0.5h = " << interpolateSecond(result[0][1] - 0.5 * 0.1, result) << "\n";
//	cout << "x = x10 + 0.5h = " << interpolateSecond(result[0][1] + 0.5 * 0.1, result) << "\n";
//
//	cout << "\nЭмперическая формула для tan(x):\n";
//	cout << "P(x) = " << result[0][1];
//	for (int k = 1; k < 11; k++) {
//		cout << " + (" << dividedDifference(0, k, result) / factorial(k) << ")";
//		for (i = 0; i < k; i++)
//		{
//			cout << "(x - " << result[i][0] << ")";
//		}
//	}
//}

#include <iostream>
#include <windows.h>
#include <math.h>

using namespace std;

#define START 0.0
#define END 1.0

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
        term *= (q - k + 1) / k;
        value += term * dividedDifference(10, k, result);
    }

    return value;
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
    for (long double x = START; x < END + START / 10; x += 0.1)
    {
        result[i][0] = x;
        result[i][1] = tanl(x);
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

    printf("  x       y         dy(x)   d^2y(x)  d^3y(x)  d^4y(x)  d^5y(x)  d^6y(x)  d^7y(x)  d^8y(x)  d^9(x)  d^10y(x)\n");
    for (i = 0; i < 11; i++)
    {
        for (j = 0; j < 12; j++)
        {
            if (result[i][j] == 3990355.0)
            {
                printf("    -    ");
            }
            else
            {
                printf("%8.6lf ", result[i][j]);
            }
        }
        cout << "\n";
    }

    cout << "\nВычисленные по первой интерполяционной формуле Ньютона:\n";
    cout << "x = x0 - 0.2h = " << interpolateFirst(n, result[0][0] - 0.2 * 0.1, result) << "\n";
    cout << "x = x0 + 0.2h = " << interpolateFirst(n, result[0][0] + 0.2 * 0.1, result) << "\n";
    cout << "x = x0 - 0.5h = " << interpolateFirst(n, result[0][0] - 0.5 * 0.1, result) << "\n";
    cout << "x = x0 + 0.5h = " << interpolateFirst(n, result[0][0] + 0.5 * 0.1, result) << "\n";
    cout << "x = x10 - 0.25h = " << interpolateFirst(n, result[10][0] - 0.25 * 0.1, result) << "\n";
    cout << "x = x10 + 0.25h = " << interpolateFirst(n, result[10][0] + 0.25 * 0.1, result) << "\n";
    cout << "x = x10 - 0.5h = " << interpolateFirst(n, result[10][0] - 0.5 * 0.1, result) << "\n";
    cout << "x = x10 + 0.5h = " << interpolateFirst(n, result[10][0] + 0.5 * 0.1, result) << "\n";

    cout << "\nВычисленные по второй интерполяционной формуле Ньютона:\n";
    cout << "x = x0 - 0.2h = " << interpolateSecond(n, result[0][0] - 0.2 * 0.1, result) << "\n";
    cout << "x = x0 + 0.2h = " << interpolateSecond(n, result[0][0] + 0.2 * 0.1, result) << "\n";
    cout << "x = x0 - 0.5h = " << interpolateSecond(n, result[0][0] - 0.5 * 0.1, result) << "\n";
    cout << "x = x0 + 0.5h = " << interpolateSecond(n, result[0][0] + 0.5 * 0.1, result) << "\n";
    cout << "x = x10 - 0.25h = " << interpolateSecond(n, result[10][0] - 0.25 * 0.1, result) << "\n";
    cout << "x = x10 + 0.25h = " << interpolateSecond(n, result[10][0] + 0.25 * 0.1, result) << "\n";
    cout << "x = x10 - 0.5h = " << interpolateSecond(n, result[10][0] - 0.5 * 0.1, result) << "\n";
    cout << "x = x10 + 0.5h = " << interpolateSecond(n, result[10][0] + 0.5 * 0.1, result) << "\n";

    cout << "\nЭмперическая формула для tan(x):\n";
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
