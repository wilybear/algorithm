#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/* 문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42746?language=cpp#
 * 작성일 : 2020-12-27
 * 작성자 : wilybear
 * 참고 : https://mungto.tistory.com/22
 */


bool compare(string a, string b)
{
    return a + b > b + a;   //두개 합쳤을 때 더 큰 순서대로 정렬
}

string solution(vector<int> numbers)
{
    string answer = "";
    vector<string> numbers_s;
    for (auto n : numbers)
    {
        numbers_s.push_back(to_string(n));
    }

    sort(numbers_s.begin(), numbers_s.end(), compare);

    if (stoi(numbers_s[0]) == 0)
    {
        return "0";
    }
    for (auto s : numbers_s)
    {
        answer += s;
    }
    return answer;
}

int main()
{
    vector<int> sample_case = {6, 10, 2};
    vector<int> sample_case2 = {3, 30, 34, 5, 9};
    vector<int> sample_case3 = {621, 6217, 7, 5};

    cout << endl;
    cout << solution(sample_case) << endl;
    cout << endl;
    cout << solution(sample_case2) << endl;
    cout << endl;
    cout << solution(sample_case3) << endl;
}