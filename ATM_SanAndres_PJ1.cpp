#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
struct ATM{


	string AccNum;
	string Pin;
	string LastName;
	string FirstName;
	string MiddleInitials;
	double Balance;
	string ContactNumber;
	int WithDrawLimit; // Withdraw Limit You Can Only Withdraw 5 times a month
};
ATM Accounts[50];// sttucture array;
void Menu(string UserName, double &Balance, int &WithDrawLimit,string ContactNumber,string AccN); //Menu for Choosing Transaction
void Withdraw(string UserName,double &Balance,int &WithDrawLimit,string ContactNumber,string AccN); // Withdraw
void Deposit(string UserName,double &Balance,int &WithDrawLimit,string ContactNumber,string AccN); // Deposit
void Inquiry (string UserName,double &Balance,int &WithDrawLimit,string ContactNumber,string AccN); // Inquiry
void FundTransfer(string UserName,double &Balance,int &WithDrawLimit,string ContactNumber,string AccN); // Fund Transfer
void Load(string UserName,double &Balance,int &WithDrawLimit,string ContactNumber,string AccN); // Load
void ChangePin(string UserName,double &Balance,int &WithDrawLimit,string ContactNumber,string AccN); // Change Pim

int IteratorForAcc = 0,CurrentUser,IteratorForAccOut=0; // Global Variables:
//IteratorForAcc - the total count of data in the file PJ1.out
// CurrentUser - The Index of The Current Accout That is Logged In
int main()
{
	int tries,PinRetries;
	string EntryAccNum;
	string EntryPin;
	string UserName;
	bool CheckerAccNum;
	bool CheckerPin;
    string CurrentUserContactNumber;
    int CurrentUserWithDrawLimit;


	ifstream DataIn;
	DataIn.open("PJ1.out");
	if(DataIn.fail())
	cerr << "Error Loading Accounts"; // Checks if The File is Right

	while(!DataIn.eof()) // while the computer is not finished to read all the data in the file
	      {
		DataIn >> Accounts[IteratorForAcc].AccNum; //Account NUmber;
		DataIn >> Accounts[IteratorForAcc].Pin;    // Pin
		getline(DataIn >> ws,Accounts[IteratorForAcc].LastName); // Last Name
		getline(DataIn >> ws,Accounts[IteratorForAcc].FirstName); // First Name
		getline(DataIn >> ws,Accounts[IteratorForAcc].MiddleInitials); // Calampiano
		DataIn >> Accounts[IteratorForAcc].Balance;  //Balance
		DataIn >> Accounts[IteratorForAcc].ContactNumber; // ContactNumber
		DataIn >> Accounts[IteratorForAcc].WithDrawLimit; // WithDrawLimit
		IteratorForAcc++;
		}
		DataIn.close();
        cout << endl;
        cout <<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
		cout <<"$$$$$$$$$$$$$$$$$$$________$$$$$$$__________________$$________$$$________$$$$$$$$$$$$$$$$$$$___$$$$$$$$$$$$$$$$$$$$$$$$\n";
		cout <<"$$$$$$$$$$$$$$$$___$$$$$$$$___$$$$$$$$$$$$___$$$$$$$$$$$______$$$_______$$$$$$$$$$$$$$$$$$$@___$$$$$$$$$$$$$$$$$$$$$$$$\n";
        cout <<"$$$$$$$$$$$$$$$___$$$$$$$$___$$$$$$$$$$$$___$$$$$$$$$$$___$___$$___$___$$$$$$$$$$$___$$_____________$$$$$$$$$$$$$$$$$$$\n";
		cout <<"$$$$$$$$$$$$$$___$$$$$$$$___$$$$$$$$$$$$___$$$$$$$$$$$___$$___$___$___$$$$$$$$$$$$___$$$$$$$___$$$$$$$$$$$$$$$$$$$$$$$$\n";
		cout <<"$$$$$$$$$$$$$______________$$$$$$$$$$$$___$$$$$$$$$$$___$$$______$___$$$$$$$$_____________$$___$$$$$$$$$$$$$$$$$$$$$$$$\n";
		cout <<"$$$$$$$$$$$$___$$$$$$$$___$$$$$$$$$$$$___$$$$$$$$$$$___$$$$$$$$$$___$$$$$$$$$$$$$$___$$$$$$$___$$$$$$$$$$$$$$$$$$$$$$$$\n";
		cout <<"$$$$$$$$$$$___$$$$$$$$___$$$$$$$$$$$$___$$$$$$$$$$$___$$$$$$$$$$___$$$$$$$$$$$$$$$___$$$$$$$$$$$$$$$     WAYS     $$$$$\n";
		cout <<"$$$$$$$$$$___$$$$$$$$___$$$$$$$$$$$$___$$$$$$$$$$$___$$$$$$$$$$___$$$$$$$$$$$$$$$$___$$$$$$$$$$$$$$$    FIND US   $$$$$\n";
		cout <<"$$$$$$$$$___$$$$$$$$___$$$$$$$$$$$$___$$$$$$$$$$$___$$$$$$$$$$___$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
		cout << endl;
		cout << endl;
		cout << " ==================================\n";
		cout << endl;
		cout << "          WELCOME TO ATM++          \n";
		cout << endl;
		cout << " ==================================\n";
		cout << endl;
		cout << " **********************************\n";
		cout << endl;
		cout << "           WAYS FINDS US             \n";
		cout << endl;
		cout << " **********************************\n";
        cout << endl;

		for(int tries = 3; tries > 0; tries--) // Three Attempts for Account Number Login
		    {
            cout << " ==============================================================\n";
            cout << endl;
            cout << " Enter Your Account Number:           ";
			cout << " Remaining Attempt(s): " << tries << endl;
			cout << endl;
			cout << " ==============================================================\n";
			cout << endl;
			cout << "           -> ";
			cin >> EntryAccNum;
			cout << endl;
			for(int FindAccNum = 0; FindAccNum < IteratorForAcc; FindAccNum++) // For Loop to match the Account Number in The List
			  {
				if(EntryAccNum == Accounts[FindAccNum].AccNum) // Checks if The Account Number is the same in the List
				  {
                    CurrentUser = FindAccNum; // if it matches then CurrentUser is equal to the index of the Pin which Corresponds to the data in the list
					CheckerAccNum = true; // If the computer finds the acc then it will become true;
					break; // break because the computer already found the account
					}
					else
                    {
					CheckerAccNum = false; // if the computer fails to find the acc
					}
                    }
					if(CheckerAccNum == true) // if true
				          {
						break; // the loop will break because the acc has been found
					  }
                    cout <<" ***************************************************\n";
                    cout << endl;
					cout << " Sorry We Did Not Find Your Account Please Try Again\n";
					cout << endl;
					cout << " ***************************************************\n";
					cout << endl;
					}

				if(CheckerAccNum == false) // if the user attempted to many tries
				{
                cout << " ***********************\n";
                cout << endl;
				cout << " Program Now Exiting....\n";
				cout << endl;
				cout << " ***********************\n";
				cout << endl;
				return 0;
				}
			if(CheckerAccNum == true) // if The computer found the acc then it will proceed to enter the pin
			  {

				for(int PinRetries = 3; PinRetries > 0; PinRetries--) // 3 attempts
				    {
                    cout << " ==============================================================\n";
                    cout << endl;
			     	cout << " Please Enter Your 6 Digit Pin:        Remaining Attempt(s): "<< PinRetries << endl;
			     	cout << endl;
			    	cout << " ==============================================================\n";
			    	cout << endl;
                    cout << "           -> ";
                    cin >> EntryPin;
                    cout <<endl;
					//for(int FindPin = 0; FindPin < IteratorForAcc; FindPin++) // for loop to find the pin in the list
						if(EntryPin == Accounts[CurrentUser].Pin) //checks the pin if  it matches the data
						   {
							CheckerPin = true;
							break; // break the loop
							}

                            else{
                            cout << "******************************\n";
                            cout << endl;
							cout << "      Sorry Wrong Pin\n";
							cout << endl;
							cout << "******************************\n";
							cout << endl;
							CheckerPin = false;
							}
                        }
							}
			if(CheckerPin == false) // if the user attempted to many tries the program will terminate
			   {
                cout << " **********************************************\n";
                cout << endl;
				cout << " Too many Attempts! Program Now Exiting......\n";
				cout << endl;
				cout << " **********************************************\n";
				cout << endl;
				return 0;
				}

			if((CheckerPin == true) && (CheckerAccNum == true)) //  checks if the pin and the account matches
			{
			UserName+= Accounts[CurrentUser].LastName + " " + Accounts[CurrentUser].FirstName + " " +Accounts[CurrentUser].MiddleInitials;// Cpncatonate The LastName:FirstName and The M.I of the CurrentUser


			Menu(UserName,Accounts[CurrentUser].Balance,Accounts[CurrentUser].WithDrawLimit,Accounts[CurrentUser].ContactNumber,Accounts[CurrentUser].AccNum);
            //I've put the data of the current user to function Menu for Selection of Transaction in the Program
            // I used ampersand to the Balance and WithDrawLimit because the value can be manipulated by the following transactions
}
}
void Menu(string UserName, double &Balance, int &WithDrawLimit,string ContactNumber,string AccN)
{
	int ChoiceForMenu;
            cout << endl;
            cout << " ============================================\n";
            cout << endl;
            cout << "      Account Number: #" << AccN <<endl;
            cout << endl;
			cout << "      Welcome User: "  << UserName << endl;
			cout << endl;
			cout << "      Current Balance: " << Balance << " PHP" << endl;
			cout << endl;
			cout << " ============================================\n";
			cout << endl;
			cout << "      Menu:\n";
			cout << "      [ 1 ] Withdraw\n";
			cout << endl;
            cout << "      [ 2 ] Deposit\n";
            cout << endl;
            cout << "      [ 3 ] Inquiry\n";
            cout << endl;
			cout << "      [ 4 ] Fund Transfer\n";
			cout << endl;
			cout << "      [ 5 ] Load\n";
			cout << endl;
			cout << "      [ 6 ] Change Pin\n";
			cout << endl;
			cout << "      [ 7 ] Exit\n";
            cout << endl;

                cout << "============================================================\n";
                cout << endl;
				cout << "      Hello, There! " << UserName << "\n      \n      What Do you want to do today?\n";
				cout << endl;
				cout << "============================================================\n";
				cout << endl;
				cout << "           -> ";
				cin >> ChoiceForMenu;
				cout <<endl;
				if(ChoiceForMenu == 1)
				  {
					Withdraw(UserName,Balance,WithDrawLimit,ContactNumber,AccN);
					}
				else if(ChoiceForMenu == 2)
				{
                    Deposit(UserName,Balance,WithDrawLimit,ContactNumber,AccN);
				}
				else if( ChoiceForMenu == 3)
                {
                    Inquiry(UserName,Balance,WithDrawLimit,ContactNumber,AccN);

                }
                else if(ChoiceForMenu == 4)
                {
                    FundTransfer(UserName,Balance,WithDrawLimit,ContactNumber,AccN);
                }
                else if(ChoiceForMenu == 5)
                {
                    Load(UserName,Balance,WithDrawLimit,ContactNumber,AccN);
                }
                else if(ChoiceForMenu == 6)
                {
                    ChangePin(UserName,Balance,WithDrawLimit,ContactNumber,AccN);
                }
                else if( ChoiceForMenu == 7)
                {   cout << " ===================================\n";
                    cout << endl;
                    cout << "      Thank You For Banking With Us " << UserName << endl;
                    cout << endl;
                    cout << " ===================================\n";
                    cout << endl;

                    ofstream DataOut;
                    DataOut.open("PJ1.out");

                    while(IteratorForAccOut < IteratorForAcc-1)
                    {
                        DataOut << Accounts[IteratorForAccOut].AccNum << endl;//Account NUmber;
                        DataOut << Accounts[IteratorForAccOut].Pin << endl;    // Pin
                        DataOut << Accounts[IteratorForAccOut].LastName << endl; // Last Name
                        DataOut << Accounts[IteratorForAccOut].FirstName << endl;// First Name
                        DataOut << Accounts[IteratorForAccOut].MiddleInitials << endl; // Calampiano
                        DataOut << Accounts[IteratorForAccOut].Balance << endl;//Balance
                        DataOut << Accounts[IteratorForAccOut].ContactNumber << endl;// ContactNumber
                        DataOut << Accounts[IteratorForAccOut].WithDrawLimit << endl;// WithDrawLimit
                       IteratorForAccOut++;
                    }
                    DataOut.close();
                }
                else
                {
                    cout << "***********************************\n";
                    cout << endl;
                    cout << "        Invalid Choice! \n";
                    cout << endl;
                    cout << "************************************\n";
                    Menu(UserName,Balance,WithDrawLimit,ContactNumber,AccN);

                }


}
void Withdraw(string UserName,double &Balance,int &WithDrawLimit,string ContactNumber,string AccN)
{
	int AmountTobeWithdrawed;
	bool Transaction;
	int ConfirmWithdraw;
	if(WithDrawLimit > 5)
    {
    cout << " ========================================================\n";
	cout << endl;
    cout << "      Sorry You Have Exceeded The Withdrawal Limit:\n";
    cout << endl;
    cout << " ========================================================\n";
    cout << endl;
     Menu(UserName,Balance,WithDrawLimit,ContactNumber,AccN);

    }
	cout << " ==========================================\n";
	cout << endl;
    cout << "      You Have Selected Withdraw:\n";
    cout << endl;
    cout << " ==========================================\n";
    cout << endl;
	for (int w = 3; w > 0; w--)
	{
    cout << " ===================================================================================\n";
    cout << endl;
    cout << "      Enter Amount To Be Withdrawed:";
	cout << "      Remaining Attemp(s) " << w << endl;
	cout << endl;
	cout << "      Press 1 to Exit:\n";
	cout << endl;
	cout << " ====================================================================================\n";
	cout << endl;
	cout << "           -> ";
	cin >>  AmountTobeWithdrawed;
	cout <<endl;
	if(AmountTobeWithdrawed == 1)
    {
        Transaction = false;
        break;
    }
    else if ( AmountTobeWithdrawed >= 200 &&  AmountTobeWithdrawed <= Balance)
    {
    cout << "===========================================\n";
    cout << endl;
	cout << "      Withdraw? " << AmountTobeWithdrawed << endl;
	cout << endl;
    cout << "      Press 1. To Confirm" << endl;
    cout << endl;
    cout << "      Press 2. To Cancel\n ";
	cout << endl;
	cout << "============================================\n";
	cout << "           -> ";
	cin >> ConfirmWithdraw;
	cout << endl;

	if(ConfirmWithdraw == 1)
    {
                Balance =  Balance - AmountTobeWithdrawed;
        cout << "==============================================================================\n";
        cout << endl;
        cout << "      You've Succefully Withdrawed: " << AmountTobeWithdrawed << " Pesos      \n";
        cout << endl;
        cout << "      Your Current Balance is " << Balance << endl;
        cout << endl;
        cout << "==============================================================================\n";
        WithDrawLimit+=WithDrawLimit+1;
        Transaction = true;
    }


            else if(ConfirmWithdraw == 2)
            {
            Transaction == false;
            break;
            }
    }
        else if( AmountTobeWithdrawed > Balance)
        {
        cout << "===================================================================================\n";
        cout << endl;
        cout << "      Sorry Your Balance Is Not Enough For The Amount Your Trying To Withdraw!      \n";
        cout << endl;
        cout << "===================================================================================\n";
        cout << endl;
        }
        else if( 2 <= AmountTobeWithdrawed && AmountTobeWithdrawed <= 200)
        {
        cout << "===========================================================\n";
        cout << endl;
        cout << "      Sorry You Must At Least Withdraw 200 PHP      \n";
        cout << endl;
        cout << "===========================================================\n";
        cout << endl;
        }
         else
        {

            cout << "***********************************\n";
            cout << endl;
            cout << "        Invalid Input! \n";
            cout << endl;
            cout << "************************************\n";
            cout << endl;

        }
    if(Transaction == true)
    {
        break;
    }
	}


	if( Transaction == true)
    {
         Menu(UserName,Balance,WithDrawLimit,ContactNumber,AccN);
    }
    else if( Transaction == false)
    {
        cout <<" ***************************\n";
        cout << endl;
        cout <<"      Exiting........\n";
        cout << endl;
        cout <<" ***************************\n";
        Menu(UserName,Balance,WithDrawLimit,ContactNumber,AccN);
    }
}

