#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

string getHint(string secret, string guess) {
    unordered_map<char,int>mp;

    int secretCount=0;
    for(int i=0; i<secret.size(); i++){
        if(secret[i]== guess[i]){
            secretCount ++;
        }else{
            mp[guess[i]]++;
        }
    }
    int countCow=0;
    for (int i=0;i<secret.size();i++) {
        if (secret[i] != guess[i] && mp[secret[i]]>0){
            countCow++;
            mp[secret[i]]--;
        }
    }
    string ans=to_string(secretCount)+"A" +to_string(countCow)+"B";
    return ans;
}

int main(){
    
}