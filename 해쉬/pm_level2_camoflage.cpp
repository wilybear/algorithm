#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

/* ���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/42578
 * �ۼ��� : 2020-12-28
 * �ۼ��� : wilybear
 * 
 */

int solution(vector<vector<string>> clothes)
{
    int answer = 1; //�ؿ��� ���ؾ� �ϹǷ�
    map<string, int> m;
    for (auto clothe : clothes)
    {
        m[clothe[1]]++; //���� ������ key������
    }
    for (auto it = m.begin(); it != m.end(); it++)
    {
        answer *= (it->second + 1); //����� �� ��� (�ش� ������ ���� ���� ���� �ֱ� ������ -1)
    }
    return answer - 1; //�ƹ��͵� ���� �ʾ��� ��츦 ����
}

int main()
{
    vector<vector<string>> sample = {{"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"}};

    cout << solution(sample) << endl;
}