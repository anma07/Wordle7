//Wordle logic goes here
//nvm my comments, i am practicing commenting XD
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

//setting a set allows us to check if the word exists in the list fast enough
set<string> wordset;
//this will store all the words from out text document once the code starts to run
vector<string> wordlist;

//this will insert all the words in out created set and vector
void setupWords(){
    ifstream file("words.txt");
    string w;
    while (file >> w) {
        wordset.insert(w);
        wordlist.push_back(w);
    }
}

int main(){
    setupWords();

    srand(time(0)); // random seed
    string word = wordlist[rand() % wordlist.size()];

    //setting a counter, as wordle has just 6 guesses
    int count=6;
    string guess = "";
    //since we want to flex our achievement(if you do by mistake) in wordle, the text version of grid is initialised
    string grid[6] = {"-----","-----","-----","-----","-----","-----"};
    string grid2[6] = {"-----","-----","-----","-----","-----","-----"};
    while(count!=0){
        cin>>guess;
        //this will check if the word is actually valid (present in our word list)
        if (wordset.find(guess) == wordset.end()) {
        cout << "Not a valid word!\nEnter a 5 lettered valid word: ";
    } 
    else {
        //next function will allow us to pass the repitions
        bool used[5] = {false,false,false,false,false};
        count--;
        string output(5, '-');
        for(int i=0; i<5; i++){
            if(guess[i]==word[i]){
                output[i]='G';
                used[i] = true;
            }
        }
        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                if(guess[i]==word[j] && !used[j]){
                    output[i]='Y';
                    used[j]=true;
                    break;
                }
            }
        }
        //i dont really remember the logic behind 6-count-1, so nvm, if it works, dont touch it
        grid[6-count-1] = output;
        grid2[6-count-1] = guess;

        for(int i = 0; i<6; i++){
            cout<<grid[i]<<"  "<<grid2[i]<<endl;
        }

        if(output == "GGGGG"){
            //W (XD)
            cout<<"You Win!"<<endl;
            break;
        }
        else{
            cout<<"No. of tries left: "<<count<<endl;
            if(count==0){
                //L (XD)
                cout<<"You Lose!\nLoser\njk\nI am just as bad at this\n"<<endl;
                cout<<"The word is: "<<word<<endl;
            }
        }
    }
    }
}
