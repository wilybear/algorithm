#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

/* 巩力 傅农 : https://programmers.co.kr/learn/courses/30/lessons/42579
 * 累己老 : 2020-12-29
 * 累己磊 : wilybear
 * 
 */

struct Song{
    int idx;
    int play;
};

bool comp(pair<string,int> a, pair<string,int> b){
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, Song> first_m;
    map<string, Song> second_m;
    map<string, int> gm;
    

    for(int i =0; i< genres.size(); i++){
        gm[genres[i]] += plays[i];
        if(first_m.find(genres[i]) == first_m.end()){
            first_m[genres[i]] = {i,plays[i]};
        }else{
            if(first_m[genres[i]].play < plays[i]){
                Song temp = first_m[genres[i]];
                second_m[genres[i]] = temp;
                first_m[genres[i]] = {i,plays[i]};
            }else{
                if(second_m.find(genres[i]) == second_m.end()){
                     second_m[genres[i]] = {i,plays[i]};
                }else{
                     if(second_m[genres[i]].play < plays[i]){
                        second_m[genres[i]] = {i,plays[i]};
                    }
                }
            }
        }
    }
    vector<vector<Song>> for_sort;

    vector<pair<string,int>> gm_v;
    for(auto g : gm){
        gm_v.push_back(g);
    }   
    sort(gm_v.begin(),gm_v.end(),comp);

    for(auto g : gm_v){
        answer.push_back(first_m[g.first].idx);
        if(second_m.find(g.first)!=second_m.end()){
            answer.push_back(second_m[g.first].idx);
        }
    }
    return answer;
}

int main(){

    vector<string> genres =  {"classic", "pop", "classic", "classic", "pop"};
    vector<int> plays = {500, 600, 150, 800, 2500};

    for(auto c : solution(genres,plays)){
        cout<< c<<",";
    }
    cout<<endl;
}