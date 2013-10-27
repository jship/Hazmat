#include "TutHelpers.h"

#include <cstring>
#include <sstream>

#include <iostream>

int TutHelpers::sNextId = 0;
std::vector<std::string> TutHelpers::mTestNames;

const char* TutHelpers::stripFileName(const char* fullFileName)
{
    int length = std::strlen(fullFileName);
    
    fullFileName += (length - 1);
    while (*fullFileName != '/' && *fullFileName != '\\')
    {
        fullFileName--;
    }
    
    fullFileName++;

    return fullFileName;
}

std::string TutHelpers::errorMessage(int lineNumber, const std::string& what)
{
    std::stringstream ss;
    ss << "Line " << lineNumber << ", " << what;

    return ss.str();
}

int TutHelpers::nextId()
{
    int id = sNextId;

    sNextId++;
    mTestNames.resize(sNextId);

    return id;
}

const char* TutHelpers::createTestName(const char* fullFileName)
{
    const char* fileName = stripFileName(fullFileName);
    int id = nextId();
    std::stringstream ss;
    char temp[20];

    sprintf(temp, "%03d", id);

    ss << temp << "_" << fileName;

    mTestNames[id].assign(ss.str());
    return mTestNames[id].c_str();
}

