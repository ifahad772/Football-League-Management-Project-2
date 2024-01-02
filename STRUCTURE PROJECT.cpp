#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cstdio>

using namespace std;

const int SIZE = 4;
const int MAX_RECORDS = 11;
int rows = 0;


struct player {
    int playernumber;
    char playername[20];
    string clubname;
    string coach;
};

struct playerinfo {
    player record;
    double goals;
    double assists;
    int matches;
};

struct transferrecord {
    player record;
    string transferdata;
    string retainorrelease;
};


player footballer;
playerinfo footballerinfo[MAX_RECORDS][SIZE];
transferrecord player1;


void addrecord();

void addrecord() {
    system("cls");

    ofstream fout("FootballManagement.txt", ios::app);

    if (fout.is_open()) {
        cout << "Enter Player Number: ";
        cin >> footballer.playernumber;
        cout << "Enter Player Name: ";
        cin >> footballer.playername;
        cout << "Enter Club Name: ";
        cin >> footballer.clubname;
        cout << "Enter Name Of the Coach: ";
        cin >> footballer.coach;

        cout << "Record Added Successfully!" << endl;

        fout << footballer.playernumber << '\t'
            << footballer.playername << '\t'
            << footballer.clubname << '\t'
            << footballer.coach << endl;


        fout.close();
    }
    else {
        cout << "Error In Opening File!" << endl;
    }
}

void viewrecord() {
    system("cls");
    ifstream fin;// opens file in read mode
    fin.open("FootballManagement.txt");// file specified to be opened
    if (fin.is_open()) {
        // exception handling applied in case file is not opened or not found

        cout << "Number" << setw(9) << "Name" << setw(14) << "Club" << setw(16) << "Coach" << endl; // displaying output with proper spacing / indentation
        // while loop is used to read data from the file ( reads all the data from the file )
        while (fin >> footballer.playernumber >> footballer.playername >> footballer.clubname >> footballer.coach) {
            cout << footballer.playernumber << setw(15) << footballer.playername << setw(15) << footballer.clubname << setw(15) << footballer.coach << endl;// displays all the available and read data 
        }
        fin.close();// closing the file
    }
    else {
        cout << "Error In Opening File!";
    }
}

void findplayer() {
    system("cls");
    int playernumber;// declaring integer variable for player number 
    
   
    cout << "Enter the Number  of Player to Find:"; // prompts user to input the player number he wants to find
    cin >> playernumber;// takes input from user / varibale stores value
    ifstream fin;// fin is used to open file in read mode
    fin.open("FootballManagement.txt");// file specified to be opened
    // exception handling applied in case file is not opened or not found 

    // while loop reads the data from the from file 
    while (fin >> footballer.playernumber>> footballer.playername >> footballer.clubname >> footballer.coach) {
        // condition is applied to check the input taken from user if it matches any number stored in the file
        if (playernumber == footballer.playernumber) {
            // if condition is met function displays this output
            cout << "Match has been found! " << endl;
            cout << "Number" << setw(9) << "Name" << setw(14) << "Club" << setw(16) << "Coach" << endl;
            cout << footballer.playernumber<< setw(15) << footballer.clubname << setw(15) << footballer.clubname << setw(15) << footballer.coach << endl;// variables output their stored values

            return;// no specified return value because void is used 
        }
    }
    // program displays this output if condition is not met
    cout << "Match not found!" << endl;
    fin.close();// closing the file
}

