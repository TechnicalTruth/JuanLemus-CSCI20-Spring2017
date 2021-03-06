#include <iostream>
#include <string>

using std :: cin;
using std :: cout;
using std :: endl;
using std :: string;

int main(){
    int numVal = 10;
    string menuItem[numVal];
    double prodCost[numVal];
    int stockLeft[numVal];
    string prodNum[numVal];
    int i = 0;
    
    int prodNumber = 0;
    int request = 0;
    double totalCost = 0.0;
    double itemCost = 0.0;
    int numTaken = 0.0;
    int qtyWanted= 0;
    bool buyMore = true;
    
    //Numbered list of items on sale
    prodNum[0] = "1. ";
    prodNum[1] = "2. ";
    prodNum[2] = "3. ";
    prodNum[3] = "4. ";
    prodNum[4] = "5. ";
    prodNum[5] = "6. ";
    prodNum[6] = "7. ";
    prodNum[7] = "8. ";
    prodNum[8] = "9. ";
    prodNum[9] = "10. ";
    
    //Actual product for each index
    menuItem [0] = "Apple";
    menuItem [1] = "Bannana";
    menuItem [2] = "Orange";
    menuItem [3] = "Pineapple";
    menuItem [4] = "Kiwi";
    menuItem [5] = "Pear";
    menuItem [6] = "Strawberry";
    menuItem [7] = "Raspberry";
    menuItem [8] = "Blueberry";
    menuItem [9] = "Blackberry";
    
    //Item cost
    prodCost[0] = 0.60;
    prodCost[1] = 0.50;
    prodCost[2] = 0.75;
    prodCost[3] = 0.80;
    prodCost[4] = 1.75;
    prodCost[5] = 0.50;
    prodCost[6] = 0.65;
    prodCost[7] = 0.99;
    prodCost[8] = 1.25;
    prodCost[9] = 1.00;
    
    //Amount of items left
    stockLeft[0] = 10;
    stockLeft[1] = 10;
    stockLeft[2] = 15;
    stockLeft[3] = 20;
    stockLeft[4] = 18;
    stockLeft[5] = 10;
    stockLeft[6] = 10;
    stockLeft[7] = 10;
    stockLeft[8] = 25;
    stockLeft[9] = 18;
    
    
    for( i = 0; i < numVal; ++i){
        cout << prodNum[i] << menuItem[i] << "  $";
        cout << prodCost[i] << " each!" << endl;
    }
    
    cout << "You can exit at any time by entering '0'" << endl;
    
    while (buyMore == true){
        cout << "Choose a product (1-10)." << endl;
        cin >> numVal;
        
        numVal = numVal - 1; // index and menu are off my 1 unit
        
//Ensures that user doesn't enter an invalid index value
        if(numVal >= 0 && numVal < 10){
            cout << "You have chosen: " << menuItem[numVal] << endl;
            cout << "How many of them would you like? Currentlly in stock: " << stockLeft[numVal] << "." << endl;
            cin >> qtyWanted;
        }
        
//if out of stock, this loop runs
       while (stockLeft[numVal] == 0){
            
            cout << "We are very sorry, we are out of that product. Please choose another item: ";
            cin >> numVal;
            numVal = numVal - 1;
            
            if (numVal == -1){
                buyMore == false;
            }
        }
        
        

        
        if(qtyWanted > stockLeft[numVal]){
            cout << "Sorry, we currently only have: " << stockLeft[numVal] << ". Would you like to take the rest (1 for yes, 0 for no)?" << endl;
            cin >>  numTaken;
                if(numTaken == 1){
                    stockLeft[numVal] = 0;
                    
                }
//reduces the amount in stock
        if(qtyWanted <= stockLeft[numVal]){
            stockLeft[numVal] = stockLeft[numVal] - qtyWanted;
        }
        }
        
//sets user's total cost
        itemCost = prodCost[numVal] * qtyWanted;
        totalCost = totalCost + itemCost;
        
        }
        
//outputs customer's total
            cout << "Your total today will be: " << totalCost << endl;
            cout << "Tank you come again!" << endl;
            
            return 0;
}