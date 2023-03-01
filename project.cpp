/*
############
(C) Copyright
Project Name : QuickNote
Language : C++
Submitted to : Ding Changqing
Author : Ayubali Emon
ID : 202001051911
Software Engineering 2020
Shandong University of Science and Technology
############
*/

#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#define MAX_NUM 100
using namespace std;

// Pre-defining global variables
string noteTitle[MAX_NUM];
string noteBody[MAX_NUM];
string noteTime[MAX_NUM];
string modifyTime[MAX_NUM];
static int noteCount = 0;

// Pre-defining essential functions
void mainIntro();
void mainMenu();
void makeNote(int n);
void noteList();
void showNote(int n);
void editNote(int n);
void saveNote(int n);
void deleteNote(int n);
void exitApp();
void close();
void Cursor(const int x, const int y);
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

// Main function
int main()
{
    mainMenu();
    return 0;
}
// Show main menu
void mainMenu() {
    close();        // clear console
    mainIntro();

    int tInt;
    cout << "\tPlease enter a number to select an option: \n";
    cout << "\t1. Create a new note\n";
    cout << "\t2. Show notes\n";
    cout << "\t3. Exit\n";
    cout << "\n\n\t\t\t\t--------------------------------------------\n";
    cout << "\t\t\t\tYou have currently " << noteCount << " notes in your notebook.\n";
    cout << "\t\t\t\t--------------------------------------------\n\n";
    cout << "\tEnter an option............";
    cin >> tInt;
    if(tInt==1) {
        noteCount++;
        makeNote(noteCount);
        }
    else if(tInt==2) {
        noteList();
        }
    else if(tInt==3) {
        exitApp();
        }
    else {
        mainMenu();
    }
}

// Calling this function shows intro in main menu
void mainIntro() {
    string welcome = "######## Welcome to QuickNote ########";
    Cursor(35,5);
    SetConsoleTextAttribute(hConsole, 1);
    for(int i=0;i<welcome.length();i++) {
        cout << welcome[i];
        Sleep(3);
    }
    cout << "\n";
    Cursor(35,6);
    for(int i=0;i<welcome.length();i++) {
        cout << "_";
        Sleep(3);
    }
    cout << "\n\n\n\n";
}

// Note creation page
void makeNote(int n) {
    close();    //clear console
    SetConsoleTextAttribute(hConsole, 6);

    time_t getTime;
    struct tm *ti;
    time(&getTime);
    ti = localtime(&getTime);
    noteTime[n] = asctime(ti);      // Saving current time
    modifyTime[n] = asctime(ti);

    cout << "\n\n\n\n\tMake a new note\n";
    cout << "\t-------------------\n";
    cout << "\tEnter title:\t";
    cin.ignore();
    getline(cin, noteTitle[n]);
    cout << "\n\tWrite your short note:\t";

    getline(cin, noteBody[n]);

    cout << "\n\n\t______________\n";
    cout << "\n\tNote saved!\n";
    cout << "\t______________\n";
    cout << "\n\n\t\t=> Navigation Menu:\n";
        cout << "\t\t1. " << "Main menu\n";
        cout << "\t\t2. " << "Create a new note\n";
        cout << "\t\t3. " << "Show notes list\n";
        cout << "\t\t4. " << "Exit\n";
        cout << "\n\n\tEnter your choose............";
        int tempInt;
        cin >> tempInt;
        if(tempInt==2) {
            noteCount++;
            makeNote(noteCount);
        }
        else if(tempInt==3) {
            noteList();
        }
        else if(tempInt==4) {
            exitApp();
        }
        else {
            mainMenu();
        }

}

// Notes listing page
void noteList() {
    close();    // clear console
    SetConsoleTextAttribute(hConsole, 10);

    string headerText = "######## My QuickNote ########";
    Cursor(35,5);
    for(int i=0;i<headerText.length();i++) {
        cout << headerText[i];
        Sleep(3);
    }
    cout << "\n";
    Cursor(35,6);
    for(int i=0;i<headerText.length();i++) {
        cout << "_";
        Sleep(3);
    }
    cout << "\n\n\n\n";
    //check if there is more than Zero notes
    if(noteCount==0) {
        cout << "\t\tSorry! Currently you don't have any notes -_- \n\n";

        cout << "\n\n\t\t=> Navigation Menu:\n";
        cout << "\t\t1. " << "Main menu\n";
        cout << "\t\t2. " << "Create a new note\n";
        cout << "\t\t3. " << "Exit\n";
        cout << "\n\n\tEnter your choose............";
        int tempInt;
        cin >> tempInt;
        if(tempInt==2) {
            noteCount++;
            makeNote(noteCount);
        }
        else if(tempInt==3) {
            exitApp();
        }
        else {
            mainMenu();
        }

    }
    //Zero checking condition end

    else {
        cout << "\t#ID - " << "\tTitle\t-\t" << "Last modified" << "\n\n";
        for(int i=1;i<=MAX_NUM;i++) {
            if(noteTitle[i].length()==0) {
                continue;
            }
            else {
                cout << "\t" << i << ". " << noteTitle[i] << "\t\t-\t" << modifyTime[i] << "\n";
            }
            }

        cout << "\n\n\tEnter note ID show your note............";
        int tempInt;
        cin >> tempInt;
        showNote(tempInt);
    }
}

