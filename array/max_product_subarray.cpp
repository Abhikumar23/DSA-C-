#include<iostream>
#include<vector>
#include<math.h>
#include<limits.h>

using namespace std;

int maxProduct(vector<int> arr){
  
    int n= arr.size();
    int maxProduct= INT_MIN;
    int mul= 1;

    for(int i=0; i<n; i++){
        mul *= arr[i];
        maxProduct= max(maxProduct, mul);

        if(arr[i] == 0){
            mul=1;
        }

    }

    mul = 1;
    for(int i=n-1; i>=0; i--){
        mul *= arr[i];
        maxProduct= max(maxProduct, mul);

        if(arr[i] == 0){
            mul=1;
        }

    }
    return maxProduct;
}
int main(){
    vector<int>arr= {2,3,-2,4};
    int ans = maxProduct(arr);

    cout<<"the maximmum Product is:"<< ans << endl;
    return 0;

}