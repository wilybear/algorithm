#include <string>
#include <vector>
#include <iostream>
using namespace std;

/* 문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42842
 * 작성일 : 2020-12-19
 * 작성자 : wilybear
 * 
 */

vector<int> solution(int brown, int yellow)
{
    vector<int> answer;

    for (int col = 1; col <= yellow; col++)
    { //가로가 세로보다 김
        if (yellow % col != 0)
            continue;                    //col로 안나누어지면 직사각형이 아니므로 패스
        int row = yellow / col;          //가로 값
        int total = (row + col) * 2 + 4; //yellow를 둘러싼 값은 row*2 + col*2 + 4(모서리)
        if (total == brown)
        {
            answer.push_back(row + 2);
            answer.push_back(col + 2);
            break;
        }
    }
    return answer;
}

int main()
{
    vector<vector<int>> sample_case{vector<int>{10, 2}, vector<int>{8, 1}, vector<int>{24, 24}};
    for (auto v : sample_case)
    {
        vector<int> result = solution(v[0], v[1]);
        if (result.size() != 0)
        {
            cout << result[0] << " " << result[1] << endl;
        }
        else
        {
            cout << "wrong" << endl;
        }
    }
}