#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/* 문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42747
 * 작성일 : 2020-12-27
 * 작성자 : wilybear
 */

int solution(vector<int> citations)
{

    sort(citations.begin(), citations.end(), greater<int>());
    int h = 0, idx = 0;
    for (auto c : citations)
    {
        idx++;
        if (h >= idx && idx > c)    // [3,3,1] 인 경우 h-index가 2가 나와야 하므로
            h = idx - 1;
        else
            h = c;

        if (h <= idx)
            return h;
    }
    return idx;
}

int main()
{
    vector<int> sample = {4, 4, 4};
    cout << solution(sample) << endl;
}