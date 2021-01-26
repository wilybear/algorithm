#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int max = numbers.size();
    vector<queue<int>> veq(max,queue<int>()); //숫자 갯수 만큼의 큐 생성
    for(int i=0; i< numbers.size();i++){
        if(i==0){
            veq[0].push(numbers[i]);
            veq[0].push(numbers[i] * -1);
        }
        else{
            while(!veq[i-1].empty()){
                int temp = veq[i-1].front();
                veq[i-1].pop();
                veq[i].push(temp + numbers[i]);
                veq[i].push(temp - numbers[i]);
            }
        }
        
        if(i==numbers.size()-1){
            while(!veq[i].empty()){
                veq[i].front() == target ? answer++ : 0;
                veq[i].pop();
            }
        }
    }
    return answer;
}

int main(){
    vector<int> sampe = {1, 1, 1, 1, 1};
    int target = 3;
    cout<<solution(sampe, target)<<endl;
}