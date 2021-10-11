#include<iostream>
#include<cmath>


using namespace std;


int main(){
    int t;
    cin>>t;
    for(int i = 0; i<t; i++){
        long int x;
        cin>>x;
        long int N = (long int )log2(x+1);
        long int res = pow(2,N);
        cout<<res<<endl;


    }
    return 0;
}