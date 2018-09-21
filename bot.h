#include <cstdlib>
#include<map>
#include<iterator>
#include "helper.h"
using namespace std;

bool comp(pair<int,int> a,pair<int,int> b){
    if(a.first==b.first)
        return(a.second < b.second);
        return(a.first < b.first);
}
bool fun(pair<int,int> a,pair<int,int> b){
    return(a.first==b.first && a.second==b.second);
}
class Bot{
public:
    vector<string> state;//Stores all possibile states.
    string guess;
    vector<string> cstate;//Current state after each Guess
    vector<pair<int,int> > prox;
    Bot(){
        state=getAllCodes();
        cstate=state;
    }
    vector<string> getPossibilities(string code,int b,int w){
        vector<string> prunestate;
        for(int i=0;i<state.size();i++){
                pair<int,int> dist=computeProximity(code,state[i]);
                if(dist.first==b && dist.second==w){
                    prunestate.push_back(state[i]);
                }
        }
        return prunestate;
    }
    multimap <pair<int,int>,string> getPossibilities(string code){
        multimap <pair<int,int> , string> nodes;
        prox.clear();
        for(int i=0;i<state.size();i++){
                pair<int,int> dist=computeProximity(code,state[i]);
                nodes.insert(make_pair(dist,state[i]));
                prox.push_back(dist);
        }
        sort(prox.begin(),prox.end(),comp);
        vector<pair<int,int> >::iterator ip;
        ip=unique(prox.begin(),prox.end(),fun);
        prox.resize(distance(prox.begin(),ip));
        return nodes;
    }
    void update(string code,int b,int w){
        vector<string> prunestate;
        prunestate=getPossibilities(code,b,w);
        vector<string> v3;
        sort(cstate.begin(), cstate.end());
        sort(prunestate.begin(), prunestate.end());
        set_intersection(cstate.begin(),cstate.end(),prunestate.begin(),prunestate.end(),back_inserter(v3));
        cstate.clear();
        cstate=v3;
    }
    string getAdvice(){
        int n_minmax=state.size();
        vector<string> mincode;
        int max_possibilities;
        for(int i=0;i<state.size();i++){
            multimap <pair<int,int> , string> poss=getPossibilities(state[i]);
            vector<int> il;
            for(int j=0;j<prox.size();j++){
                int ct=poss.count(prox[j]);
                multimap <pair<int,int> , string> ::iterator itl,itr,itu;
                itl=poss.lower_bound(prox[j]);
                itu=poss.upper_bound(prox[j]);
                vector<string> temp;
                int k=1;
                for(itr=itl;itr!=itu;itr++){
                    if(itr->first.first==prox[j].first && itr->first.second==prox[j].second)
                    temp.push_back(itr->second);
                }
                vector<string> v3;
                sort(cstate.begin(), cstate.end());
                sort(temp.begin(), temp.end());
                vector<string>::iterator ls;
                set_intersection(cstate.begin(),cstate.end(),temp.begin(),temp.end(),back_inserter(v3));
                il.push_back(v3.size());
            }
            max_possibilities=*max_element(il.begin(),il.end());
            if(max_possibilities < n_minmax){
                n_minmax=max_possibilities;
                mincode.clear();
                mincode.push_back(state[i]);
            }
            if(max_possibilities==n_minmax){
                mincode.push_back(state[i]);
            }

        }
        guess=*min_element(mincode.begin(),mincode.end());
        vector<string> intersect;
        sort(cstate.begin(), cstate.end());
        sort(mincode.begin(),mincode.end());
        set_intersection(cstate.begin(),cstate.end(),mincode.begin(),mincode.end(),back_inserter(intersect));
        if(!intersect.empty()){
            guess=*min_element(intersect.begin(),intersect.end());
        }
        return guess;
    }
};
