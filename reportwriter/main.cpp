#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <report.h>
#include <enums.h>
#define over3 "\t\t\t"
#define down3 "\n\n\n"

//function prototypes
void ShowWelcome();
Report MainMenu();
Report DrMenu();
Report DrDisorderly();
void ShowEntries(Report);
std::string SetAuthorLastName();
std::string SetAuthorFirstName();
std::string SetAuthorDrCode();
std::string SetAuthorAssignedPost();
std::string SetAuthorLocation();
std::string SetSubjectLocation();
std::string SetAuthorizingDRCode();
std::string SetIncidentDate();
std::string SetIncidentTime();
std::string SetWrittenDate();
Report ShowReportSummary(Report);
std::string SetSubjectLast();
std::string SetSubjectFirst();

// starting point main function
int main()
{
    ShowWelcome();
    ShowReportSummary(MainMenu());
    system("PAUSE");
    return 0;
}
void ShowWelcome()
{
	system("CLS");
	std::cout << over3 << "WELCOME TO THE FDC REPORT WIZARD" << std::endl;
	std::cout << over3 << "   Programmer: Bart R Lyons" << std::endl;
	std::cout << over3 << "Email: lyons.bart@gmail.com" << std::endl;
	std::cout << down3 << down3 << down3 << down3 << down3 << down3 << down3;
	system("PAUSE");
}
Report MainMenu()
{
    int menuSelection{0};
    Report myReport;
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
            case OPTION_ONE:
                myReport = DrMenu();
                break;
            case OPTION_TWO:
                std::cout << "Incident Reports not yet implemented!";
                break;
            case EXIT:
                std::cout << "Exit!";

        }
    }while(menuSelection != EXIT);
    return myReport;
}
Report DrMenu()
{
	Report myReport;
	int menuSelection{0};

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
            case OPTION_ONE:
                myReport = DrDisorderly();
                break;
            case OPTION_TWO:
                std::cout << "Incident Reports not yet implemented!"; //TODO OTHER DRS
                break;
            case EXIT:
                std::cout << "EXIT"; //TODO
        }
    return myReport;

}
Report DrDisorderly()
{

    Report disorderly;
    disorderly.authorLast = SetAuthorLastName();
    disorderly.authorFirst = SetAuthorFirstName();
    disorderly.authorDRCode = SetAuthorDrCode();
    disorderly.authorAssignedPost = SetAuthorAssignedPost();
    disorderly.authorLocation = SetAuthorLocation();
    disorderly.subjectLocation = SetSubjectLocation();
    disorderly.subjectLast = SetSubjectLast();
    disorderly.subjectFirst = SetSubjectFirst();
    disorderly.authorizingDRCode = SetAuthorizingDRCode();
    disorderly.incidentDate = SetIncidentDate();
    disorderly.incidentTime = SetIncidentTime();
    disorderly.writtenDate = SetWrittenDate();
    ShowEntries(disorderly);
    system("PAUSE");
    return disorderly;
}
void ShowEntries(Report myReport)
{
	system("CLS");
	std::cout << "Author Name: " << myReport.authorLast <<  "," << myReport.authorFirst << " " << myReport.authorDRCode << std::endl;
    std::cout << "Assigned Post: " << myReport.authorAssignedPost << " Author's Location: " << myReport.authorLocation << " Author's Position: " << myReport.postSupervisionLevel << std::endl;
    std::cout <<"Subject Name: " << myReport.subjectLast << ", " << myReport.subjectFirst << ": " << myReport.subjectDCNumber << " Subject Location: " << myReport.subjectLocation << std::endl;
    std::cout << "Authorized By: " << myReport.authorizingLast <<  "," << myReport.authorizingFirst << " " << myReport.authorizingDRCode << std::endl;
    std::cout << "Incident Date: " << myReport.incidentDate << " Incident Time: " << myReport.incidentTime << std::endl;
    std::cout << "Report Completed Date: " << myReport.writtenDate << " Report Completed Time: " << myReport.writtenTime << std::endl;

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
	//transform(firstName.begin(), firstName.end(), firstName.begin(), ::toupper);
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
std::string SetSubjectLocation()
{
	std::cout << "Enter Subjects Location During Infraction: ";
	std::string location;
	std::getline(std::cin,location);
	transform(location.begin(), location.end(), location.begin(), ::toupper);
	return location;
}
std::string SetAuthorizingDRCode()
{
	std::cout << "Enter Authorizing DR Code: ";
	std::string drCode;
	std::getline(std::cin,drCode);
	transform(drCode.begin(), drCode.end(), drCode.begin(), ::toupper);
	return drCode;
}
std::string SetIncidentDate()
{
	std::cout << "Enter Infraction Date: ";
	std::string date;
	std::getline(std::cin,date);
	transform(date.begin(), date.end(), date.begin(), ::toupper);
	return date;
}
std::string SetIncidentTime()
{
	std::cout << "Enter Infraction Time: ";
	std::string time;
	std::getline(std::cin,time);
	transform(time.begin(), time.end(), time.begin(), ::toupper);
	return time;
}
std::string SetWrittenDate()
{
	std::cout << "Report Completion Date: ";
	std::string date;
	std::getline(std::cin,date);
	transform(date.begin(), date.end(), date.begin(), ::toupper);
	return date;
}
std::string SetSubjectLast()
{
	std::cout << "Enter Subject Last Name: ";
	std::string name;
	std::getline(std::cin,name);
	transform(name.begin(), name.end(), name.begin(), ::toupper);
	return name;
}
std::string SetSubjectFirst()
{
	std::cout << "Enter Subject First Name: ";
	std::string name;
	std::getline(std::cin,name);
	transform(name.begin(), name.end(), name.begin(), ::toupper);
	return name;
}
Report ShowReportSummary(Report myReport)
{
    std::cout << "On " << myReport.incidentDate << " I was assigned as " << myReport.authorAssignedPost << " housing " << myReport.postSupervisionLevel << ". "<< "At approximately " << myReport.incidentTime << " I was present in the " << myReport.authorLocation << " when I observed inmate " << myReport.subjectLast << ", " << myReport.subjectFirst << myReport.subjectDCNumber << " waiving his arms in the air and yelling \"" << myReport.subjectStatement << "\"" << " thus inmate " << myReport.subjectLast << "was disrupting the normal operations of " << myReport.subjectLocation << " area. " << "The shift supervisor authorized inmate " << myReport.subjectLast << " to be charged with " << myReport.reportCharge << std::endl;
    return myReport;
}
