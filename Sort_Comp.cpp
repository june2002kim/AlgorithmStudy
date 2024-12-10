/*
https://www.acmicpc.net/problem/1431
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
string st;
vector<string> v;

bool cmp(const string& a, const string& b) {
    int lena = a.size(), lenb = b.size();
    int suma = 0, sumb = 0;

    // a가 b의 앞에 와야할 때, true
    // 그렇지 않을 떄 false
    if(lena != lenb) return lena < lenb;

    for(int i = 0; i < lena; i++) {
        if(isdigit(a[i])) suma += (a[i] - '0');
    }
    for(int i = 0; i < lenb; i++) {
        if(isdigit(b[i])) sumb += (b[i] - '0');
    }
    if(suma != sumb) return suma < sumb;
    return a < b;   // 사전순
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> st;
        v.push_back(st);
    }

    sort(v.begin(), v.end(), cmp);

    for(auto i : v) cout << i << '\n';
}