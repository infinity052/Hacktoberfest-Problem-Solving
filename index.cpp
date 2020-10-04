#include<bits/stdc++.h>
using namespace std;
 bool detectCapitalUse(string word) {
        int count=0;
        int index=-1;
        
        for(int i=0;i<word.length();i++){
            if(isupper(word[i])){
                if(count==0 and i!=0)
                    return false;
                count++;
                if(i==0)
                    index=0;
            }
            else{
                if(count>0 and index!=0)
                    return false;
            }
        }
        if(count==word.length() or count<=1)
            return true;
        else
            return false;
    }
int main(){
  return 0;
}