void deleteplayer() {
    system("cls");
    cout << "Enter The Number Of the Player You Want To Delete: ";
    int playernumberDelete; // string variable to take input ( after update of ide we can take int input in string ), if we take both input in int it deletes all data from file not specific
    // to take input in int we will have to then convert the input into string in order to apply a condition because data is read in string and input is in int
    // stoi will be used then ( stoi = string to integer )
    cin >> playernumberDelete;// takes user input

    ifstream fin;// opens file in read mode
    fin.open("FootballManagement.txt");// file specified to be opened
    // exception handling applied in case file is not opened or not found 
  
    ofstream fout("temp.txt", ios::app);// Create a temporary file for writing


   

    bool recordFound = false; // bool is declared either true or false, we will be declaring it as false first
    // while loop to read data from file 
    while (fin >> footballer.playernumber >> footballer.playername >> footballer.clubname >> footballer.coach) {
        // condition to check user input and read data from file to find needed data / desired output 
        // condition checks if the entered value is equal or not and condition is true or false accordingly
        if (footballer.playernumber != playernumberDelete)// if input was in int this condition would have produced an error or we would have to use stoi 
        {
            fout << footballer.playernumber << setw(15) << footballer.playername << setw(15) << footballer.clubname << setw(15) << footballer.coach << endl;
        }
        // e;se runs if entered value is equal or found in file
        else {
            recordFound = true;
        }
    }

    fin.close();// closing main file opened in read mode
    fout.close();// closing temporary file created in write mode


    remove("FootballManagement.txt"); // enabled by cstdio library used to rename a file
    rename("temp.txt", "FootballManagement.txt");// first argument is temporary file and it will be renamed to the second argument which will be the new name of the new file
    // if bool is true program displays this output
    if (recordFound) {
        cout << "Record Deleted Successfully." << endl;
    }
    // if false then record not found
    else {
        cout << "Record not found." << endl;
    }
}

void updaterecord() {
    system("cls");
    cout << "Enter The Player Number To Update: ";// prompts user to input desired player number needed to update
    int playernumbertoupdate;// variabled declared to take input from user
    cin >> playernumbertoupdate; // takes input from user stores entered value

    ifstream fin;// opens file in read mode
    fin.open("FootballManagement.txt");// specified file to be opened
  
    ofstream fout("temp.txt");// temporary file opened in write mode , if it is opened in append mode data will not be updated

  

    bool recordFound = false;// bool is declared either true or false, we will be declaring it as false first
    // while loop is used to read data from file
    while (fin >> footballer.playernumber >> footballer.playername >> footballer.clubname >> footballer.coach)
    {
        // if entered value matches value in file flag / bool is true and code runs further
        if (playernumbertoupdate == footballer.playernumber) {
            recordFound = true;
            // prompts user to enter the updated data / can enter the same data in other fields if user only wants to update specific data
            cout << "---* Enter Same Data In Field You Don't Want to update *---\n";
            cout << "Enter The Updated Number of Player : ";
            cin >> footballer.playernumber; // inputs updated player number

            cout << "Enter The Updated Name of Player: ";
            cin >> footballer.playername;// inputs updated Name

            cout << "Enter The Updated Name of Club: ";
            cin >> footballer.clubname;// inputs updated club name

            cout << "Enter The Updated Name of Coach: ";
            cin >> footballer.coach;// inputs updated coach name;
        }
        // fout stores the updated data to temp file and skips the old file
        fout << footballer.playernumber << setw(15) << footballer.playername << setw(15) << footballer.clubname << setw(15) << footballer.coach << endl;
    }

    fin.close();//closing file opened in read mode
    fout.close();// closing temporary opened file in write mode

    remove("FootballManagement.txt"); // enabled by cstdio library used to rename a file
    rename("temp.txt", "FootballManagement.txt");// first argument is temporary file and it will be renamed to the second argument which will be the new name of the new file
    // if condition is met and record is found and updated program displays this output
    if (recordFound) {
        cout << "Record Updated Successfully." << endl;
    }
    // program displays this output if condtion is not met bool is false
    else {
        cout << "Record not found." << endl;
    }
}

