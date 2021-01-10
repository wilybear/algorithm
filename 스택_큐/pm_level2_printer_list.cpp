#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location)
{
    int answer = 1;

    queue <pair<int,int>> q;

    for (int i = 0; i < priorities.size(); i++)
    {
        q.push(make_pair(priorities[i], i));
    }

    int flag = 0;
    int pivot = location;
    while (!q.empty())
    {
        if (q.front().second != location)
        {
            if (q.front().second > pivot)
            {
                flag++;
                pivot = q.front().second;
            }
            else
            {
                answer++;
            }
            q.pop();
        }else{
            if(flag !=0){
                pair<int,int> temp = q.front();
                q.pop();
                q.push(temp);
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