IF (APPLE)
	INCLUDE(CustomTargetCommandsOSX)
ELSEIF (WIN32)
	INCLUDE(CustomTargetCommandsWin32)
ELSE()
	INCLUDE(CustomTargetCommandsLinux)
ENDIF()
