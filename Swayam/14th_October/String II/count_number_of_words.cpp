#include<iostream>
#include<string>        
using namespace std;
int main(){
    string str;
    cout<<"Enter a string: ";
    getline(cin, str);
    
    int wordCount = 0;
    bool inWord = false;
    
    for(int i = 0; i < str.length(); i++){
        if(str[i] != ' ' && !inWord){
            inWord = true;
            wordCount++;
        } else if(str[i] == ' '){
            inWord = false;
        }
    }
    
    cout<<"The number of words in the string is: "<<wordCount<<endl;
    return 0;
}