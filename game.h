#include <ctime>
#include <cstdlib>
#include "helper.h"
using namespace std;
int randg(int i){ return rand()%i;}
class Game{
private:
    string code;
    int ntrial;
public:
    int getTrial() {return ntrial;}
    void codemaker(){
        srand(unsigned(time(0)));
        vector<int> arr;
        for (int i=0; i<totalballs; ++i) arr.push_back(i);
        random_shuffle ( arr.begin(), arr.end() );
        random_shuffle ( arr.begin(), arr.end(), randg);
        for(int i=0;i<ballsincode;i++){
            char st=char(97+arr[i]);
            code.push_back(st);
        }
    }
    Game(){
        codemaker();
        ntrial=0;
    }
    pair<int,int> play(vector<Ball> b){
        string s;
        for(int i=0;i<b.size();i++){
            s.push_back(b[i].getcolor());
        }
        return check(s);
    }
    pair<int,int> check(string s){
        pair<int,int> bw;
        bw=computeProximity(s,code);
        ntrial++;
        return bw;
    }
};
