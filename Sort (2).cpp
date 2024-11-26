#include <iostream>

using namespace std;

// If input number's range could be smaller than 0
// Let array's range twice and add half of array's size to index when get input.
int N, idx, arr[10002];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    while(N--)
    {
        cin >> idx;
        arr[idx]++;
    }

    for(int i = 0; i <= 10000; i++)
    {
        while(arr[i])
        {
            cout << i << '\n';
            arr[i]--;
        }
    }
}