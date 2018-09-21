#include<math.h>
#include "ball.h"
#include "game.h"
#include "bot.h"
using namespace std;
int test_case=10;
int main()
{
    cout << "Welcome to mastermind Game!";
    for(int i=0;i<test_case;i++){
        cout<<"\n\nRunning Test case "<<i+1<<"....\n";
        srand(unsigned(time(0)));
        vector<int> arr;
        for (int i=0; i<totalballs; ++i) arr.push_back(i);
        random_shuffle ( arr.begin(), arr.end() );
        //random_shuffle ( arr.begin(), arr.end(), randg);
        vector<Ball> b;
        for(int i=0;i<ballsincode;i++){
            Ball t(char(arr[i]+97),i);
            b.push_back(t);
        }
        Game g;
        pair<int,int> bw=g.play(b);
        cout<<"black:"<<bw.first<<"white:"<<bw.second<<"\n";
        string input;
        for(int i=0;i<ballsincode;i++){input.push_back(b[i].getcolor());}
        if(bw.first!=ballsincode){
            Bot bot1;
            while(true){
                bot1.update(input,bw.first,bw.second);
                input=bot1.getAdvice();
                cout<<"Ball Guessed by Alg:"<<input<<"\n";
                bw=g.check(input);
                if(bw.first==ballsincode){
                    break;
                }
                cout<<"Black: "<<bw.first<<" White:"<<bw.second<<" #Trial:"<<g.getTrial()<<"\n";
            }
        }
        cout<<"You won!!..Took "<<g.getTrial()<<" to win the game\n";

    }
    return 0;
}
