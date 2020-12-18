#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/* 문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42839
 * 작성일 : 2020-12-18
 * 작성자 : wilybear
 * 
 */


//소수 판별 함수
bool isPrime(int n)
{
    if (n == 1 || n == 2 || n == 0)
    {
        return !(n == 1 || n == 0); //0,1일 경우 false, 2일 경우 true;
    }
    else if (n % 2 == 0)      //짝수는 2를 제외하고 소수가 아니다
    {
        return false;
    }
    else
    {
        for (int i = 3; i * i <= n; i = i + 2)   //소수의 특성 사용
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }
}

int solution(string numbers)
{
    int answer = 0;
    string s, sub;
    s = numbers;
    sort(s.begin(), s.end());
    set<int> primes;    //중복을 방지하기 위해서
    do
    {
        for (int i = 1; i < s.length() + 1; i++)
        {
            sub = s.substr(0, i);
            if (isPrime(stoi(sub)))
            {
                primes.insert(stoi(sub));
            }
        }

    } while (next_permutation(s.begin(), s.end()));
    // for(auto i : primes){    //테스트용
    //     cout<< i<<endl;
    // }
    answer = primes.size();
    return answer;
}

int main()
{
    string test_case_1 = "17";
    string test_case_2 = "011";
    cout << solution(test_case_1) << endl
         << solution(test_case_2) << endl;
}