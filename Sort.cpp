#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    cout.sync_with_stdio(0);
    cin.tie(0);

    int arr[3];
    for(int i = 0; i < 3; i++)
    {
        cin >> arr[i];
    }

    // 오름차순 기본 정렬
    //sort(arr, arr+3);

    // 람다 함수를 이용한 내림차순 정렬
    sort(arr, arr + sizeof(arr)/sizeof(*arr), [](int a, int b){return a > b;});

    for(int i = 0; i < 3; i++)
    {
        cout << arr[i] << ' ';
    }
}