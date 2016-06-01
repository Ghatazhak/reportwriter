#pragma once
#include <string>
struct Report
{
	std::string authorLast;
	std::string authorFirst;
	std::string authorDRCode;
	std::string authorAssignedPost;
	std::string postSupervisionLevel; //TODO IMPLEMENT SUPERVISOR OR OFFICER.
	std::string authorLocation;
	std::string subjectLocation;
	std::string subjectLast;
	std::string subjectFirst;
	std::string subjectDCNumber;
	std::string subjectStatement;
	std::string reportCharge;
	std::string authorizingLast;
	std::string authorizingFirst;
	std::string authoirzingRank;
	std::string authorizingDRCode;
	std::string incidentDate;
	std::string incidentTime;
	std::string writtenDate;
	std::string writtenTime;
};
