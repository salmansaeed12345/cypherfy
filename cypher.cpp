
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

    using namespace std;

string encrypt_easy (string s){
      int k=3;
    for (int i=0 ; i < s.length();i++){

        char c=toupper (s[i]);

        if (c>='A' && c<='Z'){
             c=c+k;
             if(c>'Z')
               c-=26;
    }

        s[i]=c;         
    }
    return s;
}


string decrypt_easy (string s){
      int k=3;
    for (int i=0 ; i < s.length();i++){

        char c=toupper (s[i]);

        if (c>='A' && c<='Z'){
             c=c+k;
             if(c>'Z')
               c+=26;
    }

        s[i]=c;         
    }
    return s;
}

string decrypt_medium (string s){
      int k=5;
    for (int i=0 ; i < s.length();i++){

        char c=toupper (s[i]);

        if (c>='A' && c<='Z'){
             c=c+k;
             if(c>'Z')
               c+=26;
    }

        s[i]=c;         
    }
    return s;
}


string encrypt_medium (string s){
      int k=5;
    for (int i=0 ; i < s.length();i++){

        char c=toupper (s[i]);

        if (c>='A' && c<='Z'){
             c=c+k;
             if(c>'Z')
               c-=26;
    }

        s[i]=c;         
    }
    return s;
}

string decrypt_diff (string s){
      int k=5;
    for (int i=0 ; i < s.length();i++){

        char c=toupper (s[i]);

        if (c>='A' && c<='Z'){
             c=c+k;
             if(c>'Z')
               c+=26;
    }

        s[i]=c;         
    }
    return s;
}


string encrypt_diff (string s){
      int k=5;
    for (int i=0 ; i < s.length();i++){

        char c=toupper (s[i]);

        if (c>='A' && c<='Z' && c==65,69,73,79,85){
             c=32;}
        else{c=c}     
               
    }

        s[i]=c;         
    }
    return s;
}

int main(){

    
    
}