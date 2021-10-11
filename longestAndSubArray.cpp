#include<iostream>
#include<cmath>

using namespace std;

int main(){
    int t;
    cin>>t;
    int arr[100];
    for(int i =0 ;i<t;i++){
        int N;
        int length1, length2;
        cin>>N; 
        int bits = (int)(log2(N)) +1; 
        int upp , mid =1,low=1;
        upp = pow(2,bits); 
        if(bits -1 > 0){   
            mid = pow(2,bits-1); 
        }
        if(bits-2 > 0){
            low = pow(2,bits-2); 
        }

        length1 = N - mid +1; 
        length2 = mid - low;  
        if(length1 > length2){
            arr[i] = length1;
        }else{
            arr[i] = length2;
        }

    }
    for(int i =0;i<t;i++){
        cout<<arr[i]<<endl;
    }
    return 0;

}
