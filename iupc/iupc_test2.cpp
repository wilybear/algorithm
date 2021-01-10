#include<iostream>
#include<vector>
using namespace std;

int main(){
    int N,M;

    cin >> N;
    cin >> M;
    vector<int> v;
    for(int i=0; i< M; i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    int max;
    for(int i=0; i<=v.size();i++){
        int dis;
        if(i==0){
            if(v[i]==i){
                max =1;
            }else{
                max = v[i];
            }
        }else if(i==v.size()){
            dis = N - v[i-1];
            if(max < dis){
                max = dis;
            }
        }else{
            if(i+1 != v.size()){
                dis = (v[i+1] - v[i]+1)/2;
                if(max < dis){
                    max = dis;
                }
            }
        }
    }
    cout<< max <<endl;

}