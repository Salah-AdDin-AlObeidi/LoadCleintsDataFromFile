 
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;
 const string FileClinte = "Clinte.txt";

 
struct sClient 
{
	string AccountNumber;
	string PinCode;
	string Name;
	 
	string Phone  ;
	double AccountBalance = 0;

	 
  };


vector<string> SplitString(string S1, string Delim)
{
	vector<string> vString;
	short pos = 0;
	string sWord; // define a string variable
	// use find() function to get the position of the delimiters
	while ((pos = S1.find(Delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos); // store the word
		if (sWord != "")
		{
			vString.push_back(sWord);
		}
		S1.erase(0, pos + Delim.length());
	}
	if (S1 != "")
	{
		vString.push_back(S1); // it adds last word of the string.
	}
	return vString;
}




sClient ConvertLinetoRecord(string Line, string Seperator =
	"#//#")
{
	sClient Client;
	vector<string> vClientData;
	vClientData = SplitString(Line, Seperator);
	Client.AccountNumber = vClientData[0];
	Client.PinCode = vClientData[1];
	Client.Name = vClientData[2];
	Client.Phone = vClientData[3];
   Client.AccountBalance = stod(vClientData[4]);//cast string to

		return Client;
}


vector<sClient> LoadCleintsDataFromFile(string FileMy)
{

	vector<sClient> vClinte;
	fstream myFile;
	myFile.open(FileMy, ios::in);


	if (myFile.is_open())
	{

	  string Line;
	  sClient Clinte;
		while (getline(myFile, Line))
		{

			Clinte = ConvertLinetoRecord(Line);

			vClinte.push_back(Clinte);
		}
		myFile.close();
	}


	return vClinte;

}
 
  
	void PrintClientRecord(sClient Client)
	{
		cout << "| " << setw(15) << left << Client.AccountNumber;
		cout << "| " << setw(10) << left << Client.PinCode;
		cout << "| " << setw(40) << left << Client.Name;
		cout << "| " << setw(12) << left << Client.Phone;
		cout << "| " << setw(12) << left << Client.AccountBalance;
	}


 
 
void prentClinte(vector<sClient> vClinte)
{
 
	"\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	cout << "| " << left << setw(15) << "Accout Number";
	cout << "| " << left << setw(10) << "Pin Code";
	 
	 
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(12) << "Balance";
	cout <<
		"\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

	for (sClient &Clinte : vClinte)
	{

		PrintClientRecord(Clinte);
      cout << endl;
	}
	cout <<
		"\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

 }
 

  



 
 
int main()
{
 
	vector<sClient> vClinte = LoadCleintsDataFromFile(FileClinte);
	prentClinte(vClinte);

	system("pause>0");

	return 0;
}
 