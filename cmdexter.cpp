// cmdexter main

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void dexExit() {
    exit;
}

void waitForKey() {
    cout << "Press any key to continue...";
    cin.get();
    cin.get();
}

void waitForKey_Silent() {
    //cout << endl << "Press any key to continue...";
    cin.get();
    cin.get();
}

void dexShell() {
    cout << endl << endl << "-----[dexShell Console ";
    string line;
    ifstream myfile("MAINDATA/ShellVersion.dex");
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            cout << line;
        }
        myfile.close();
        cout << "]-----";
    }
    else cout << endl << "[Error!] Unable to detect shell version. (File 'ShellVersion.dex' is missing.)";

    cout << endl << ">> ";
    string shellIn;
    cin >> shellIn;

    if (shellIn == "dex.exit(0)") {
        cout << endl << "[i] Shell exited with reason code 0." << endl;
        waitForKey();
        cout << endl << endl << "You may now close the program safely.";
        dexExit();
        exit;
        while (1 != 0) {
            exit;
        }
    }

    else if (shellIn == "dex.exit(2)") {
        cout << endl << "[i] Shell exited with reason code 2." << endl;
        waitForKey();
        dexExit();
    }

    else if (shellIn == "dex.exit(1)") {
        cout << endl << "[i] Shell restarted with reason code 1." << endl;
        waitForKey();
        dexShell();
    }

    else if (shellIn == "dex.exit()") {
        cout << endl << "[ERROR!] No exit reason code provided." << endl << "[i] Type 'dex.exit(help)' to learn how to properly terminate your session." << endl;
        waitForKey();
        dexShell();
    }

    else if (shellIn == "dex.exit(help)") {
        cout << endl << endl;
        string line;
        ifstream myfile("MAINDATA/exit_HelpFile.dex");
        if (myfile.is_open())
        {
            while (getline(myfile, line))
            {
                cout << line << "\n";
            }
            myfile.close();
        }
        else
        {
            cout << endl << "[Error!] Unable to load help file. (File 'exit_HelpFile.dex' is missing.)";
        }
        cout << endl;
        waitForKey();
        dexShell();
    }

    else if (shellIn == "dex.help()") {
        string line;
        ifstream myfile("MAINDATA/HelpFile.dex");
        if (myfile.is_open())
        {
            while (getline(myfile, line))
            {
                cout << line << "\n";
            }
            myfile.close();
        }
        else
        {
            cout << endl << "[Error!] Unable to load help file. (File 'HelpFile.dex' is missing.)";
        }
        cout << endl;
        waitForKey();
        dexShell();
    }

    else if (shellIn == "dex.sdk()") {
        string line;
        ifstream myfile("MAINDATA/SDK.dex");
        if (myfile.is_open())
        {
            while (getline(myfile, line))
            {
                cout << line << '\n';
            }
            myfile.close();
        }
        else cout << endl << "[Error!] No SDK install present. (File 'sdk.dex' is missing.)";
        cout << endl;
        waitForKey();
        dexShell();
    }

    else if (shellIn == "dex.install(start)") {
        cout << endl << "To install a new package, place the 'install.pkdex' file in the main CMDEXTER directory." << endl;
        waitForKey();
        cout << endl;

        char oldname[] = "install.pkdex";
        char newname[] = "install.exe";

        /*	Deletes the file if exists */
        if (rename(oldname, newname) != 0) {
            perror("[Error!] Could not import package");
            cout << endl;
            dexShell();
        }
        else {
            cout << endl << "Package imported successfully." << endl;
        }

        cout << endl;
        system("install.exe");
        cout << endl;
        cout << endl << "Installer has exited." << endl;

        char e_oldname[] = "install.exe";
        char e_newname[] = "install.pkdex";

        /*	Deletes the file if exists */
        if (rename(e_oldname, e_newname) != 0) {
            perror("[Error!] Could not export package");
            cout << endl;
            dexShell();
        }
        else {
            cout << endl << "Package exported successfully." << endl;
        }

        dexShell();
    }

    else if (shellIn == "dex.install(exe2dex)") {
    cout << endl << "Windows Executable (EXE) will be converted to a CMDEXTER Package File (PKDEX)" << endl;
    cout << endl << "Place the 'install.exe' file in the main CMDEXTER directory." << endl;
    waitForKey();
    cout << endl;

    char oldname[] = "install.exe";
    char newname[] = "install.pkdex";

    /*	Deletes the file if exists */
    if (rename(oldname, newname) != 0) {
        perror("[Error!] Could not convert package");
        cout << endl;
        dexShell();
    }
    else {
        cout << endl << "Package converted successfully." << endl;
    }
    dexShell();
    }

    else
    {
        cout << endl << "[Error!] Unrecognised parameter: " << shellIn << endl;
        dexShell();
    }
}


void dexSys() {
    cout << "CMDEXTER" << endl;

    cout << "Current version: ";
    string line;
    ifstream myfile("MAINDATA/CurrentVersion.dex");
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            cout << line << '\n';
        }
        myfile.close();
    }
    else cout << endl << "[Error!] Unable to detect software version. (File 'CurrentVersion.dex' is missing.)";

    cout << endl;
    cout << "Starting shell..." << endl << endl;
    dexShell();
}




int main()
{
    dexSys();
}
