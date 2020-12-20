#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/* 문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42627
 * 작성일 : 2020-12-21
 * 작성자 : wilybear
 * 참고 : https://mungto.tistory.com/15
 */

struct compare
{
    bool operator()(const vector<int> a, const vector<int> b)
    {
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs)
{
    int answer = 0, idx = 0, cur_time = 0;
    priority_queue<vector<int>, vector<vector<int>>, compare> q;
    sort(jobs.begin(), jobs.end());
    while (jobs.size() > idx || !q.empty())
    {
        //현재 시간에 가능한 job이면 대기 큐에 삽입
        if (jobs.size() > idx && cur_time >= jobs[idx][0])
        {
            q.push(jobs[idx]);
            idx++;
            continue;
        }

        if (!q.empty())
        {
            //대기 큐에 job이 있으면 수행
            cur_time += q.top()[1];
            answer += cur_time - q.top()[0];
            q.pop();
        }
        else
        {
            //만약 대기 큐에 job이 없다면 다음 job이 도착하는 시간을 현재 시간으로 변경
            cur_time = jobs[idx][0];
        }
    }

    return answer / jobs.size();
}

int main()
{
    vector<vector<int>> sample_case{vector<int>{0, 3}, vector<int>{1, 9}, vector<int>{2, 6}};
    cout << solution(sample_case) << endl;
}