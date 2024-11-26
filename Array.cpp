#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
    cout.sync_with_stdio(0);
    cin.tie(0);

    string word;
    int alphabet[100];                  // alphabet[100]={};
    fill(alphabet, alphabet + 100, 0);  // 전역변수로 설정시 0으로 초기화

    cin >> word;

    for(int i = 0; i < word.length(); i++)
    {
        alphabet[word[i] - 'a']++;
    }

    for(char a = 'a'; a <= 'z'; a++)
    {
        cout << alphabet[a - 'a'] << ' ';
    }
}