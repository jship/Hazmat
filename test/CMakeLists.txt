SET(TARGET test_hazmat)

SET(HEADERS
    TutHelpers.h
    Common.h
)

SET(SOURCES
    TutHelpers.cpp

    # Unit Tests for Array
    Array/TestArray.cpp

    # Unit Tests for Matrix
    Matrix/TestCofactor.cpp
    Matrix/TestDeterminant.cpp
    Matrix/TestIdentity.cpp
    Matrix/TestInvert.cpp
    Matrix/TestMatrix.cpp
    Matrix/TestTranspose.cpp
    
    # Unit Tests for Quaternion
    Quaternion/TestQuaternion.cpp

    # Unit Tests for Vector
    Vector/TestAdd.cpp
    Vector/TestCross.cpp
    Vector/TestDot.cpp
    Vector/TestLength.cpp
    Vector/TestLerp.cpp
    Vector/TestNegate.cpp
    Vector/TestNorm.cpp
    Vector/TestRotate.cpp
    Vector/TestScale.cpp
    Vector/TestSet.cpp
    Vector/TestSquaredLength.cpp
    Vector/TestSub.cpp
    Vector/TestTransform.cpp
    Vector/TestVector.cpp

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
