#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    string s;
    string a ="";
    cin >> s;
    
    if(s[0] == 'I'){
        a += 'E';
    }else{
        a += 'I';
    }

    if(s[1] == 'S'){
        a +='N';
    }else{
        a +='S';
    }
     if(s[2] == 'T'){
        a +='F';
    }else{
        a +='T';
    } 
    
    if(s[3] == 'J'){
        a +='P';
    }else{
        a +='J';
    }

    cout <<a <<endl;

}