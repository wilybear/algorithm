#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;
struct comp
{
    bool operator()(const pair<int, int> a, const pair<int, int> b)
    {
        if (a.first == b.first)
        {
            return a.second > b.second;
        }
        else
        {
            return a.first < b.first;
        }
    }
};

int solution(vector<int> priorities, int location)
{
    int answer = 1;

    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
    for (int i = 0; i < priorities.size(); i++)
    {
        pq.push(make_pair(priorities[i], i));
    }

    for (auto i = 0; i < pq.size(); i++)
    {
        cout<<pq[i].second<<endl;
    }
    

    int flag = 0;
    while (!pq.empty())
    {
        if (pq.top().second != location)
        {
            if (pq.top().second > location)
            {
                flag++;
            }
            else
            {
                answer++;
            }
            pq.pop();
        }else{
            if(flag !=0){
                pair<int,int> temp = pq.top();
                temp.second += pq.size();
                pq.pop();
                pq.push(temp);
                flag--;
            }
        }
    }

    return answer;
}

int main()
{
    vector<int> sample = {1, 1, 9, 1, 1, 1};
    int location = 0;

    cout << solution(sample, location) << endl;
}