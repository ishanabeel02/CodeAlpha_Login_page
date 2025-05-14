#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <windows.h>
using namespace std;

void setColor(int color) 
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

class User 
{
private:
    string username, password;	
	//To set timer
    void timer() 
	{
        int seconds = 10;
        setColor(2);
        cout << "\n\n" << endl;
        for (int i = seconds; i >= 0; --i) 
		{
            cout << "\t\t\t\t\tTime remaining: 00:00:" << i << " seconds\r" << flush;
            Sleep(1000); // Sleep for 1000 milliseconds (1 second)  
        }
         cout << "\n\n\n";
        setColor(15);
    }
    //To add loading animation 
	void Loading() 
	{
		int barWidth = 40;
		setColor(4);
		cout << "\t\t\tLoading: [";
		for (int i = 0; i < barWidth; ++i) 
		{
		setColor(6);
		cout << "=" << flush;
		Sleep(5); 
		setColor(4);
		}
		cout << "]" << endl;
		setColor(15);
	}
	//To generate one time password 
    bool OTP() 
	{
        ofstream F;
        A:
        F.open("MyFile.txt", ios::trunc);
        if (!F) {
            cout << "Unable to open the file " << endl;
        }
        // Seed the random number generator
        srand(time(0));
        // Generate a random number between 1 - 999
        int Random = (rand() % 1000) + 1000;

        // OTP added to file
        F << Random;
        F.close();

        // Enter the OTP
        int OTP;
        cout << "Enter the one time password " << endl;
        cin >> OTP;

        if (Random == OTP) 
		{
            cout << "==========================================" << endl;
		    cout << "         <<< Login Successful!!!! >>>         " << endl;
		    cout << "==========================================" << endl;
		    return true;
    
        } 
		else 
		{
            cout << "==========================================" << endl;
		    cout << "              <<< \aInvalid >>>         " << endl;
		    cout << "==========================================" << endl;
            timer();
            int ans;
            cout << "Do you want to resend OTP?" << endl;
            cout << "==========================================" << endl;
		    cout << "\t1 = Yes" << endl;
		    cout << "\t2 = No" << endl;
		    cout << "==========================================" << endl;
            cin >> ans;
            if(ans == 1)
            {
            	goto A;	
			}
			else
			{
				return false;
				cout << "==================================================EXITING=========================================================" << endl;
			}
        }
    }
        bool isUsernameTaken(const string& user) 
		{
        ifstream file("info.txt");
        string u, p;
        while (file >> u >> p) 
		{
            if (u == user) 
			{
                return true;
            }
        }
        return false;
    }

    void suggestUsernames(const string& base) 
	{
        cout << "\n\tSuggested usernames:\n";

        string prefix = base.substr(0, min((int)base.length(), 6));

        for(int i = 1; i <= 3; ++i) 
		{
            stringstream ss;
			ss << prefix << (rand() % 1000 + 1);
			string suggestion = ss.str();

            // Make sure suggestion is not already taken
            if(!isUsernameTaken(suggestion)) 
			{
                cout << "\t- " << suggestion << endl;
            }
        }
    }
public:
    // Register new user
       void registerUser() {
        cout << "Enter desired username: ";
        cin >> username;

        while (isUsernameTaken(username)) 
		{
			setColor(12);
            cout << "\n\tERROR: Username already taken. Please choose a different one.\n";
			setColor(15);
            // Suggest alternative usernames
            suggestUsernames(username);

            cout << "\nEnter new username: ";
            cin >> username;
        }

        cout << "Enter password: ";
        cin >> password;

        ofstream out("info.txt", ios::app);
        out << username << " " << password << endl;
        out.close();
		setColor(10);
		cout << "==========================================\n";
        cout << "\tRegistration Successful!" << endl;
        cout << "==========================================\n";
        setColor(15);
    }

