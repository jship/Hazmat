SET(TARGET test_hazmat)

SET(HEADERS
    TutHelpers.h
    Common.h
)

SET(SOURCES
    TutHelpers.cpp
    ArrayTest.cpp
    MatrixTest.cpp
    VectorTest.cpp
    main.cpp
)

SET(DEPENDENCIES
)

SET(DATA
)

ADD_TEST_APP(${TARGET}
	"${HEADERS}"
	"${SOURCES}"
	"${DEPENDENCIES}"
    "${DATA}"
)
