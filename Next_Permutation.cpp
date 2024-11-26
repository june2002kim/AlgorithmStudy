#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a[] = {1, 2, 3};
    sort(a, a+3);

    // 순열
    do{
        for(int i = 0; i < 3; i++)
            cout << a[i] << ' ';
        cout << '\n';
    }while(next_permutation(a, a+3));

    cout << "After loop : ";
    for(int i = 0; i < 3; i++)
        cout << a[i] << ' ';
    cout << '\n';

    int b[] = {1, 1, 0, 0};
    sort(b, b+4);

    // 조합
    do {
        for(int j = 0; j < 4; j++)
        {
            if(b[j] == 0)
                cout << j + 1 << ' ';
        }
        cout << '\n';
    }while(next_permutation(b, b+4));

    return 0;
}