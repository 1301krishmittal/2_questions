#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

bool checker(string l,int k){
    int m = 0;
    vector<char> km;
    for(int i = 0;i<l.size();i++){
        if(i == 0){
            km.push_back(l[i]);
            m++;
        }
        else{
            if((count(km.begin(),km.end(),l[i])) == true){
                continue;
            }
            else if((count(km.begin(),km.end(),l[i])) == false){
                km.push_back(l[i]);
                m++;
            }
        }
        if(m>k){
            return false;
        }
    }
    return true;
}

int solution(vector<string> &S,int K){
    vector<string> km;
    for(int i = 0;i<S.size();i++){
        if(checker(S[i],K) == true){
            km.push_back(S[i]);
        }
    }
    
    vector<pair<char,char>> km3;
    vector<int> km4;
    for(int j = 0;j<km.size();j++){
        pair<char,char> km2;
        for(int k = 0;k < km[j].size();k++){
            km2.first = km[j][0];
            if(k!= 0){
                if(km[j][k] != km2.first){
                    km2.second = km[j][k];
                }
            }
        }
        if(km3.size() == 0){
            km3.push_back(km2);
            km4.push_back(1);
        }
        else{
        for(int i = 0;i<km3.size();i++){
            if(km2.second == NULL){
                if(km3[i].first == km2.first || km3[i].second == km2.first){
                    if(km4[i] == -1){
                    km4[i] = 1;
                    }
                    else{
                        km4[i]++;
                    }
                }
            }
            else if(km3[i].first == km2.first && km3[i].second == km2.second ){
                if(km4[i] == -1){
                    km4[i] = 1;
                }
                else{
                    km4[i]++;
                }
            }
            else if(km3[i].second == km2.first && km3[i].first == km2.second ){
                if(km4[i] == -1){
                    km4[i] = 1;
                }
                else{
                    km4[i]++;
                }
            }
            else{
                km3.push_back(km2);
                km4.push_back(1);
            }
        }
    }
    }
    return *max_element(km4.begin(),km4.end());
}

int main(){
    vector<string> S = {"bc","edf","fde","dge","abcd"};
    int k  = 4;
    int l = solution(S,k);
    cout<<l;
    return 0;
}