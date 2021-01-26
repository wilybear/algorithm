#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool visited[201][201];
int N;

void dfs(vector<vector<int>> map, int i, int j){
    visited[i][j] = true;
    visited[j][i] = true;
    for(int k=0; k<N;k++){
        if(map[j][k]==1 && !visited[j][k]){
            dfs(map,j,k);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    N = n;
    int answer = 0;
    for(int i=0; i<n;i++){
        for(int j=0; j<n; j++){
            if(!visited[i][j] && computers[i][j] == 1){
                answer ++;
                dfs(computers,i,j);
            }
        }
    }

    return answer;
}

int main(){
    int n =3;
    vector<vector<int>> v =	{{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    cout<< solution(n,v)<<endl;
}