void firstmenu() {
    system("cls");// to have clear output
    // void is used to call function so there will be no specific return written
    cout << "                     ----*----                     " << endl; // added to make output presentable
    cout << "*--------FOOTBALL LEAGUE MANAGEMENT SYSTEM---------*\n";// Displaying Name of Management Program 
    cout << "*---Choose One Of The Following Actions To Perform!---*" << endl; // Giving user choice to choose his desired operation
    cout << "1. Add Record\n2. View Record\n3. Find Player\n4. Delete Player Record\n5. Update Record\n6. Exit" << endl; // operations which are performable are listed
    int option;// integer variable declared to take input from user 
    cin >> option;// value assigned to integer by user
    // switch is used to call corresponding function based on user input
    switch (option) {
    case 1: // calls add record function
        cout << " Add Record!\n";
        addrecord();
        break; // switch runs again
    case 2:// calls view record function
        cout << "View Records!\n";
        viewrecord();
        break;// switch runs again
    case 3: // calls find player function
        cout << " Find Player!\n";
        findplayer();
        break;// switch runs again
    case 4:// calls delete player function
        cout << "Delete Player Record!\n";
        deleteplayer();
        break;// switch runs again
    case 5:// calls update record function
        cout << "Update Record!\n";
        updaterecord();
        break;// switch runs again
    case 6:
        cout << "Program Ends";
        break;
    default:
        cout << "Invalid Option\n";
    }
}

void addarray(playerinfo playerrecord[][SIZE]) {
    system("cls");
    if (rows < MAX_RECORDS) 
        
    {
        ofstream fout;
        fout.open("footballerinfo.txt", ios::app);

        cout << "Enter Player ID: "; 
        cin >> playerrecord[rows][0].record.playernumber;
        cout << "Enter Number Of Matches Played By Player: "; 
        cin >> playerrecord[rows][1].matches;
        cout << "Enter Number Of Goals Scored By Player: ";
        cin >> playerrecord[rows][2].goals;
        cout << "Enter Number Of Assists Provided By Player: ";
        cin >> playerrecord[rows][3].goals;

        fout << playerrecord[rows][0].record.playernumber << " " << playerrecord[rows][1].matches << " " << playerrecord[rows][2].goals << " " << playerrecord[rows][3].assists << endl;

        cout << "RECORD ADDED SUCCESSFULLY!" << endl; // successfull record addition message
        rows++;// after record is added to first index it is incremented to next row for new record
        fout.close();
    }
    else {
        cout << "Maximum Amount of Records Reached!" << endl; 
    }

}

void viewarray( playerinfo playerrecord[][SIZE]) {
    
    system("cls"); 
    int row = 0;
    ifstream fin;
    fin.open("footballerinfo.txt");
    cout << "ID"  << setw(10) << "Matches" << setw(10) << "Goals"  << setw(10) << "Assists" << endl;

    while (fin>> playerrecord[rows][0].record.playernumber>> playerrecord[rows][1].matches>> playerrecord[rows][2].goals>> playerrecord[rows][3].assists)
    {
        
        cout << playerrecord[rows][0].record.playernumber  << setw(10) << playerrecord[rows][1].matches  << setw(10) << playerrecord[rows][2].goals  << setw(10) << playerrecord[rows][2].assists << endl;
        row++; 
    }
}

void findarray( playerinfo playerrecord[][SIZE])
{
    system("cls");
    ifstream fin;
    fin.open("footballerinfo.txt");

    int idtofind;
    cout << "Enter ID of Player To Find: "; 
    cin >> idtofind;
    while (fin >> playerrecord[rows][0].record.playernumber >> playerrecord[rows][1].matches >> playerrecord[rows][2].goals >> playerrecord[rows][3].assists) {

        rows++;
    }


    for (int i = 0; i < rows; i++) 
    {
        if (playerrecord[i][0].record.playernumber == idtofind)
        {
            cout << "MATCH FOUND!" << endl; 

        

            cout << "ID" << "\t" << setw(13) << "Matches" << "\t" << setw(10) << "Goals" << "\t" << setw(11) << "Assists" << endl; 
            
            cout << playerrecord[rows][0].record.playernumber << setw(10) << playerrecord[rows][1].matches << setw(10) << playerrecord[rows][2].goals << setw(10) << playerrecord[rows][3].assists << endl;
            fin.close();
            return;
        }
    }


   
    cout << "MATCH NOT FOUND!" << endl;
    fin.close();
}

