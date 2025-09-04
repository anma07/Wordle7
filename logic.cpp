//Wordle logic goes here
#include <iostream>
#include <string>

using namespace std;

int main(){
    string word;
    cin>>word;
    int count;
    string guess = "";
    while(count!=0){
        cin>>guess;
        bool used[5] = {false,false,false,false,false};
        count++;
        string output(5, '-');
        for(int i=0; i<5; i++){
            if(guess[i]==word[i]){
                output[i]='G';
                used[i] = true;
            }
            else{
                for(int j=0; j<5; j++){
                    if(guess[i]==word[j] && !used[i]){
                        output[i]='Y';
                        used[j]=true;
                    }
                }
            }
        }
        if(output == "GGGGG"){
            cout<<"You Win!"<<endl;
            break;
        }
        cout<<output<<endl;
    }
}
