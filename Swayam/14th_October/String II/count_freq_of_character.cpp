#include<iostream>
#include<string>
using namespace std;   
int main(){
    string str;
    cout<<"Enter a string: ";
    getline(cin, str);
    
    char ch;
    cout<<"Enter a character to find its frequency: ";
    cin>>ch;
    
    int count = 0;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == ch){
            count++;
        }
    }
    
    cout<<"The frequency of character '"<<ch<<"' in the string is: "<<count<<endl;
    return 0;
}