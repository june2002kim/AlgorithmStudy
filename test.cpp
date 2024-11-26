#include <iostream>

using namespace std;

/*
Time Complexity : avg O(NlgN), worst O(N^2) but faster than Merger Sort
Overhead : O(1)
Stable Sort : N
*/

int N;
int arr[1000002];

void quick_sort(int op, int ed)
{
    if(ed <= op+1) return;

    // setting first element as pivot makes worst case when array is already sorted
    int pivot = arr[op];
    int l = op + 1;
    int r = ed - 1;

    while(1)
    {
        while(l <= r && arr[l] <= pivot) l++;
        while(l <= r && pivot <= arr[r]) r--;
        if(l > r) break;
        swap(arr[l], arr[r]);
    }

    swap(arr[op], arr[r]);
    quick_sort(op, r);
    quick_sort(r+1, ed);
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

    quick_sort(0, N);

    for(int i = 0; i < N; i++)
    {
        cout << arr[i] << '\n';
    }
}