    // Login existing user
    bool loginUser() 
	{
        string us, pass, line;
        bool found = false;
        cout << "Enter username: ";
        cin >> us;
        cout << "Enter password: ";
        cin >> pass;

        ifstream file("info.txt");
        if (!file.is_open()) 
		{
            cout << "Error opening info.txt file!\n";
            return false;
        }

        while (getline(file, line)) 
		{
            istringstream i(line);
            i >> username >> password;
            if (username == us && password == pass) 
			{
                Loading();
                setColor(10);
                cout << "==========================================\n";
                cout << "     <<< Username and Password OK >>>     \n";
                cout << "==========================================\n";
                setColor(15);
                found = true;
                return OTP();
            }
        }

        if (!found) 
		{
            Loading();
            setColor(12);
            cout << "==========================================\n";
            cout << "   <<< Username or Password Incorrect >>> \n";
            cout << "==========================================\n";
            setColor(15);
        }

        file.close();
        return false;
    }
};
//Function To Clear the screen
void Clearscreen()
{
	system("cls");
}
int main() 
{
	 User user;


		cout << "\n\n\n\n\n\n\t-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-" << endl;
		cout << "\n\n\n";
        cout <<"\t\t\t\t   __      __        __\n";
		cout <<"\t\t\t\t  /  \\    /  \\ ____ |  | ____  ____    _____   ____ \n";										
		cout <<"\t\t\t\t  \\   \\/\\/   // __ \\|  |/ ___\\/  _ \\  /     \\ / __ \\\n";
		cout <<"\t\t\t\t   \\        /|  ___/|  |  \\__(  <_> )|  Y Y  | ___ /  \n";
		cout <<"\t\t\t\t    \\__/\\__/  \\____\\|__|\\_____>____/ |__|_|__|\\____\\\n";
		cout << "\n\n\n\n\t-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-" << endl;;
		
        
        Sleep(300); // Sleep 
        Clearscreen();
    int op;
    do 
	{
    	D:
        cout << "\n\t\t\t\tBANK - SYSTEM PORTAL" << endl;
        cout << "\t ///////////////////////////////////////////////////////////////////" << endl;
        cout << "\t |\tRegister Account   :------------------- |\tPress [1] |" << endl;
        cout << "\t |\tLogin to Account   :------------------- |\tPress [2] |" << endl;
        cout << "\t |\tExit Program       :------------------- |\tPress [3] |" << endl;
        cout << "\t |________________________________________________________________|" << endl;
        cout << "\n\tEnter your choice: ";
        cin >> op;

        switch (op) 
		{
            case 1:
                user.registerUser();
                Sleep(2000);  // wait 2 seconds
                system("cls"); // clear screen
                break;

            case 2:
                if (user.loginUser()) 
				{
                    cout << "\n\t\tAccess Granted to  login System!\n";
                    // You can call admin menu or user dashboard here
                } 
				else 
				{
                    cout << "\n\t\tAccess Denied. Please try again.\n";
                }
                Sleep(2500);
                system("cls");
                break;

            case 3:
                cout << "\n\t\tExiting the program... Thank you!\n";
                Sleep(2000);
                break;

            default:
                cout << "\n\t\tInvalid choice. Try again.\n";
                Sleep(2000);
                system("cls");
                goto D;
        }

    } while (op != 3);

        cout << "\t\t\t\tTTTTT  H   H  AAAAA  N   N  K   K    U   U" << endl;
	    cout << "\t\t\t\t  T    H   H  A   A  NN  N  K  K     U   U" << endl;
	    cout << "\t\t\t\t  T    HHHHH  AAAAA  N N N  K K      U   U" << endl;
	    cout << "\t\t\t\t  T    H   H  A   A  N  NN  KK       U   U" << endl;
	    cout << "\t\t\t\t  T    H   H  A   A  N   N  K  K     U   U" << endl;
	    cout << "\t\t\t\t  T    H   H  A   A  N   N  K   K    UUUUU" << endl;
        
    return 0;
}

