#ifndef _HELPER_H_
#define	_HELPER_H_

#include<algorithm>
#include<vector>
#include<iostream>
#include<string>
using namespace std;
int totalballs=6;
int ballsincode=4;
vector<string> getAllCodes(){
    vector<string> state;
    for(int i=0;i<totalballs;i++){
        for(int j=0;j<totalballs;j++){
            for(int k=0;k<totalballs;k++){
                for(int l=0;l<totalballs;l++){
                    if(i!=j && j!=k && k!=l && i!=k && i!=l && j!=l){
                        string gen;
                        gen.push_back(char(int('a'+i)));
                        gen.push_back(char(int('a'+j)));
                        gen.push_back(char(int('a'+k)));
                        gen.push_back(char(int('a'+l)));
                        state.push_back(gen);
                    }
                }
            }
        }
    }
    return state;
}
vector<int> getCount(string code){
    vector<int> ctArr;
    for(int i=0;i<totalballs;i++){
        ctArr.push_back(0);
    }
    for(int i=0;i<code.size();i++){
        ctArr[code[i]-'a']++;
    }
    return ctArr;
}
pair<int,int> computeProximity(string n, string m){
    int black=0,bw=0;
    for(int i=0,j=0;i<n.size(),j<m.size();i++,j++){
        if(n[i]==m[j]){
            black++;
        }
    }
    vector<int> ctn=getCount(n);
    vector<int> ctm=getCount(m);
    for(int i=0,j=0;i<ctn.size(),j<ctm.size();i++,j++){
        if(ctn[i]<ctm[j]){
            bw+=ctn[i];
        }
        else{
            bw+=ctm[j];
        }
    }
    pair<int,int> res;
    res=make_pair(black,bw-black);
    return res;
}
#endif // _HELPER_H_
