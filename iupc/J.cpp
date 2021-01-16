#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int matrix[2001][2001];
int answer[2001][2001];
int main(){
    int M, N;
    
	std::ios::sync_with_stdio(false);
    cin >> N >> M;

    if(M==1){
        M=0;
    }else{
     M = M/2;
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int temp;
            scanf("%d",&temp);
            matrix[i][j] = temp;
            if(i<M || j<M || i==N-M || j == N-M){
                answer[i][j]=0;
            }
        }
    }

    for(int i=0;i<N-M;i++){
        for(int j=0;j<N-M;j++){
            if(matrix[i][j] == 0){
               // answer[i][j] = 0;
                continue;
            }else{
                answer[i+M][j+M] = matrix[i][j] * -1;
                int temp = matrix[i][j];
                for(int a=i; a<i+(M*2)+1;a++){
                    for(int b=j; b<j+(M*2)+1;b++){
                        matrix[a][b] -= temp;
                    }
                }
            
            }
        }
    }

       for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<< answer[i][j]<<" ";
 
        }
        cout<<endl;
    }

}