// Note showing page
void showNote(int n) {
    close();    //Clear console
    SetConsoleTextAttribute(hConsole, 5);

    cout << "\n\n\n\n\n";
    if(noteTitle[n].length()==0) {
        cout << "\t\t##### Invalid note ID! #####" << "\n";
    }
    else {
        cout << "\t\tID#" << n << " " << noteTitle[n] << "\n";
    }

    cout << "\t\t" << "------------------------------------" << "\n\n";

    if(noteBody[n].length()==0) {
        cout << "\t\t" << "##### Note not found! #####" << "\n";
    }
    else {
        cout << "\t\t" << noteBody[n];
    }

    cout << "\n\n\t\t" << "------------------------------------" << "\n";

    cout << "\t\tCreated on: " << noteTime[n] << "\n\t\tLast modified on: " << modifyTime[n] << "\n\n\n";

    cout << "\n\n\t\t=> Navigation Menu:\n";
    cout << "\t\t1. " << "Save this note as txt file\n";
    cout << "\t\t2. " << "Edit note\n";
    cout << "\t\t3. " << "Delete note\n";
    cout << "\t\t4. " << "Notes list\n";
    cout << "\t\t0. " << "Main menu\n";
    cout << "\n\n\tEnter your choose............";
    int tempInt;
    cin >> tempInt;
    if(tempInt==4) {
        noteList();
    }
    else if(tempInt==3) {
        deleteNote(n);
    }
    else if(tempInt==2) {
        editNote(n);
    }
    else if(tempInt==1) {
        saveNote(n);
    }
    else {
        mainMenu();
    }

}

// Edit note page
void editNote(int n) {
    close();
    SetConsoleTextAttribute(hConsole, 6);

    if(noteTitle[n].length() != 0) {
        time_t getTime;
        struct tm *ti;
        time(&getTime);
        ti = localtime(&getTime);
        modifyTime[n] = asctime(ti);
    }

    cout << "\n\n\n";
    if(noteTitle[n].length()==0) {
        cout << "\t\t##### Invalid note ID! #####" << "\n";
    }
    else {
        cout << "\t\tID#" << n << " " << noteTitle[n] << "\n";
    }

    cout << "\t\t" << "------------------------------------" << "\n\n";

    if(noteBody[n].length()==0) {
        cout << "\t\t" << "##### Note not found! #####" << "\n";
    }
    else {
        cout << "\t\t" << noteBody[n];
    }

    cout << "\n\n\t\t" << "------------------------------------" << "\n\n";

    if(noteBody[n].length()==0) {
        cout << "\t\tSorry! Unable to edit an empty note -_-\n";

        cout << "\n\n\t\t=> Navigation Menu:\n";
        cout << "\t\t1. " << "Notes list\n";
        cout << "\t\t2. " << "Main menu\n";
        cout << "\n\n\tEnter your choose............";
        int tempInt;
        cin >> tempInt;
        if(tempInt==1) {
            noteList();
        }
        else {
            mainMenu();
        }
    }
    else {
        cout << "\t\tWrite new note: ";
        cin.ignore();
        getline(cin, noteBody[n]);
        cout << "\n\n\t\tNote edited successfully!\n";
        cout << "\t\tNew note:\n\t\t" << noteBody[n];

        cout << "\n\n\t\t" << "------------------------------------" << "\n";

        cout << "\n\n\t\t=> Navigation Menu:\n";
        cout << "\t\t1. " << "Edit again\n";
        cout << "\t\t2. " << "Delete note\n";
        cout << "\t\t3. " << "Notes list\n";
        cout << "\t\t0. " << "Main menu\n";
        cout << "\n\n\tEnter your choose............";
        int tempInt;
        cin >> tempInt;
        if(tempInt==3) {
            noteList();
        }
        else if(tempInt==2) {
            deleteNote(n);
        }
        else if(tempInt==1) {
            editNote(n);
        }
        else {
            mainMenu();
        }
    }
}

