#include<iostream>
#include<string>
using namespace std;    
int main(){
    string str;
    cout<<"Enter a string: ";
    getline(cin, str);
    
    string result = "";
    for(int i = 0; i < str.length(); i++){
        char currentChar = str[i];
        // Check if currentChar is already in result
        bool found = false;
        for(int j = 0; j < result.length(); j++){
            if(result[j] == currentChar){
                found = true;
                break;
            }
        }
        // If not found, append to result
        if(!found){
            result += currentChar;
        }
    }
    
    cout<<"String after removing duplicate characters: "<<result<<endl;
    return 0;
}