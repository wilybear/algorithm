#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
using namespace std;

/* 문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42628
 * 작성일 : 2020-12-22
 * 작성자 : wilybear
 * 
 */

//문자열 split 함수
vector<string> Split(string str, char delimiter)
{
    vector<string> internal;
    stringstream ss(str);
    string temp;

    while (getline(ss, temp, delimiter))
    {
        internal.push_back(temp);
    }

    return internal;
}

vector<int> solution(vector<string> operations)
{
    vector<int> answer;
    multiset<int> ms; //min, max를 구해야하므로 multiset 사용

    for (auto op : operations)
    {
        vector<string> operation = Split(op, ' ');
        int value = stoi(operation[1]); //stoi를 사용하여 string -> int
        if (operation[0] == "I")
        { //insert
            ms.insert(value);
        }
        else if (operation[0] == "D" && !ms.empty())
        {
            if (value == -1)
            {
                ms.erase(ms.begin()); //최소값 제거
            }
            else
            {
                ms.erase(prev(ms.end())); //prev(ms.end()) == --ms.end(); 최대값 제거
            }
        }
    }
    int max = 0, min = 0;
    if (!ms.empty())
    {
        min = *ms.begin();
        max = *ms.rbegin();
    }
    answer.push_back(max);
    answer.push_back(min);
    return answer;
}

int main()
{
    vector<string> sample_case = {"I 16", "D 1"};
    vector<string> sample_case2 = {"I 4", "I 3", "I 2", "I 1", "D 1", "D 1", "D -1", "D -1", "I 5", "I 6"};

    vector<int> sol1 = solution(sample_case);
    vector<int> sol2 = solution(sample_case2);

    cout << sol1[0] << "," << sol1[1] << endl;
    cout << sol2[0] << "," << sol2[1] << endl;
}