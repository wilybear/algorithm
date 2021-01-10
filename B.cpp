#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int main(){
   int N,M;

    cin >> N >> M;
    std::ios::sync_with_stdio(false);
    multimap<int,int> m;
    vector<int> v;
    for(int i=0; i<N;i++){
        int temp;
        cin >> temp;
        m.insert(make_pair(temp,1));
    }

    for(int i=0; i<M;i++){
        int temp;
        cin >> temp;
        if(m.find(temp) != m.end()){           
            cout<< distance(m.begin(),m.find(temp))<<endl;
        }else{
            cout<< -1 <<endl;
        }
    }
}