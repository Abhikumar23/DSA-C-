#include<bits/stdc++.h>
using namespace std;

vector<int> selfProduct(vector<int>arr){
int n= arr.size();
vector<int>ans(n,1);

int suffix=1;
for(int i=0; i<n; i++){
    ans[i] *= suffix;
    suffix *= arr[i];
}

int preffix=1;
for(int i=n-1; i>=0; i--){
    ans[i] *= preffix;
    preffix *= arr[i];
}

return ans;

}

int main(){

    vector<int> arr= {1,2,3,4,5};
    vector<int>ans= selfProduct(arr);

    for(int num: ans){
        cout<<"product is:"<< num <<endl;
    }


    return 0;
}