/*
https://www.acmicpc.net/problem/14956
*/

#include <iostream>

using namespace std;

int N, M;

pair<int, int> Philosopher(int n, int m)
{
    // Recursive Considering return value
    if (n == 2)
    {
        switch (m)
        {
        case 1:
            return {1, 1};
        case 2:
            return {1, 2};
        case 3:
            return {2, 2};
        case 4:
            return {2, 1};
        }
    }

    int half = n / 2;
    int elements = half * half;
    pair<int, int> quadResult;

    if (m <= elements)
    {
        quadResult = Philosopher(half, m);
        return {quadResult.second, quadResult.first};
    }
    else if (m <= elements * 2)
    {
        quadResult = Philosopher(half, m - elements);
        return {quadResult.first, half+quadResult.second};
    }
    else if (m <= elements * 3)
    {
        quadResult = Philosopher(half, m - elements * 2);
        return {half+quadResult.first, half+quadResult.second};
    }
    else
    {
        quadResult = Philosopher(half, m - elements * 3);
        return {half*2+1-quadResult.second, half+1-quadResult.first};
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    pair<int, int> result = Philosopher(N, M);
    cout << result.first << ' ' << result.second;
}