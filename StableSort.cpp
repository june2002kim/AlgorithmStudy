#include <iostream>
#include <algorithm>

using namespace std;

// https://www.acmicpc.net/problem/10814
/*
 '&'은 모두 참조의 의미로 함수 내부에서 값이 변경되면 참조된 값 또한 변경됨을 의미.
*/

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    pair<int, string> x[N];
    for (auto& s : x) cin >> s.first >> s.second;

    stable_sort(x, x+N, [&](pair<int, string> a, pair<int, string> b) {
        // lambda : [캡처](매개변수){함수동작}(호출인자)
        return a.first < b.first;
    });

    for (auto p : x) cout << p.first << ' ' << p.second << '\n';
}
