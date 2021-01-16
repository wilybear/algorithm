#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

int main(){

    int t;
    int bnp, timing,bnt_cnt, t_cnt;
    bnt_cnt = 0;
    t_cnt = 0;
    vector<int> v;
    int h;
    int l;

    cin >> t;
    bnp =t;
    timing = t;
    for(int i=0; i< 14;i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    for(int i =0; i< v.size();i++){
        if(bnp >= v[i]){
            bnt_cnt += bnp/v[i];
            bnp = bnp%v[i];
        }

        if(i==0){
            h=0;
            l=0;
        }else if(v[i] > v[i-1]){
            h++;
            l=0;
            if(h >= 3){
                t += t_cnt *v[i];
                t_cnt=0;
            }
        }else if(v[i] < v[i-1]){
            h=0;
            l++;
            if(l >=3){
                t_cnt += t / v[i];
                t = t % v[i];
            }
        }else{
            h=0;
            l=0;
        }
    }

    t = t + t_cnt * v[v.size()-1];
    bnp = bnp + bnt_cnt * v[v.size()-1];
  //  cout<< t<< ", "<< bnp<<endl;
    if(t > bnp){
        cout<< "TIMING"<<endl;
    }else if( t==bnp){
        cout<<"SAMESAME"<<endl;
    }else{
        cout<<"BNP"<<endl;
    }
    
}