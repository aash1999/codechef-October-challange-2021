#include<iostream>
#include<vector>

class Digit{
    public :
        int digit;
        int yes;
};

using namespace std;


int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        vector<Digit> num , out;
        vector<Digit>::iterator lastptr;
    
        int there=0;
        long int mor ;
        int key;
        cin>>mor>>key;
        int indexcount=0 , lastindex=-1;

        do{
            Digit tempObj;
            tempObj.digit = mor%10; 
            if(tempObj.digit == key ){  
                tempObj.yes =1;
                there =1;
            }
            else tempObj.yes =0;

            mor = mor/10; 
            num.push_back(tempObj);  
            if(tempObj.digit == key ){
                lastptr = --num.end();
                lastindex = indexcount;
            }
            //cout<<"last : "<<lastptr->digit<<endl;
            ++indexcount;
            
        }while(mor != 0);

        if(there == 0){
            cout<<0<<endl;
            //cout<<"there";
            //return 0;
        }else{
            //1->1[*]
            vector<Digit>::iterator itr;
            int carry =0;
            indexcount =0;
            for(itr = num.begin() ; itr!=num.end() ; ++itr){
                Digit tempout;
                if(indexcount == lastindex){
                    if(carry ==0 ){
                        tempout.digit=1; //1
                        out.push_back(tempout);//1->
                    }else{
                        tempout.digit=0;
                        out.push_back(tempout);

                    }

                    //if(itr->digit+tempout.digit + carry >=10){ 
                    vector<Digit>::iterator titr = num.begin()+indexcount+1;
                    //cout<<">> "<<titr->digit<<endl;
                    if(itr->digit +tempout.digit+carry >=10 )
                    carry=1;
                    else
                    carry =0;
                    while(titr != num.end()){
                        if((titr->digit + carry)%10 == key ){  
                            tempout.digit = 1;
                            if(titr->digit + carry + tempout.digit >=10 ){
                                carry =1;
                            }else{
                                break;
                            }
                        }else{
                            tempout.digit = 0;
                            break;
                        }
                        out.push_back(tempout);
                        ++titr;
                    }
                    break;
                }

                tempout.digit = itr->digit+carry; 
                tempout.digit = 10-tempout.digit ; 
                if((itr->digit+tempout.digit + carry )%10 == key){
                    tempout.digit++;
                }
                if(itr->digit+(tempout.digit)%10 + carry >=10){ //
                    carry =1;
                    
                }else{
                    carry =0;
                }
                tempout.digit = tempout.digit%10; //9


                out.push_back(tempout);//5->7->



                ++indexcount;
            }

            int outdigit=0;
            int mult =1;

            vector<Digit>::iterator oitr;

            for(oitr = out.begin();oitr!=out.end() ; ++oitr ){
                outdigit+= oitr->digit*mult;
                mult*=10;
            }

            cout<<outdigit<<endl;

        }


    }
}
