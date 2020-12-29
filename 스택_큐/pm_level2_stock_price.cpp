#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <set>


/* ���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/42584
 * �ۼ��� : 2020-12-29
 * �ۼ��� : wilybear
 * solution 1�� multi set ���..  ��� ������ �ʿ䰡 ���� ������
 * solution 2�� stack���� ����
 */


using namespace std;
struct  cmp{
    bool operator()(pair<int,int> a , pair<int,int> b){
        return a.second > b.second;
    }
};

vector<int> solution(vector<int> prices) { 
    int len = prices.size();
    vector<int> answer(len,0);
    multiset<pair<int,int>, cmp>  s;      //<idx,price>
    s.insert(make_pair(0,prices[0]));
    for(int i=1;i<prices.size();i++){
        if(s.begin()->second > prices[i]){
            while(s.begin()->second > prices[i]){
                answer[s.begin()->first] = i - s.begin()->first;
                s.erase(s.begin());
            }
        }
        s.insert(make_pair(i,prices[i]));

    }

    for(auto p : s){
        answer[p.first] = len - p.first -1 ;
    }

    return answer;
}

vector<int> solution2(vector<int> prices) { 
    int len = prices.size();
    vector<int> answer(len,0);
    stack<int>  s;    
    s.push(0);
    for(int i=1;i<prices.size();i++){
        if(prices[s.top()] > prices[i]){
            while(!s.empty()&&prices[s.top()]> prices[i]){
                answer[s.top()] = i - s.top();
                s.pop();
            }
        }
        s.push(i);
    }

    while(!s.empty()){
        answer[s.top()] = len - s.top() -1;
        s.pop();
    }
    return answer;
}

int main(){
    vector<int> prices = {1, 2, 3, 2, 3};
    for(auto p : solution2(prices)){
        cout<< p<<", ";
    }
    cout<<endl;
}