void updatearray( playerinfo playerrecord[][SIZE]) {
    system("cls"); 
    
    ifstream fin;
    fin.open("footballerinfo.txt");
    
    ofstream fout;
    fout.open("temp.txt");

    int idtoupdate; 
    cout << "Enter ID To Update: ";
    cin >> idtoupdate;

    bool recordsfound = false; 
    int i = 0;
    

    for (int i = 0; i < rows; i++)
    {
        if (playerrecord[i][0].record.playernumber ==idtoupdate ) 
        {
            cout << "ID\tGoals\tMatches\tAssists\n";

            recordsfound = true; // bool is true

           
        }
    }

    if (recordsfound) {
        cout << "MATCH FOUND!" << endl;
        cout << playerrecord[rows][0].record.playernumber << setw(10) << playerrecord[rows][1].matches << setw(10) << playerrecord[rows][2].goals << setw(10) << playerrecord[rows][2].assists << endl;

        cout << "Enter Updated Information!" << endl; 
        cout << "---* Enter Same Data In Field You Don't Want to update *---\n"; 

       
        cout << "Enter Player ID: ";
        cin >> playerrecord[rows][0].record.playernumber; 
        cout << "Enter Number Of Matches Played By Player: ";
        cin >> playerrecord[rows][1].matches; 
        cout << "Enter Number Of Goals Scored By Player: ";
        cin >> playerrecord[rows][2].goals; 
        cout << "Enter Number Of Assists Provided By Player: ";
        cin >> playerrecord[rows][3].assists; 

        fout << playerrecord[rows][0].record.playernumber << " " << playerrecord[rows][1].matches << " " << playerrecord[rows][2].goals << " " << playerrecord[rows][3].assists << endl;
    }
    else {
        fout << playerrecord[rows][0].record.playernumber << " " << playerrecord[rows][1].matches << " " << playerrecord[rows][2].goals << " " << playerrecord[rows][3].assists << endl;
    }

    fin.close();
    fout.close();

    if(!recordsfound){
        cout << "Match Not Found.\n";
    
    }
    else {
        remove("footballerinfo.txt");
        rename("temp.txt", "footballerinfo.txt");
    }
}

void playertransfer(playerinfo playerrecord[][SIZE]) {
    system("cls");

    ifstream fin1("FootballManagement.txt");
    ifstream fin2("footballerinfo.txt");
    ofstream fout("footballerrecord.txt", ios::app);

    int idtransfer;
    cout << "Enter ID of the player you want to transfer: ";
    cin >> idtransfer;

    bool matchFound = false;

    while (fin1 >> footballer.playernumber >> footballer.playername >> footballer.clubname >> footballer.coach) {
        if (footballer.playernumber == idtransfer) {
            matchFound = true;

            cout << "Player Details:\n";
            cout << "Number" << setw(9) << "Name" << setw(14) << "Club" << setw(16) << "Coach" << endl;
            cout << footballer.playernumber << setw(15) << footballer.playername << setw(15) << footballer.clubname << setw(15) << footballer.coach << endl;

            while (fin2 >> playerrecord[rows][0].record.playernumber >> playerrecord[rows][1].matches >> playerrecord[rows][2].goals >> playerrecord[rows][3].assists) {
                fout << playerrecord[rows][0].record.playernumber << " " << playerrecord[rows][1].matches << " " << playerrecord[rows][2].goals << " " << playerrecord[rows][3].assists << " Released" << endl;
                rows++;
            }

            cout << "Player records transferred and marked as Released." << endl;
            break;
        }
    }

    if (!matchFound) {
        cout << "Player not found in the first file." << endl;
    }

    fin1.close();
    fin2.close();
    fout.close();
}

