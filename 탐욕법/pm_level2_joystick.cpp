#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/* 巩力 傅农 : https://programmers.co.kr/learn/courses/30/lessons/42860
 * 累己老 : 2021-01-16
 * 累己磊 : wilybear
 */

int solution(string name)
{
    int answer = 0;
    int first_A = -1;
    int end_A = -1;
    int back_distance = name.size();
    for (int i = 0; i < name.size(); i++)
    {
        answer += min(name[i] - 65, 91 - name[i]);
        if (name[i] == 'A' && first_A == -1 && i != 0)
        {
            first_A = i;
        }
        if (name[i] != 'A' && first_A != -1 && end_A == -1)
        {
            end_A = i;
        }
    }
    if (first_A != -1 && end_A != -1)
    {
        back_distance = (first_A - 1) * 2 + name.size() - end_A;
    }

    answer += min(int(name.size() - 1), back_distance);
    return answer;
}