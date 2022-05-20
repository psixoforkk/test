#include "../thirdparty/ctest.h"
#include "../src/libs/trainer.h"
#include "../src/libs/MenuLogic.h"

CTEST(TrainerChekSravnenieDif, ChooseDifficulty) {
    int variable = ChooseDifficulty();
    int res;
    if ( variable > 5 || variable < 1) {
        res = 0;
    } 
    else {
        res = 1;
    } 
    ASSERT_EQUAL(1, res); 
}

CTEST(TrainerChekSravnenieMenu, ShowMenu) {
    int variable = ShowMenu();
    int res;
    if ( variable > 5 || variable < 1) {
        res = 0;
    } 
    else {
        res = 1;
    } 
    ASSERT_EQUAL(1, res); 
}

CTEST(TrainerChekSravnenieZaglavnaya, Sravnenie) {
    char sym1 = 'A';
    ASSERT_EQUAL(Sravnenie(sym1, 'a'), 0);
    ASSERT_EQUAL(Sravnenie(sym1, 'B'), 0);
}

CTEST(TrainerChekSravneniePropis, Sravnenie) {
    char sym1 = 'a';
    ASSERT_EQUAL(Sravnenie(sym1, 'A'), 0);
    ASSERT_EQUAL(Sravnenie(sym1, 'b'), 0);
}

CTEST(TrainerChekSravnenieDot, Sravnenie) {
    char sym1 = '.';
    ASSERT_EQUAL(Sravnenie(sym1, '.'), 1);
}

CTEST(TrainerChekSravnenieExp, Sravnenie) {
    char sym1 = '!';
    ASSERT_EQUAL(Sravnenie(sym1, '!'), 1);
}

CTEST(TrainerChekSravnenieQue, Sravnenie) {
    char sym1 = '?';
    ASSERT_EQUAL(Sravnenie(sym1, '?'), 1);
}

CTEST(TrainerChekSravnenieSpace, Sravnenie) {
    char sym1 = ' ';
    ASSERT_EQUAL(Sravnenie(sym1, ' '), 1);
}

CTEST(TrainerChekSravnenieInclude, include) {
    ASSERT_EQUAL(sizeof(int), sizeof(include()));
}

CTEST(TrainerChekSwitch, SwithMode) {
    int variable = SwitchMode(0,1);
    int res;
    if ( variable > 4 || variable < 0) {
        res = 0;
    } 
    else {
        res = 1;
    } 
    ASSERT_EQUAL(res, 1);
}

CTEST(TrainerChekSravnenieStart, Start) {
    int res = sizeof(float);
    ASSERT_EQUAL(sizeof(Start(1)), res);
    ASSERT_EQUAL(sizeof(Start(2)), res);
    ASSERT_EQUAL(sizeof(Start(3)), res); 
}

