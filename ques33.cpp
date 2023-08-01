#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

bool zeroes(int **A,int N,int M){
    if(A[N][M] == 0){
        return true;
    }
    else{
        return false;
    }
}

int solution(int **A,int N,int M){
    int count = 0;
    for(int k = 0;k<9;k++){
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            if(A[N][M] == 1){
                continue;
            }
            else if(A[i][j]>1){
                if(j>0 && zeroes(A,i,j-1)){
                    A[i][j]--;
                    A[i][j-1]++;
                    count++;
                }
                else if(i>0 && zeroes(A,i-1,j)){
                    A[i][j]--;
                    A[i-1][j]++;
                    count++;
                }
                else if(i<2 && zeroes(A,i+1,j)){
                    A[i][j]--;
                    A[i+1][j]++;
                    count++;
                }
                else if(j<2 && zeroes(A,i,j+1)){
                    A[i][j]--;
                    A[i][j+1]++;
                    count++;
                }
                else{
                    A[i][j]--;
                    if(j==2){
                        A[i][j-1]++;
                        count++;
                    }
                    else if(j == 0){
                        A[i][j+1]++;
                        count++;
                    }
                }
            }
        }
    }
    }
    return count;
}

int main(){
    int A[3][3] = {{1,0,1},{1,3,0},{2,0,1}};



    return 0;
}