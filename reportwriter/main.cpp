#include<iostream>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<report.h>
#define over3 "\t\t\t"
#define down3 "\n\n\n"

//function prototypes
void ShowWelcome();
void MainMenu();
void DrMenu();
void DrDisorderly();
void ShowEntries(Report);
std::string SetAuthorLastName();
std::string SetAuthorFirstName();
std::string SetAuthorDrCode();
std::string SetAuthorAssignedPost();
std::string SetAuthorLocation();

int main()
{
    ShowWelcome();
    MainMenu();
    system("PAUSE");







    return 0;
}

void ShowWelcome()
{
	system("CLS");
	std::cout << over3 << "WELCOME TO THE FDC REPORT WIZARD" << std::endl;
	std::cout << over3 << "   Programmer: Bart R Lyons" << std::endl;
	std::cout << over3 << "Email: nocternalwarrior@gmail.com" << std::endl;
	std::cout << down3 << down3 << down3 << down3 << down3 << down3 << down3;
	system("PAUSE");
}
void MainMenu()
{
    int menuSelection{0};
    do
    {


        system("CLS");
        std::cout << down3 << down3;
        std::cout << over3 << "       MAIN MENU" << std::endl;
        std::cout << over3 << "_______________________" << std::endl;
        std::cout << over3 << "1. Disciplinary Report" << std::endl;
        std::cout << over3 << "2. Incident Report" << std::endl;
        std::cout << over3 << "3. Exit" << std::endl;
        std::cout << over3 << "Menu Selection: ";
        std::cin >> menuSelection;
        switch(menuSelection)
        {
            case 1:
                DrMenu();
                break;
            case 2:
                std::cout << "Incident Reports not yet implemented!";
                break;
            default:
                std::cout << "Default";

        }
    }while(menuSelection !=3);
}
void DrMenu()
{
	int menuSelection{0};
	do
    {
        system("CLS");
        std::cout << over3 << " DISCIPLINARY REPORT MENU" << std::endl;
        std::cout << over3 << "___________________________" << std::endl;
        std::cout << over3 << "1. 9-17 (Disorderly Conduct)" << std::endl;
        std::cout << over3 << "2. Other DR type" << std::endl;
        std::cout << over3 << "3. Exit" << std::endl;
        std::cout << over3 << "Menu Selection: ";
        std::cin >> menuSelection;

        switch(menuSelection)
        {
            case 1:
                DrDisorderly();
                break;
            case 2:
                std::cout << "Incident Reports not yet implemented!"; //TODO OTHER DRS
                break;
            default:
                std::cout << "Default"; //TODO
        }
    }while(menuSelection != 3);


}
void DrDisorderly()
{
    Report disorderly;
    disorderly.authorLast = SetAuthorLastName();
    disorderly.authorFirst = SetAuthorFirstName();
    disorderly.authorDRCode = SetAuthorDrCode();
    disorderly.authorAssignedPost = SetAuthorAssignedPost();
    disorderly.authorLocation = SetAuthorLocation();
    ShowEntries(disorderly);
    system("PAUSE");
}
void ShowEntries(Report myReport)
{
	system("CLS");
	std::cout << "Author Name: " << myReport.authorLast <<  "," << myReport.authorFirst
        << " " << myReport.authorDRCode << std::endl;
    std::cout << "Assigned Post: " << myReport.authorAssignedPost << "Author's Location: " << myReport.authorLocation << std::endl;
}
std::string SetAuthorLastName()
{
	std::cout << "Enter Author's last name: ";
	std::string lastName;
	std::cin >> lastName;
	transform(lastName.begin(), lastName.end(), lastName.begin(), ::toupper);
	return lastName;
}
std::string SetAuthorFirstName()
{
	std::cout << "Enter Author's first name: ";
	std::string firstName;
	std::cin >> firstName;
	transform(firstName.begin(), firstName.end(), firstName.begin(), ::toupper);
	return firstName;
}
std::string SetAuthorDrCode()
{
	std::cout << "Enter Author's DR Code: ";
	std::string drCode;
	std::cin >> drCode;
	std::cin.ignore(32767, '\n'); // Need this to flush newline out of input stream.
	transform(drCode.begin(), drCode.end(), drCode.begin(), ::toupper);
	return drCode;
}
std::string SetAuthorAssignedPost()
{
	std::cout << "Enter Author's Assigned Post: ";
	std::string aPost;
	std::getline(std::cin,aPost);
	transform(aPost.begin(), aPost.end(), aPost.begin(), ::toupper);
	return aPost;
}
std::string SetAuthorLocation()
{
	std::cout << "Enter Author's Location During Infraction: ";
	std::string location;
	std::getline(std::cin,location);
	transform(location.begin(), location.end(), location.begin(), ::toupper);
	return location;
}
