#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

/* 문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42586
 * 작성일 : 2020-12-30
 * 작성자 : wilybear
 * 큐 문제인거 같은데 큐를 안써도 될거같아서 안씀
 */

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int cnt = 0;
    int max = 0;

    for(int i=0; i<progresses.size();i++){
        int day = (100-progresses[i])/speeds[i];
        if((100-progresses[i])%speeds[i] != 0){
            day++;
        }
        if(max == 0){
            max = day;
            cnt++;
        }else{
            if(max < day){
                max = day;
                answer.push_back(cnt);
                cnt = 1;
            }else{
                cnt++;
            }
        }
    }

    if(cnt!=0){
        answer.push_back(cnt);
    }

    return answer;
}

int main(){
    vector<int> progress = {93, 30, 55};
    vector<int> speeds = {1, 30, 5};

    for(auto ans : solution(progress,speeds)){
        cout<< ans <<",";
    }
    cout<<endl;

}