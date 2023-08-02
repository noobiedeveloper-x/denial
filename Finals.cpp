// File Headers to be used:
#include <unistd.h>
#include <iomanip>
#include <cstdio>
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>


using namespace std;


// Global Variables
string Username, Password;
char Selections;
int tries = 0, Options;
char P_ID[50], P_NAME[50], P_LNAME[50], P_SNTC[50], P_TRL[50], P_CRM[50], P_RD[50];
const int maximumrow = 10;
string Prisoner_ID[maximumrow];
string Prisoner_NAME[maximumrow];
string Prisoner_LASTNAME[maximumrow];
string Prisoner_SENTENCE[maximumrow];
string Prisoner_TRIAL[maximumrow];
string Prisoner_CRIME[maximumrow];
string Prisoner_RELEASEDATE[maximumrow];

// Security Login
int Log_in() {
    while (tries < 3) {
        cout << "<=============[\033[34mWELCOME ADMIN PRISON MANAGEMENT SYSTEM\033[0m]=============>" << endl;
        cout << "USERNAME: ";
        cin >> Username;
        cout << "PASSWORD: ";
        cin >> Password;

        // Check if the username and password match to continue to the main program
        if (Username == "ADMIN" && Password == "ADMIN") {
            cout << "\033[32mSUCCESS!!\033[0m" << endl;
            sleep(5);
            system("CLS");
            break;
        } else {
            cout << "\033[31mPLEASE TRY AGAIN!\033[0m" << endl;
            sleep(1);
            system("CLS");
            tries++;
        }

        if (tries == 3) {
            exit(1);
        }
    }

    return 0;
}
//#############CREATE RECORD
void Create_Record(){
system("CLS");
cout << "[\033[32mG\033[0m] GREEN SIGN MEANS IT'S SUCCESSFUL [\033[31mR\033[0m] RED SIGN MEANS AN ERROR OCCURRED [\033[33mY\033[0m] YELLOW SIGN IS WARNING" << endl;
bool alreadyExists = false;

cout << "ENTER PRISONER ID NUM: ";
cin.ignore();
cin.getline(P_ID, 50);


// Check if the ID already exists
for (int i = 0; i < maximumrow; i++) {
    if (Prisoner_ID[i] == P_ID) {
        cout << "\033[33mALREADY ADDED\033[0m" << endl;
     sleep(2);
        alreadyExists = true;
        break;
    }
}
//check if the database is already full
for (int numEntries = 0; numEntries < maximumrow; numEntries++){
if (numEntries == maximumrow) {
        cout << "\033[33mMAXIMUM NUMBER OF ENTRIES REACHED. CANNOT CREATE MORE ENTRIES.\033[0m" << endl;
        sleep(2);
      return;
    }

}
if (!alreadyExists) {
    for (int i = 0; i < maximumrow; i++) {
        if (Prisoner_ID[i].empty()) {
            cout << "ENTER PRISONER NAME: ";
            cin.getline(P_NAME, 50);
            cout << "ENTER PRISONER LASTNAME: ";
            cin.getline(P_LNAME, 50);
            cout << "ENTER PRISONER SENTENCE: ";
            cin.getline(P_SNTC, 50);
            cout << "ENTER PRISONER TRIAL DATE: ";
            cin.getline(P_TRL, 50);
            cout << "ENTER PRISONER CRIME/CASE: ";
            cin.getline(P_CRM, 50);
            cout << "ENTER PRISONER RELEASE DATE: ";
            cin.getline(P_RD, 50);

            // Store the prisoner data in the arrays
            Prisoner_ID[i] = P_ID;
            Prisoner_NAME[i] = P_NAME;
            Prisoner_LASTNAME[i] = P_LNAME;
            Prisoner_SENTENCE[i] = P_SNTC;
            Prisoner_TRIAL[i] = P_TRL;
            Prisoner_CRIME[i] = P_CRM;
            Prisoner_RELEASEDATE[i] = P_RD;

            // Open the CSV file in append mode, write prisoner data, and close the file
            ofstream file("prisoner_records.csv", ios::app);
            if (file.is_open()) {
                file << P_ID << "," << P_NAME << "," << P_LNAME << "," << P_SNTC << "," << P_TRL << "," << P_CRM << "," << P_RD << "\n";
                sleep(3);
                cout << "\033[32mDATA ENTRY HAS BEEN ADDED AND SAVED TO CSV FILE!! \033[0m" << endl;
                file.close();  // Close the file after writing
            } else {
                cout << "\033[31mCSV FILE DAMAGED, NOT OPENED, OR NOT FOUND. PLEASE CHECK AGAIN! \033[0m" << endl;
            }

            break;
            }
        }
    }

}