void viewplayertransfer(playerinfo playerrecord[][SIZE]) {
    ifstream fin;
    fin.open("footballerrecord.txt");

    if (!fin) {
        cerr << "Error opening file footballerrecord.txt" << endl;
        return;
    }

    cout << "Released Players are:\n";
    cout << "ID" << setw(10) << "Matches" << setw(10) << "Goals" << setw(10) << "Assists" << endl;

   
    while (fin >> playerrecord[rows][0].record.playernumber >> playerrecord[rows][1].matches >> playerrecord[rows][2].goals >> playerrecord[rows][3].assists) {
        cout << playerrecord[rows][0].record.playernumber << setw(10) << playerrecord[rows][1].matches << setw(10) << playerrecord[rows][2].goals << setw(10) << playerrecord[rows][3].assists << endl;
        rows++;
    }

    fin.close();
}



void secondmenu(playerinfo playerrecord[][SIZE]) {
    system("cls");// to have clear output
    // void is used to call function so there will be no specific return written
    cout << "                     ----*----                     " << endl; // added to make output presentable
    cout << "*--------FOOTBALL LEAGUE MANAGEMENT SYSTEM---------*\n";// Displaying Name of Management Program 
    cout << "*---Choose One Of The Following Actions To Perform!---*" << endl; // Giving user choice to choose his desired operation
    cout << "1. Add Record\n2. View Record\n3. Find Player\n4. Update Record\n5. Exit" << endl;// operations which are performable are listed
    int option;// integer variable declared to take input from user 
    cin >> option;// value assigned to integer by user
    // switch is used to call corresponding function based on user input
    switch (option) {

    case 1:// calls add record function
        cout << " Add Record!\n";
        addarray(playerrecord);// function called with passed array
        break;// switch runs again
    case 2:// calls view function
        cout << "View Records!\n";
        viewarray(playerrecord);// function called with passed array
        break;// switch runs again
    case 3:// calling find player function
        cout << " Find Player!\n";
        findarray(playerrecord);// function called with passed array
        break;// switch runs again
    case 4:// calling update record function
        cout << "Update Record!\n";
        updatearray(playerrecord);// function called with passed array
        break;// switch runs again
    case 5:// ends program in this case
        cout << "Program Ends";
        break;// program exits
    default:// invalid value entered
        cout << "Invalid Option\n";// error message
    }
}

void thirdmenu(playerinfo playerrecord[][SIZE])
{
    system("cls");
    cout << "Football League Management System" << endl;
    cout << "1. to caclulate average\n2. to view player average\n3. back\n";
    int option;
    cin >> option;

    // Switch case for handling user choices
    switch (option) {
    case 1:
        cout << "CALLING TRANSFER FUNCTION" << endl;
        playertransfer(playerrecord);
        break;
    case 2:
        cout << "CALLING VIEW FUNCTION" << endl;
        viewplayertransfer(playerrecord);
        break;
    case 3:
        break; // returns to main menu
    default:
        cout << "Invalid option. Try again." << endl; //if user select other number than given than we'll display this
    }
}
void mainmenu( playerinfo playerrecord[][SIZE]) {
    system("cls");// to have clear output

    while (true) // runs loops until exit is initiated
    {
        cout << "                     ----*----                     " << endl;// decorative line
        cout << "*--------FOOTBALL LEAGUE MANAGEMENT SYSTEM---------*\n";// program title
        cout << "*------------------MAIN MENU-----------------------*\n";// menu title
        cout << "1. MENU 1 ( Using File Handling )\n2. MENU 2 ( Using Arrays & Pointers )\n3. MENU 3 ( Linked Files )\n4. EXIT\n";// options availabe to use
        int mainmenuoption;// variable to take input / choice
        cin >> mainmenuoption;// stores input

        switch (mainmenuoption)// switch used to take choice input
        {
        case 1:// calls first menu
            firstmenu();// first menu called
            break;// switch runs again
        case 2:// calls second menu
            secondmenu(playerrecord);// second menu called
            break;// switch runs again
        case 3:thirdmenu(playerrecord);
            break;
        case 4:
            exit(0);
        default:// invalid value entered
            cout << "Invalid Option!" << endl;// error message displayed
        }


    }
}



int main()
{
     playerinfo playerrecord[MAX_RECORDS][SIZE];
    
    while (true) {
        mainmenu(playerrecord);\
    }
    return 0;
}