#include<iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int answer;
vector<string> words_g;
string t;

void dfs(string word, vector<bool> visited, int cnt){
    if(word == t){
        if(answer > cnt){
            answer = cnt;
        }
        return;
    }
    for(int i=0; i<words_g.size(); i++){
        if(visited[i])
            continue;
        for(int j=0; j<words_g[i].size();j++){
            if(word[j] != words_g[i][j] && t[j] != word[j]){
                string temp = word;
                temp[j] = words_g[i][j];
                if(find(words_g.begin(),words_g.end(),temp) != words_g.end()){
                    vector<bool> temp_v = visited;
                    temp_v[i] = true;
                    dfs(temp,temp_v,cnt+1);
                }
            }
        }
    }

}

int solution(string begin, string target, vector<string> words) {
    answer = words.size()+1;
    words_g = words;
    t = target;
    vector<bool> visited (words.size(),false);

    dfs(begin,visited,0);

    return answer > words.size() ? 0 : answer;
}

int main(){
    vector<string> v= {"cog", "log","lot","dog","dot","hot"};
    string b = "hit";
    string t = "cog";

    cout<< solution(b,t,v)<<endl;

}