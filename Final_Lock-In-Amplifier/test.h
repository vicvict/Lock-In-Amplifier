#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

#include "testlib.h"
#include "finallockinamplifier.h"
#include "cmath"

bool Testlib::__assert_print_to_stderr = true;
bool Testlib::__assert_print_if_ok     = false;
bool Testlib::__assert_throw_exception = true;
bool Testlib::__test_print_to_stderr   = true;
bool Testlib::__test_throw_exception   = false;

void Test1();
void Test2();
void Test3();
void Test4();
void Test5();
void Test6();
void Test7();
void Test8();
void TestAll();

void Test1() {
    SR865 obj;
    obj.connect("COM5","19200","8","1", "NO", "NO");
    for (auto timeConstant: obj.getTimeConstantList()){
        obj.setTimeConstant(timeConstant);
        ASSERT_MSG(obj.getTimeConstant() == timeConstant, "correct timeConstant" + timeConstant);
    }
    obj.disconnect();
}

void Test2() {
    SR865 obj;
    obj.connect("COM5","19200","8","1", "NO", "NO");
    for (auto sensitivity: obj.getSensitivityList()){
        obj.setSensitivity(sensitivity);
        ASSERT_MSG(obj.getSensitivity() == sensitivity, "correct sensetivity" + sensitivity);
    }
    obj.disconnect();
}

void Test3() {
    SR865 obj;
    obj.connect("COM5","19200","8","1", "NO", "NO");
    for (auto refSourse : obj.getRefSourceList()){
        obj.setRefSource(refSourse);
        ASSERT_MSG(obj.getRefSource() == refSourse, "correct refSourse" + refSourse);
    }
    obj.disconnect();
}

void Test4() {
    SR865 obj;
    obj.connect("COM5","19200","8","1", "NO", "NO");
    for (auto refTriggerMode : obj.getRefTriggerModeList()){
        obj.setRefTriggerMode(refTriggerMode);
        ASSERT_MSG(obj.getRefTriggerMode() == refTriggerMode, "correct refSourse" + refTriggerMode);
    }
    obj.disconnect();
}

void Test5() {
    SR865 obj;
    obj.connect("COM5","19200","8","1", "NO", "NO");
    double currentPhase = obj.getMinPhase()+1;
    double step = 1;
    while(currentPhase < obj.getMaxPhase()){
        obj.setInternalPhase(currentPhase);
        ASSERT_MSG(abs(std::stod(obj.getPhase()) - currentPhase) <= obj.getEpsilon(), "correct refSourse");
        currentPhase +=step;
    }
    obj.disconnect();
}
/*
void Test8 ()
{
    {
        Fraction < int > frac1(5,3),frac2;
        ASSERT_MSG((frac2 = frac1) == Fraction < int > (5,3) , " 5/3 is equal to 5/3");
        ASSERT_MSG( frac1 == Fraction < int > (5,3) ," I don't changed");
        ASSERT_MSG((frac2 = 3) == 3 , " 3 is equal to 3");
    }
}
*/
void TestAll() {
    Testlib::Test test;
    RUN_TEST_MSG(test, Test1, "time constant was set correctly");
    RUN_TEST_MSG(test, Test2, "sensitivity was set correctly");
    RUN_TEST_MSG(test, Test3, "referense source set correctly");
    RUN_TEST_MSG(test, Test4, "referense trigger mode set correctly");
    RUN_TEST_MSG(test, Test5, "phase set correctly");
    /*RUN_TEST_MSG(test, Test6, "Multiply test");
    RUN_TEST_MSG(test, Test7, "Division test");
    RUN_TEST_MSG(test, Test8, "Check of equal");*/
}

#endif // TEST_H_INCLUDED