//############DISPLAY RECORDS
void Display_Record() {
    ifstream file("prisoner_records.csv");
    int checker_exist = 0;
    string line;

    if (file.is_open()) {
        system("CLS");
        cout << setw(100) << "|<-----\033[35mPRISONER RECORDS\033[0m----->|" << endl;
        cout << "+---------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
        cout << "|        ID          |       NAME         |      LASTNAME      |      SENTENCE      |       TRIAL        |       CRIME        |          RELEASEDATE      |" << endl;
        cout << "|--------------------+--------------------+--------------------+--------------------+--------------------+--------------------+---------------------------|" << endl;

        // Skip the header line
        getline(file, line);

       //OUTER WHILE LOOP
        while (getline(file, line)) {
            stringstream ss(line);
            string token;
            vector<string> tokens;
         //INNER WHILE LOOP
            while (getline(ss, token, ',')) {
                tokens.push_back(token);
            }

            if (tokens.size() == 7) {
                 cout << "| " << setw(18) << left  << tokens[0] << " |";
                cout << " " << setw(18)<< left   << tokens[1] << " |";
                cout << " " << setw(18) << left << tokens[2] << " |";
                cout << " " << setw(18) << left  << tokens[3] << " |";
                cout << " " << setw(18) << left  << tokens[4] << " |";
                cout << " " << setw(18) << left  << tokens[5] << " |";
                cout << " " << setw(25) << left  << tokens[6] << " |" << endl;
                checker_exist++;
            }
        }

        if (checker_exist == 0) {
            cout << "\033[31m                                                                 No records found!                                                 \033[0m" << endl;
        }

        cout<< "|--------------------+--------------------+--------------------+--------------------+--------------------+--------------------+---------------------------|" << endl;
    } else {
        cout << "Failed to open the CSV file." << endl;
    }
}
void Search_Record(string P_ID) {
  system("CLS");
  ifstream file("prisoner_records.csv");
  bool check_existed = false;

  cout << "ENTER NUMBER ID TO SEARCH IN THE DATABASE: ";
  cin >> P_ID;


  // Check in the file
  string line;
  while (getline(file, line)) {
    if (line.find(P_ID) != string::npos) {
      check_existed = true;
      break;
    }
  }
  file.close();
//#######Check if existed or not return to main screen after (5 seconds)
  if (!check_existed) {
    cout << "\033[33mUSER NOT FOUND IN THE DATABASE\033[0m" << endl;
  } else {
      Display_Record();
    cout << "\033[32mUSER FOUND IN THE DATABASE\033[0m" << endl;
    sleep(1);
  }

  for (int i = 6; i > 0; i--) {
   cout << "RETURNING TO THE MAIN SCREEN: [" << i << "]"<<endl;
  sleep(1);
}
  sleep(1);
    system("CLS");
    return;
}