void Deposit(string UserName,double &Balance,int &WithDrawLimit,string ContactNumber,string AccN)
{
    bool DepTransaction;
	int AmountToBeDeposited,ChoiceForDeposit;

	cout << "===================================\n";
	cout << endl;
	cout << "     You Have Selected Deposit\n";
	cout << endl;
	cout << "===================================\n";
	cout << endl;
	for(int Dep = 3; Dep > 0; Dep--)
	    {
        cout << " =========================================================================\n";
        cout << endl;
        cout << "      Enter Amount To Be Deposited:      " << " Remaining Attempt(s): " << Dep <<  endl;
        cout << endl;
        cout << "      Press to 1 exit\n";
        cout << endl;
        cout << " =========================================================================\n";
        cout << endl;
        cout << "           -> ";
		cin >> AmountToBeDeposited;
		cout << endl;
		if(200 <= AmountToBeDeposited && AmountToBeDeposited <= 50000)
            {
        cout << "===========================================\n";
        cout << endl;
        cout << "      Deposit? " << AmountToBeDeposited << endl;
        cout << endl;
        cout << "      Press 1. To Confirm" << endl;
        cout << endl;
        cout << "      Press 2. To Cancel\n ";
        cout << endl;
        cout << "============================================\n";
        cout << "           -> ";
        cin >> ChoiceForDeposit;
        if( ChoiceForDeposit == 1)
        {
            Balance+=AmountToBeDeposited;
            cout << " ================================================\n";
            cout << endl;
			cout << "            You've Succefully Deposited:      " << AmountToBeDeposited <<endl;
			cout << endl;
			cout << "            Current Balance:      "<< Balance <<endl;
			cout << endl;
            cout << " =================================================\n";
            cout << endl;
			DepTransaction = true;
            break;
			}
			else if( ChoiceForDeposit == 2)
            {
                DepTransaction = false;
                break;
            }
	          }
            else if( 2 < AmountToBeDeposited && AmountToBeDeposited < 200)
            {
                cout << " **********************************************\n";
                cout << endl;
                cout << "      You need at least 200 PHP To Deposit      \n";
                cout << endl;
                cout << " **********************************************\n";
                cout << endl;
            }
            else if( AmountToBeDeposited == 1)
            {
                DepTransaction = false;
                break;
            }
            else if(DepTransaction == true )
            {
                break;
            }
            else if (DepTransaction == false)
            {
                break;
            }
            else if( AmountToBeDeposited > 50000)
            {
                cout << " **********************************************\n";
                cout << endl;
                cout << "      Sorry, The Maximum Deposit Is 50000 PHP      \n";
                cout << endl;
                cout << " **********************************************\n";
                cout << endl;
            }
			else
            {
                    cout << "***********************************\n";
                    cout << endl;
                    cout << "        Invalid Input! \n";
                    cout << endl;
                    cout << "************************************\n";
                    cout <<endl;

			}
            }

            if(DepTransaction == true)
            {

                Menu(UserName,Balance,WithDrawLimit,ContactNumber,AccN);

            }
            else if ( DepTransaction == false)
            {
            cout << "************************\n";
            cout << endl;
            cout << "      Exiting.....      \n";
            cout << endl;
            cout << "************************\n";
            cout << endl;
          Menu(UserName,Balance,WithDrawLimit,ContactNumber,AccN);
            }
}
void Inquiry(string UserName,double &Balance,int &WithDrawLimit,string ContactNumber,string AccN)
{
    string c;
    cout << " ==================================\n";
    cout << endl;
    cout << "      You Have Seleced Inquiry     \n";
    cout << endl;
    cout << " ==================================\n";
    cout << endl;

    cout << " ============================================================\n";
    cout <<endl;
    cout << "      Account Information:\n";
    cout << endl;
    cout << "      Account Number: #" << AccN <<endl;
    cout << endl;
    cout << "      Name:" << UserName << endl;
    cout << endl;
    cout << "      Contact Number: " << ContactNumber << endl;
    cout << endl;
    cout << "      Current Balance: " << Balance <<endl;
    cout << endl;
    cout << "      Withdrawal Limit For This Month " << WithDrawLimit << endl;
    cout << endl;
    cout << "=============================================================\n";
    cout <<endl;

    cout <<" ===================================\n";
    cout << endl;
    cout <<"      Press any key to Continue:      \n";
    cout << endl;
    cout <<" ===================================\n";
    cout << "           -> ";
    cin >> c;
    Menu(UserName,Balance,WithDrawLimit,ContactNumber,AccN);

}
void FundTransfer(string UserName,double &Balance,int &WithDrawLimit,string ContactNumber,string AccN)
{
    string AccountNumberOfTheReceiver;
    int AmountToBeTransferred,CurrentAccForTransfer,ChoiceForTransfer,LengthOfTheAccNum;
    bool CheckerTransfer;
    bool CheckAccountNum;
    cout << " ========================================\n";
    cout << endl;
    cout << "      You Have Seleced Fund Transfer     \n";
    cout << endl;
    cout << " ========================================\n";
    cout << endl;
    for (int FundTries = 3; FundTries > 0; FundTries--)
    {
    cout << " ===============================================================================================\n";
    cout << endl;
    cout << "      Enter The Account Nummber You Want Transfer Fund With";
    cout << "      Remaining Attempt(s): " << FundTries << endl;
    cout << "      Press 1 To Exit\n";
    cout << endl;
    cout << " ===============================================================================================\n";
    cout << "           -> ";
    cin >> AccountNumberOfTheReceiver;
    cout << endl;
    LengthOfTheAccNum = AccountNumberOfTheReceiver.length();
    if(AccountNumberOfTheReceiver == "1")
    {
        CheckAccountNum = false;
        break;

    }
    else if(LengthOfTheAccNum != 12)
    {

    cout <<" ===================================\n";
    cout << endl;
    cout <<"      Invalid Account Number!     \n";
    cout << endl;
    cout <<" ===================================\n";
    }
    else if(AccountNumberOfTheReceiver == Accounts[CurrentUser].AccNum)
    {
            cout << "******************************************************\n";
            cout << endl;
            cout << "      You Can't Transer Fund To Your Own Account!      \n";
            cout << endl;
            cout << "******************************************************\n";
            cout << endl;

            break;
            CheckAccountNum = false;

    }
    else if (LengthOfTheAccNum == 12 )
    {
    for(int FindAcc = 0; FindAcc < IteratorForAcc; FindAcc++)
    {
        if(AccountNumberOfTheReceiver == Accounts[FindAcc].AccNum)
        {
            CurrentAccForTransfer = FindAcc;
            CheckAccountNum = true;
            break;
        }
        else
            CheckAccountNum = false;
    }
    if(CheckAccountNum == true )
    {
        cout << " ============================================\n";
        cout << "Do You Want To Transfer Fund With?\n";
        cout << endl;
        cout << " Account Number: #" << Accounts[CurrentAccForTransfer].AccNum << endl;
        cout << endl;
        cout << " Name: " << Accounts[CurrentAccForTransfer].LastName << " " << Accounts[CurrentAccForTransfer].FirstName << " " << Accounts[CurrentAccForTransfer].MiddleInitials;
        cout << endl;
        cout << " [ 1 ] YES \n [ 2 ] NO\n";
        cout << endl;
        cout << " ============================================\n";
        cout << endl;
        cout << "           -> ";
        cin >> ChoiceForTransfer;
        if(ChoiceForTransfer == 1)
        {
            cout << " ===============================================\n";
            cout << endl;
            cout << "      Enter The Amount To Be Transferred:\n";
            cout << endl;
            cout << " ===============================================\n";
            cout << "           -> ";
            cin >> AmountToBeTransferred;
            if(AmountToBeTransferred <= Balance)
            {
            Accounts[CurrentAccForTransfer].Balance+=AmountToBeTransferred;
            Balance-=AmountToBeTransferred;
            CheckerTransfer = true;
            break;
            }
        }
        else if(ChoiceForTransfer == 2)
        {
            CheckerTransfer = false;
        }
        else
        {
        cout << " =======================\n";
        cout << endl;
        cout << "      Invalid Choice    \n";
        cout << endl;
        cout << " ========================n";
        cout << endl;
            CheckerTransfer = false;
            break;
        }
    }
    else if(CheckAccountNum == false)
    {
        cout << "===========================================================\n";
        cout << endl;
        cout << "     Sorry We did Not The Account That You've Entered      \n";
        cout << endl;
        cout << "===========================================================\n";
        cout << endl;
    }
        }

        if((CheckerTransfer == true) || (CheckerTransfer == false))
        {
            break;
        }
    }

    if(CheckerTransfer == false)
    {
            cout << "************************\n";
            cout << endl;
            cout << "      Exiting.....      \n";
            cout << endl;
            cout << "************************\n";
            cout << endl;
          Menu(UserName,Balance,WithDrawLimit,ContactNumber,AccN);
    }
    else if( CheckerTransfer == true)
    {
            cout << " =====================================================================================\n";
            cout << endl;
            cout << "      You've Successfully Transfered: " << AmountToBeTransferred << " PHP To" << endl;
            cout << endl;
            cout << "      Name: " << Accounts[CurrentAccForTransfer].LastName << " " << Accounts[CurrentAccForTransfer].FirstName << " " << Accounts[CurrentAccForTransfer].MiddleInitials;
            cout << endl;
            cout << "      Account Number: #" << Accounts[CurrentAccForTransfer].AccNum << endl;
            cout << endl;
            cout << " =====================================================================================\n";
            cout << endl;
            Menu(UserName,Balance,WithDrawLimit,ContactNumber,AccN);
    }

}

