#include <iostream>
#include <string>
using namespace std;

int remaining = 0, sum, deposit, withdraw, pcode, counter = 0;
string username;


void log_on(){
 while (counter != 3){
    cout << "<-----USERLOGIN ATM----->" << endl;
    cout << "ENTER USERNAME: ";
    cin >> username;
    cout << "ENTER PIN: ";
    cin >> pcode;


     if (username == "admin" &&  pcode == 5555){
        cout << "SUCCESS!" << endl;
        break;
     }else {
       cout << "ERROR ";
       counter++;
     }

    if (counter == 3){
        exit(1);
        }
 }

}

void bank (){
    const  string black = "        * ******************************************************************";
    const  string white = "       I                        CATACUTAN MJ ATM                                 I";
    const  string lines = "        *******************************************************************";
      cout << black << endl;
      cout << white << endl;
      cout << lines << endl;
      cout << "                           1. CHECK BALANCE "  << endl;
      cout << "                           2. DEPOSIT "  << endl;
      cout << "                           3. WITHDRAW "  << endl;
      cout << "                           4. LOGOUT   " << endl;

}

int remaining_cash(){

cout << "---------------------------------REMAINING CASH---------------------------------" <<endl;
cout << "-------------------------------- P: ["  << sum <<   "]---------------------------------" <<endl;
  return 0;
}

int input_cash (){
 cout << "--------------------------------ENTER THE AMOUNT YOU WANNA PUT------------------" <<endl;
 cout << "------------------------------"<<endl; cin >> deposit; cout <<"-----------------" <<endl;
 sum = deposit + remaining;
 cout << "--------------------------------REMAINING CASH: [" << sum << "]-------------" << endl;
   return 0;
}

int withdraw_cash(){

  if (withdraw > remaining){
    cout << "-------------------------------ENTER AMOUNT YOU WANNA WITHDRAW----------------" << endl;
  cout << "--------------------------------P ";  cin >> withdraw;  cout << "-----------------" << endl;
  sum = sum - withdraw;
  cout << "--------------------------------successfully withdraw-------------------------" << endl;
  cout << "--------------------------------------Remaining Cash--- P: [" << sum << "]----------" << endl;
  }else {
    cout << "INVALID" << endl;
  }
  return 0;
}

void logout(){
   log_on();
}


int main()
{
   char functi0n;
   int trigger = 0;
   log_on();
   bank();
   cin >> functi0n;

   while (trigger < 5000){
   if (functi0n == '1'){
        remaining_cash();
       cout << "Do you wanna return? y/n" << endl;
       cin >> functi0n;
   }if (functi0n == 'y'){
        bank();
        cout << "ENTER NUMBER" << endl;
        cin >> functi0n;
   }else if (functi0n == '2'){
       input_cash();
       cout << "DO YOU WANNA GO BACK? y/n" << endl;
       cin >> functi0n;
}  else if (functi0n == '3'){
         withdraw_cash();
         cout << "DO YOU WANNA GO BACK? y/n" << endl;
       cin >> functi0n;
} else if (functi0n == '4'){
 logout();
}

return 0;

}
}
