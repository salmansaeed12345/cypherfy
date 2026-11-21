
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



string encrypt_diff (string s){
      int k=2;
    for (int i=0 ; i < s.length();i++){

        char c=toupper (s[i]);

        if (c>='A' && c<='Z' && c==65){
             c=64;}                                    //null in place of A
        
        if (c>='A' && c<='Z' && c==69){
             c=32;}                                   //space in place of E
        
        if (c>='A' && c<='Z' && c==73){
             c=46;}                                    // full stop for I
          
        if (c>='A' && c<='Z' && c==79){
             c=61;}                                         // = for O
        
        if (c>='A' && c<='Z' && c==85){
             c=86;}                                         // v for U   
        else{c=c+k}                                        //rest of the letters are moved two places ahead  
               
    }

        s[i]=c;         
    }
    return s;
}

string decrypt_diff (string s){
      int k=2;
    for (int i=0 ; i < s.length();i++){

        char c=toupper (s[i]);

        if (c==64){
             c=65;}                                    //null in place of A
        
        if (c==32){
             c=69;}                                   //space in place of E
        
        if (c==46){
             c=73;}                                    // full stop for I
          
        if (c==61){
             c=79;}                                         // = for O
        
        if (c==86){
             c=85;}                                         // v for U   
        else{c=c-k}                                        //rest of the letters are moved two places ahead  
               
    }

        s[i]=c;         
    }
    return s;
}

int main(){

    
    
}