void Load(string UserName,double &Balance,int &WithDrawLimit,string ContactNumber,string AccN)
{
    int LoadAmount,ChoicePin,ChoiceLoad,IndexOfNumberCounter = 0,LenghOfTheContactNumber,ContactNumFound;
    bool LoadChecker;
    string ContactNum;
    bool ContactChecker;
    cout << " ==========================================\n";
	cout << endl;
    cout << "      You Have Selected Load:\n";
    cout << endl;
    cout << " ==========================================\n";
    cout << endl;
    for(int Tries = 3; Tries > 0; Tries--)
    {
    cout << " ==========================================\n";
	cout << endl;
    cout << "      Enter Mobile Number:\n";
    cout << endl;
    cout << "      Press 1 to Exit";
    cout << endl;
    cout << " ==========================================\n";
    cout << endl;
    cout << "           -> ";
    cin >> ContactNum;
    cout << endl;
    if(ContactNum == "1")
    {   ContactChecker = false;
        break;
    }
    LenghOfTheContactNumber = ContactNum.length();
    if(LenghOfTheContactNumber == 11)
    {
        for (int ContactNumFind = 0; ContactNumFind < IteratorForAcc; ContactNumFind++)
        {
            if(ContactNum == Accounts[ContactNumFind].ContactNumber)
            {
                ContactNumFound = ContactNumFind;
                ContactChecker = true;
                break;
            }
            else
            {
                ContactChecker = false;
            }
        }
            if( ContactChecker == true)
            {
            cout << " ==========================================\n";
            cout << endl;
            cout << "      Do You Want To Load?\n ";
            cout << endl;
            cout << "      Account Number: " << Accounts[ContactNumFound].AccNum << endl;
            cout << endl;
            cout << "      Name: " << Accounts[ContactNumFound].LastName << " " << Accounts[ContactNumFound].FirstName << " " << Accounts[ContactNumFound].MiddleInitials << endl;
            cout << endl;
            cout << "      Mobile Number: " << ContactNum << endl;
            cout << endl;
            cout << "      1 : YES\n" << endl << "      2 : NO\n" << endl;
            cout << " ==========================================\n";
            cout << endl;
             cout << "           -> ";
            cin >> ChoiceLoad;
            if(ChoiceLoad == 1)
            {
            cout << " ==========================================\n";
            cout << endl;
            cout << "      Enter The Amount OF Load:\n";
            cout << endl;
            cout << " ==========================================\n";
            cout << endl;
            cout << "           -> ";
            cin >> LoadAmount;
            if(LoadAmount <= Balance)
            {
            Balance -= LoadAmount;
            LoadChecker = true;
            break;
            }
            else if( LoadAmount > Balance)
            {
            cout << "************************\n";
            cout << endl;
            cout << "      Exiting.....      \n";
            cout << endl;
            cout << "************************\n";
            cout << endl;
            LoadChecker = false;
            break;
            }
            }
            else if(ChoiceLoad == 2)
            {
            LoadChecker = false;
            break;
            }
            }
            else if(ContactChecker == false)
            {
                cout << "*********************************************\n";
                cout << endl;
                cout << "      Sorry We Did Not The Find Number      \n";
                cout << endl;
                cout << "********************************************\n";
                cout << endl;
                ContactChecker = false;
            }
    }
    else if( LenghOfTheContactNumber != 11)
    {
            cout << "***************************\n";
            cout << endl;
            cout << "      Invalid Number!      \n";
            cout << endl;
            cout << "***************************\n";
            cout << endl;
        LoadChecker = false;
    }
    }
    if((LoadChecker == false) || (ContactChecker = false))
    {
            cout << "***************************\n";
            cout << endl;
            cout << "      Exiting..........    \n";
            cout << endl;
            cout << "***************************\n";
         Menu(UserName,Balance,WithDrawLimit,ContactNumber,AccN);

    }
    else if(LoadChecker == true)
    {
        cout << " ==================================================================================\n";
        cout << endl;
        cout << "      " <<LoadAmount  << " PHP  Regular Load Successfully Loaded To:  " << Accounts[ContactNumFound].ContactNumber << endl;
        cout << "      From: ATM++, Valid For 1 Year.\n";
        cout << endl;
        cout << " ==================================================================================\n";
        cout << endl;
        Menu(UserName,Balance,WithDrawLimit,ContactNumber,AccN);
    }
}
void ChangePin(string UserName,double &Balance,int &WithDrawLimit,string ContactNumber,string AccN)
{
    string CurrentPin;
    string NewPin;
    bool Check;
    int Confirmation,LengthOfNewPin,LengthCurrentPin;
    cout << " ==========================================\n";
	cout << endl;
    cout << "      You Have Selected Change Pin:\n";
    cout << endl;
    cout << " ==========================================\n";
    cout << endl;

    for(int Change = 3; Change > 0; Change--)
    {
    cout << " ======================================================================\n";
	cout << endl;
    cout << "      Please Enter Your Current Pin:       Remaining Attempt(s): " << Change << endl;
    cout << endl;
    cout << "      Press 1 To Exit:\n";
    cout << endl;
    cout << " ======================================================================\n";
    cout << endl;
    cout << "           -> ";
    cin >> CurrentPin;
    cout << endl;
    LengthCurrentPin = CurrentPin.length();
    if(CurrentPin == "1")
    {
        Check = false;
        break;
    }
   else if(CurrentPin ==  Accounts[CurrentUser].Pin)
    {
        cout << " ==========================================\n";
        cout << endl;
        cout << "      Please Enter Your New Pin:           \n";
        cout << endl;
        cout << " ==========================================\n";
        cout << endl;
        cout << "           -> ";
        cin >> NewPin;
        cout << endl;
        LengthOfNewPin = NewPin.length();
        if( NewPin == Accounts[CurrentUser].Pin)
        {
            cout << "***********************************************\n";
            cout << endl;
            cout << "      Your Old Pin & New Pin Are The Same      \n";
            cout << endl;
            cout << "***********************************************\n";
            cout << endl;
            Check = false;
            break;
        }
       else if(LengthOfNewPin == 6)
        {
        cout << "Your Current Pin " << CurrentPin << " Will now be changed to " << NewPin << endl;
        cout << "Press 1. To Confirm\n Press 2. To Cancel \n";
        cout << "           -> ";
        cin >> Confirmation;
        if(Confirmation == 1 )
        {
        Accounts[CurrentUser].Pin = NewPin;
        cout << " ===============================================\n";
        cout << endl;
        cout << "      You've Successfully Changed Your Pin      \n";
        cout << endl;
        cout << " ===============================================\n";
        cout << endl;
        Check = true;
        }
        else if(Confirmation == 2)
        {
            cout << "***************************\n";
            cout << endl;
            cout << "      Exiting..........    \n";
            cout << endl;
            cout << "***************************\n";
            Check = false;
        }

        else
        {
        cout <<" ****************************\n";
        cout << endl;
        cout <<"       Invalid Choice!      \n";
        cout << endl;
        cout <<" ****************************\n";
        cout << endl;
        Check = false;

        }
        }
        else if( LengthOfNewPin != 6)
        {
        cout <<" ****************************\n";
        cout << endl;
        cout <<"       Invalid Pincode!      \n";
        cout << endl;
        cout <<" ****************************\n";
        cout << endl;
            Check = false;
            break;
        }

    }
    else if(LengthCurrentPin != 6 )
    {
        cout <<" ***************************************\n";
        cout << endl;
        cout <<"      Wrong Pin! Please Try Again!\n";
        cout << endl;
        cout <<" ***************************************\n";
        cout << endl;
   }
   else if( Check == true)
   {
     break;
   }
    }
        if(Check == true)
        {
             Menu(UserName,Balance,WithDrawLimit,ContactNumber,AccN);
        }
        else if(Check == false)
        {
        cout <<" ************************\n";
        cout << endl;
        cout <<"      Exiting......      \n";
        cout << endl;
        cout <<" ************************\n";
        cout << endl;
            Menu(UserName,Balance,WithDrawLimit,ContactNumber,AccN);
        }
}
