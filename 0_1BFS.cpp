#include <iostream>
#include <deque>

using namespace std;

int arr[200000], visit[200000];

int main(void)
{
    int N, K;
    cin >> N >> K;

    deque<int> Q;
    Q.push_front(N);
    fill(visit, visit + 200000, -1);
    visit[N] = 0;

    while(visit[K] == -1)
    {
        int cur = Q.front();
        Q.pop_front();

        if(cur*2 < 200000 && visit[cur*2] == -1)
        {
            visit[cur*2] = visit[cur];
            Q.push_front(cur*2);
        }

        for(int nxt : {cur-1, cur+1})
        {
            if(nxt < 0 || nxt >= 200000 || visit[nxt] != -1) continue;
            visit[nxt] = visit[cur] + 1;
            Q.push_back(nxt);
        }
    }

    cout << visit[K];
}