//Note save-as-file page
void saveNote(int n) {
    close();    // Clear console
    SetConsoleTextAttribute(hConsole, 3);

    if(noteTitle[n].length()==0) {
        cout << "\n\n\n\t\tSorry nothing to save!\n";
        cout << "\t\tIvalid note ID or note is empty!";

        cout << "\n\n\t\t=> Navigation Menu:\n";
        cout << "\t\t1. " << "Main menu\n";
        cout << "\t\t2. " << "Notes list\n";
        cout << "\n\n\tEnter your choose............";
        int tempInt;
        cin >> tempInt;
        if(tempInt==2) {
            noteList();
            }
        else {
            mainMenu();
            }
    }
    else {
        ofstream noteFile(noteTitle[n] + ".txt");

        noteFile << "ID#" << n << " " << noteTitle[n];
        noteFile << "\n------------------------------------\n\n";
        noteFile << noteBody[n];
        noteFile << "\n\n------------------------------------\n\n";
        noteFile << "Created on: " << noteTime[n] << "\nLast modified on: " << modifyTime[n];

        noteFile.close();

        cout << "\n\n\n\n\t\tSaving note as file";
        for(int i=0;i<=6;i++) {
            cout << ".";
            Sleep(400);
        }

        cout << "\n\n\t\tFile saved sucessfully!\n";
        cout << "\n\t\tNote #" << n << " has been saved as \"" << noteTitle[n] << ".txt\" in your current folder.";

        cout << "\n\n\t\t=> Navigation Menu:\n";
        cout << "\t\t1. " << "Main menu\n";
        cout << "\t\t2. " << "Notes list\n";
        cout << "\n\n\tEnter your choose............";
        int tempInt;
        cin >> tempInt;
        if(tempInt==2) {
            noteList();
            }
        else {
            mainMenu();
            }
        }
}

//Calling this function to delete a note
void deleteNote(int n) {
    close();
    SetConsoleTextAttribute(hConsole, 4);

    if(noteTitle[n].length()==0) {
        cout << "\n\n\n\n\n\t\tSorry! Invalid note Id/note is empty.\n" << "\t\tCan't do delete\n";
        cout << "\n\n\t\t=> Navigation Menu:\n";
        cout << "\t\t1. " << "Main menu\n";
        cout << "\t\t2. " << "Notes list\n";
        cout << "\n\n\tEnter your choose............";
        int tempInt;
        cin >> tempInt;
        if(tempInt==2) {
            noteList();
        }
        else {
            mainMenu();
        }
    }
    else {
        noteCount--;
        noteTime[n].erase();
        modifyTime[n].erase();
        noteTitle[n].erase();
        noteBody[n].erase();

        cout << "\n\n\n\n\n\t\tDeleting note";
        for(int i=0;i<=6;i++) {
            cout << ".";
            Sleep(100);
        }
        cout << "\n\n\t\tNote deleted successfully!\n";
        cout << "\n\n\t\t=> Navigation Menu:\n";
        cout << "\t\t1. " << "Main menu\n";
        cout << "\t\t2. " << "Notes list\n";
        cout << "\n\n\tEnter your choose............";
        int tempInt;
        cin >> tempInt;
        if(tempInt==2) {
            noteList();
        }
        else {
            mainMenu();
        }
    }
}

// Call this function to clear the console
void close() {
    #if defined(_WIN32)
        system("CLS");
    #else
        system("clear");
    #endif
}

// Calling this function help to align the text in different position of console
void Cursor(const int x, const int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD PlaceCursorHere;
    PlaceCursorHere.X = x;
    PlaceCursorHere.Y = y;

    SetConsoleCursorPosition(hConsole, PlaceCursorHere);
    return;
    }

// Calling this function will terminate the process
void exitApp() {
    close();
    SetConsoleTextAttribute(hConsole, 4);
    Cursor(35,4);

    string headerText = "Thank you for trying out my little project ^-^";
    Cursor(35,5);
    cout << headerText;
    cout << "\n";
    Cursor(35,6);
    cout << string(headerText.length(), '_');
    Cursor(25,8);
    cout << "(C) QuickNote project by Ayubali Emon, SDUST-2020, ID- 202001051911\n";
    Cursor(25,9);
    cout << "\tSubmitted to: Ding Changqing, Software Engineering Dept.";
    cout << "\n\n\n\n";
    cout << "\t\tExiting........\n";
    for(int i=1;i<=10;i++) {
        cout << "\t\tx\n";
        Sleep(200);
    }
    exit(0);
}