//######### UPDATE A RECORD
void Update_Record(string P_ID) {
  system("CLS");
  bool prisonerFoundArray = false;
  bool prisonerFoundExcel = false;
  int arrayIndex;

  cout << "ENTER PRISONER ID TO UPDATE RECORD: ";
  cin.ignore();
  getline(cin, P_ID);



  // Check if the ID exists in the Excel file
  ifstream file("prisoner_records.csv");
  string line;
  vector < string > excelData;
  while (getline(file, line)) {
    if (line.find(P_ID) != string::npos) {
      prisonerFoundExcel = true;
      excelData.push_back(line);
    }
  }
  file.close();
// Update new information for a specific prisoner ID
if (prisonerFoundArray || prisonerFoundExcel) {
  // Prompt for the new values that will be stored for the prisoner
  char newPrisonerName[50], newPrisonerLastName[50], newPrisonerSentence[50], newPrisonerTrial[50], newPrisonerCrime[50], newPrisonerReleaseDate[50];
  cout << "ENTER NEW NAME: ";
  cin.getline(newPrisonerName, 50);
  cout << "ENTER NEW LASTNAME: ";
  cin.getline(newPrisonerLastName, 50);
  cout << "ENTER NEW SENTENCE: ";
  cin.getline(newPrisonerSentence, 50);
  cout << "ENTER NEW TRIAL DATE: ";
  cin.getline(newPrisonerTrial, 50);
  cout << "ENTER NEW CRIME/CASE: ";
  cin.getline(newPrisonerCrime, 50);
  cout << "ENTER NEW RELEASE DATE: ";
  cin.getline(newPrisonerReleaseDate, 50);

  // Update the record in the array
  if (prisonerFoundArray) {
    Prisoner_NAME[arrayIndex] = newPrisonerName;
    Prisoner_LASTNAME[arrayIndex] = newPrisonerLastName;
    Prisoner_SENTENCE[arrayIndex] = newPrisonerSentence;
    Prisoner_TRIAL[arrayIndex] = newPrisonerTrial;
    Prisoner_CRIME[arrayIndex] = newPrisonerCrime;
    Prisoner_RELEASEDATE[arrayIndex] = newPrisonerReleaseDate;
  }

  // Update the record in the Excel file
  ifstream inFile("prisoner_records.csv");
  ofstream tempFile("temp.csv");

  if (inFile.is_open() && tempFile.is_open()) {
    string line;
    while (getline(inFile, line)) {
      if (line.find(P_ID) != string::npos) {
        line = P_ID + "," + newPrisonerName + "," + newPrisonerLastName + "," +
          newPrisonerSentence + "," + newPrisonerTrial + "," +
          newPrisonerCrime + "," + newPrisonerReleaseDate;
      }
      tempFile << line << "\n";
    }

    inFile.close();
    tempFile.close();

    // Remove the existing file
    if (remove("prisoner_records.csv") != 0) {
      cout << "Error deleting the existing file." << endl;
    }

    // Rename the updated file with the existing file name
    if (rename("temp.csv", "prisoner_records.csv") != 0) {
      cout << "Error renaming the file." << endl;
    }
  } else {
    cout << "Error opening the input/output files." << endl;
  }

  cout << "\033[32mSUCCESS UPDATING INFORMATION TO PRISONER!!\033[0m" << endl;
  sleep(1);
  system("CLS");
} else {
  cout << "\033[33mNO PRISONER FOUND WITH THAT ID! RETURNING TO THE MAIN SCREEN\033[0m" << endl;
  for (int i = 6; i > 0; i--) {
    cout << "RETURNING TO THE MAIN SCREEN: [" << i << "]" << endl;
    sleep(1);
  }
  sleep(1);
  system("CLS");
  return;
}

}
//####### CREATE A RECORD
void Delete_Record(string P_ID) {
    system("CLS");
    bool prisonerFoundArray = false;
    bool prisonerFoundExcel = false;
    int arrayIndex = -1;

    cout << "ENTER PRISONER ID TO DELETE RECORD: ";
    cin.ignore();
    getline(cin, P_ID);

    // Check if the ID exists in the array
    for (int i = 0; i < maximumrow; i++) {
        if (Prisoner_ID[i] == P_ID) {
            prisonerFoundArray = true;
            arrayIndex = i;
            break;
        }
    }

    // Check if the ID exists in the Excel file
    ifstream file("prisoner_records.csv");
    string line;
    vector<string> excelData;
    while (getline(file, line)) {
        if (line.find(P_ID) != string::npos) {
            prisonerFoundExcel = true;
            excelData.push_back(line);
        }
    }
    file.close();

    if (prisonerFoundArray || prisonerFoundExcel) {
        // Remove the record from the array
        if (prisonerFoundArray) {
            Prisoner_ID[arrayIndex].clear();
            Prisoner_NAME[arrayIndex].clear();
            Prisoner_LASTNAME[arrayIndex].clear();
            Prisoner_SENTENCE[arrayIndex].clear();
            Prisoner_TRIAL[arrayIndex].clear();
            Prisoner_CRIME[arrayIndex].clear();
            Prisoner_RELEASEDATE[arrayIndex].clear();
        }

        // Remove the record from the Excel file
        ifstream inFile("prisoner_records.csv");
        ofstream tempFile("temp.csv");

        if (inFile.is_open() && tempFile.is_open()) {
            string line;
            while (getline(inFile, line)) {
                if (line.find(P_ID) == string::npos) {
                    tempFile << line << "\n";
                }
            }

            inFile.close();
            tempFile.close();

            // Remove the existing file
            if (remove("prisoner_records.csv") != 0) {
                cout << "Error deleting the existing file." << endl;
            }

            // Rename the updated file with the existing file name
            if (rename("temp.csv", "prisoner_records.csv") != 0) {
                cout << "Error renaming the file." << endl;
            } else {
                cout << "\033[32mRecord deleted successfully!\033[0m" << endl;
                sleep(1);
                system("CLS");
            }
        } else {
            cerr << "Error opening the input/output files." << endl;
        }
    } else {
        sleep(1);
        cout << "\033[33mRecord not found in the database.\033[0m" << endl;
        system("CLS");
    }
}




