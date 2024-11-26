#include <iostream>

using namespace std;

/*
Time Complexity : O(NlgN)
Overhead : O(N)
Stable Sort : Y
*/

int N;
int arr[1000002], tmp[10000002];

void merge(int op, int ed)
{
    int mid = (op+ed)/2;
    int lidx= op, ridx = mid;
    for(int i = op; i < ed; i++)
    {
        if(ridx == ed) tmp[i] = arr[lidx++];
        else if(lidx == mid) tmp[i] = arr[ridx++];
        else if(arr[lidx] <= arr[ridx]) tmp[i] = arr[lidx++];
        else tmp[i] = arr[ridx++];
    }

    for(int i = op; i < ed; i++)
    {
        arr[i] = tmp[i];
    }
}

void merge_sort(int op, int ed)
{
    if(ed == op + 1)
    {
        return;
    }

    int mid = (op+ed)/2;
    merge_sort(op, mid);
    merge_sort(mid, ed);
    merge(op, ed);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    merge_sort(0, N);

    for(int i = 0; i < N; i++)
    {
        cout << arr[i] << '\n';
    }
}