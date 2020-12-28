#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

/* 문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42578
 * 작성일 : 2020-12-28
 * 작성자 : wilybear
 * 
 */

int solution(vector<vector<string>> clothes)
{
    int answer = 1; //밑에서 곱해야 하므로
    map<string, int> m;
    for (auto clothe : clothes)
    {
        m[clothe[1]]++; //옷의 종류를 key값으로
    }
    for (auto it = m.begin(); it != m.end(); it++)
    {
        answer *= (it->second + 1); //경우의 수 계산 (해당 부위를 착용 안할 수도 있기 때문에 -1)
    }
    return answer - 1; //아무것도 입지 않았을 경우를 제외
}

int main()
{
    vector<vector<string>> sample = {{"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"}};

    cout << solution(sample) << endl;
}