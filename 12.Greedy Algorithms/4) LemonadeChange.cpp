#include <iostream>
using namespace std;

// One lemonade price is 5 fixed
bool lemonadeChange(vector<int>& bills){
    int five = 0;
    int ten = 0;
    for(int it:bills){
        if(it==5){
            five++;
        }
        else if(it==10){
            if(five==0) return false;
            five--;
            ten++;
        }
        else{
            if(ten>0 && five>0){
                ten--;
                five--;
            }
            else if(five>=3){
                five -= 3;
            }
            else{
                return false;
            }
        }
    }

    return true;
}