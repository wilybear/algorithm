#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K)
{
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> q;   //우선순위 큐 사용, 오르차순 정렬

    for (auto scov : scoville)
    {
        q.push(scov);
    }

    while (q.size() != 1 && q.top() < K)
    {
        int first_food = q.top();
        q.pop();
        int second_food = q.top();
        q.pop();
        int new_food = first_food + (second_food * 2);
        q.push(new_food);
        answer++;
    }
    if (q.top() >= K)
        return answer;
    return -1;
}

int main()
{
    vector<int> sample_case{1, 2, 3, 9, 10, 12};
    int K = 7;
    cout << solution(sample_case, K) << endl;
}