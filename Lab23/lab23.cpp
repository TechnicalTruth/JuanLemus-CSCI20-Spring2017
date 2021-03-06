//Name: Juan Lemus
/* Lab Description: Calling functions withing other functions in order to swap
variables and continue to use them within the outside funcition. Also, we 
are using pass by reference to be able to use new vairable values as opposed to 
directly referencing the user's input. */
//Date: 2/23/17

#include <iostream>
#include <cstdlib>  //Enables use of rand()     **really weird, doesnt have to be declared?
#include <ctime>    //Enables use of time()

using std :: cin;
using std :: cout;
using std :: endl;

void swapFunc(int& upLim, int& lowLim);
int rndmNum(int upLim, int lowLim);                     //functions are declared


int main(){
    
    int lowLim = 0;
    int upLim = 0;
    int usrRndNum = 0;
    
    
    cout << "Please enter a lower limit: ";                  
    cin >> lowLim;
    cout << "Please enter an upper limit: ";
    cin >> upLim;
    
    
    usrRndNum = rndmNum(upLim, lowLim);
    
    cout << "_________________________________" << endl;
    cout << "You entered a lower Limit of: " << lowLim << endl;
    cout << "You entered an upper limit of: " << upLim << endl;
    cout << "Your random number is: " << usrRndNum << endl;
    cout << "_________________________________" << endl; 
    
    return 0;
    
}

                                                   //functions are being defined
  
void swapFunc(int& upLim, int& lowLim){

    int tempVarA = 0;
    int tempVarB = 0;
    
    tempVarA = upLim;     //Facilitating value swap by using temporary variables
    tempVarB = lowLim;
    
    upLim = tempVarB;          //Assinging new values to original user variables
    lowLim = tempVarA;
    

    return;
    
}

int rndmNum (int upLim, int lowLim){      
    
    int usrRndNum = 0;
    
    srand(time(0));
    
    swapFunc(upLim, lowLim);    //Swapping user Values inside rndmNum() fucntion
    
    usrRndNum = ((rand() % (lowLim - upLim)) + upLim);   
                                         //creates rndm number in between limits
    
    return usrRndNum;
}

