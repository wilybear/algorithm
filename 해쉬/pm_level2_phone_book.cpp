#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/* 문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42577
 * 작성일 : 2020-12-27
 * 작성자 : wilybear
 * 해쉬 문제이지만 해쉬보다 정렬로 푸는게 더 쉬웠음
 */

bool comp(const string a,const string b){
    return a.length() < b.length();
}

bool solution(vector<string> phone_book) {
    bool answer = true;

    sort(phone_book.begin(),phone_book.end(),comp);

    for(int i=0;i<phone_book.size()-1;i++){
        for(int j=i+1;j<phone_book.size();j++){
            if(phone_book[j].compare(0,phone_book[i].length(),phone_book[i]) == 0 ){
                return false;
            }
        }
    }

    return answer;
}

int main(){
    vector<string> sample = {"123", "456", "789"};
    cout<<solution(sample)<<endl;
}