int main() {
    char Selections;

     Log_in();
    while (Options != 6) {
        // Display the main menu options
        cout << "[\033[31mP\033[0m]RISON [\033[31mM\033[0m]ANAGEMENT MAIN-MENU" << endl;
        cout << "1.CREATE A RECORD" << endl;
        cout << "2.UPDATE A RECORD" << endl;
        cout << "3.DELETE A RECORD" << endl;
        cout << "4.SEARCH A RECORD" << endl;
        cout << "5.DISPLAY ALL RECORDS" << endl;
        cout << "6.LOGOUT AND SAVE UPDATES TO EXCEL" << endl;
        cout << "ENTER COMMAND:";

        // Read the user's choice
        cin >> Options;

        if (Options == 1) {
            // Call the function to create a record
            Create_Record();
            system("CLS");
        } else if (Options == 2) {
            // Call the function to update a record
            Update_Record(P_ID);
        } else if (Options == 3) {
            // Call the function to delete a record
            Delete_Record(P_ID);
        } else if (Options == 4) {
            // Call the function to search for a record
            Search_Record(P_ID);
        } else if (Options == 5) {
            system("CLS");
            // Handle option 5 - display all records
            Display_Record();

            // Prompt the user to return to the main menu or exit
            cout << "[\033[32mR\033[0m] TYPE R TO RETURN TO MAIN MENU OR TYPE ANYTHING TO [\033[31mE\033[0m]XIT THE PROGRAM" << endl;
            cout << "ENTER COMMAND: ";
            cin >> Selections;

            if (Selections == 'R' || Selections == 'r') {
                // Clear the screen and continue to the next iteration of the loop
                system("CLS");
                continue;
            } else {
                // Break the loop and exit the program
                break;
            }
        } else if (Options == 6) {
            // Exit the program
            cout << "BYEE!!!" << endl;
            exit(1);
        } else {
            // Handle invalid input
            cout << "INVALID INPUT" << endl;
            cin.clear();               // Clear the error state
            cin.ignore(10000, '\n');   // Discard the invalid input
            system("CLS");
        }
    }

    return 0;
}
