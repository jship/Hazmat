# Finds TUT directory.
# TUT is the Template Unit Test framework.
# It is a header-only library.
#
# This will define the following:
# TUT_FOUND
# TUT_INCLUDE_DIR

FIND_PATH(TUT_INC_DIR tut.h
    PATH_SUFFIXES tut
    PATHS
    ${TUT_ROOT}
    $ENV{TUT_ROOT}
    ~/ThirdParty
    ~/Library/Frameworks
    C:/ThirdParty
    /Library/Frameworks
    /usr/local/
    /usr/
    /sw          # Fink
    /opt/local/  # DarwinPorts
    /opt/csw/    # Blastwave
    /opt/
)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(TUT DEFAULT_MSG TUT_INC_DIR)

IF(TUT_FOUND)
	SET(TUT_INCLUDE_DIR ${TUT_INC_DIR})
ENDIF(TUT_FOUND)

MARK_AS_ADVANCED(TUT_INC_DIR)
