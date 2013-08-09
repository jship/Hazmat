#include "TutHelpers.h"

#include <cstring>
#include <sstream>

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

const char* TutHelpers::errorMessage(int lineNumber, const char* what)
{
    std::stringstream ss;
    ss << "Line " << lineNumber << ", " << what;
    
    return ss.str().c_str();
}
