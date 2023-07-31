#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

int solution(int a[],int N){
    vector<int> km;
    int sum = 0;
    for(int i = 0;i<N;i++){
        if(i == N-1){
            int k = a[N-1];
            while(k != 0){
                int rem = k%2;
                if(rem != 0){
                    sum ++;
                }
                k = k/2;
            }
        }
        else if(a[i]%2 == 0){
            a[i+1] = a[i+1] + a[i]/2;
            a[i] = 0; 
        }
        else if(a[i]%2 != 0){
            a[i+1] = a[i+1] + a[i]/2;
            a[i] = 1;
            sum ++;
        }
    }
    return sum;
}

int main(){
    int arr[] = {4,0,3,0};
    int k  = solution(arr,4);
    cout<<k;

return 0;}