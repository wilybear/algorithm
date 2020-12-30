#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

/* 문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42583
 * 작성일 : 2020-12-30
 * 작성자 : wilybear
 *
 */

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int answer = 1;
    queue<int> q;
    vector<int> entered_t(truck_weights.size());
    int total, last = 0;

    q.push(truck_weights[0]);       //초기값
    total = q.front();
    entered_t[0] = 1;

    for (int idx = 1; idx < truck_weights.size(); idx++) 
    {

        while (weight < total + truck_weights[idx])     //새로운 truck이 들어갈 수 없을때
        {
            total -= q.front();
            answer += (bridge_length - answer + entered_t[last]) - 1;
            last++;
            q.pop();
        }

        if (weight >= total + truck_weights[idx])   //새로운 트럭이 들어 갈 수 있을때
        {
            total += truck_weights[idx];
            answer++;
            if (!q.empty() && entered_t[last] + bridge_length <= answer)    //새로운 트럭이 들어가 시간이 지났을때 만약 다리에서
            {                                                               //시간이 지남에 따라 트럭이 나올때
                total -= q.front();
                last++;
                q.pop();
            }
            q.push(truck_weights[idx]);
            entered_t[idx] = answer;
        }
    }

    while (!q.empty())      //종료후 다리에 남아있는 모든 트럭을 뻄
    {
        answer += (bridge_length - answer + entered_t[last]);
        last++;
        q.pop();
    }

    return answer;
}

int main()
{
    int len = 2;
    int weight = 10;
    vector<int> truck = {7, 4, 5, 6};

    cout << solution(len, weight, truck) << endl;
}