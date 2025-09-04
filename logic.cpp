//Wordle logic goes here
#include <iostream>
#include <string>

using namespace std;

int main(){
    string word;
    cin>>word;
    int count=6;
    string guess = "";
    string grid[6] = {"-----","-----","-----","-----","-----","-----"};
    while(count!=0){
        cin>>guess;
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
        grid[6-count-1] = output;

        for(int i = 0; i<6; i++){
            cout<<grid[i]<<endl;
        }

        if(output == "GGGGG"){
            cout<<"You Win!"<<endl;
            break;
        }
        else{
            cout<<"No. of tries left: "<<count<<endl;
            if(count==0){
                cout<<"You Lose!"<<endl;
            }
        }
    }
}
