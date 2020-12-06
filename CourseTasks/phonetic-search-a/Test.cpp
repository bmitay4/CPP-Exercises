/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: ITAY BEN MOSHE
 * 
 * Date: 2020-02
 */
#include "PhoneticFinder.hpp"
#include "doctest.h"
using namespace phonetic;

#include <string>
using namespace std;

// 9
TEST_CASE("Test Checking the presence of the words themselves") {
    string text = "Hi good morning nice world recommend eating cheese snacks";
    CHECK(find(text, "good") == string("good"));
    CHECK(find(text, "morning") == string("morning"));
    CHECK(find(text, "nice") == string("nice"));
    CHECK(find(text, "world") == string("world"));
    CHECK(find(text, "Hi") == string("Hi"));
    CHECK(find(text, "recommend") == string("recommend"));
    CHECK(find(text, "eating") == string("eating"));
    CHECK(find(text, "cheese") == string("cheese"));
    CHECK(find(text, "snacks") == string("snacks"));
}
// 15
TEST_CASE("Test replacement of lower/uper case") {
    string text = "DO yOu goIng to plAy on Pc";
    CHECK(find(text, "dO") == string("DO"));
    CHECK(find(text, "PC") == string("Pc"));
    CHECK(find(text, "You") == string("yOu"));
    CHECK(find(text, "YOU") == string("yOu"));
    CHECK(find(text, "you") == string("yOu"));
    CHECK(find(text, "yOU") == string("yOu"));
    CHECK(find(text, "GOIng") == string("goIng"));
    CHECK(find(text, "GoiNG") == string("goIng"));
    CHECK(find(text, "GOING") == string("goIng"));
    CHECK(find(text, "goiNG") == string("goIng"));
    CHECK(find(text, "play") == string("plAy"));
    CHECK(find(text, "PLAY") == string("plAy"));
    CHECK(find(text, "plAY") == string("plAy"));
    CHECK(find(text, "PLay") == string("plAy"));
    CHECK(find(text, "PlAY") == string("plAy"));
}
// 7
TEST_CASE("Test the replacement of v and w") {
    string text = "The elephant valked in the voods";
    CHECK(find(text, "walked") == string("valked"));
    CHECK(find(text, "woods") == string("voods"));
    CHECK(find(text, "Walked") == string("valked"));
    CHECK(find(text, "Woods") == string("voods"));
    CHECK(find(text, "WOODS") == string("voods"));
    CHECK(find(text, "WOodS") == string("voods"));
    CHECK(find(text, "WalKed") == string("valked"));
}
// 5
TEST_CASE("Test the replacement of j and g") {
    string text = "The goker searched joojle for Batman";
    CHECK(find(text, "Joker") == string("goker"));
    CHECK(find(text, "Google") == string("joojle"));
    CHECK(find(text, "joker") == string("goker"));
    CHECK(find(text, "Goojle") == string("joojle"));
    CHECK(find(text, "jooGle") == string("joojle"));
}
// 9
TEST_CASE("Test the replacement of i and y") {
    string text = "We are fliing seeyng three happi trees";
    CHECK(find(text, "flying") == string("fliing"));
    CHECK(find(text, "seeing") == string("seeyng"));
    CHECK(find(text, "happy") == string("happi"));
    CHECK(find(text, "seeing") == string("seeyng"));
    CHECK(find(text, "happy") == string("happi"));
    CHECK(find(text, "HAPPi") == string("happi"));
    CHECK(find(text, "HappI") == string("happi"));
    CHECK(find(text, "haPPY") == string("happi"));
    CHECK(find(text, "HaPpY") == string("happi"));
}
// 9
TEST_CASE("Test the replacement of o and u") {
    string text = "Du Cuca COla caoses wisdUm";
    CHECK(find(text, "CUCA") == string("Cuca"));
    CHECK(find(text, "CUCA") == string("Cuca"));
    CHECK(find(text, "CULA") == string("COla"));
    CHECK(find(text, "COLA") == string("COla"));
    CHECK(find(text, "Cola") == string("COla"));
    CHECK(find(text, "causes") == string("caoses"));
    CHECK(find(text, "wisdom") == string("wisdUm"));
    CHECK(find(text, "Do") == string("Du"));
    CHECK(find(text, "do") == string("Du"));
}
// 7
TEST_CASE("Test the replacement of d and t") {
    string text = "dhe todo is an extincd birt";
    CHECK(find(text, "The") == string("dhe"));
    CHECK(find(text, "Dodo") == string("todo"));
    CHECK(find(text, "DoDO") == string("todo"));
    CHECK(find(text, "extinct") == string("extincd"));
    CHECK(find(text, "exdinct") == string("extincd"));
    CHECK(find(text, "bird") == string("birt"));
    CHECK(find(text, "birD") == string("birt"));
}
// 5
TEST_CASE("Test the replacement of s and z") {
    string text = "The zchwetS family are ztrange";
    CHECK(find(text, "Schwetz") == string("zchwetS"));
    CHECK(find(text, "SCHWETZ") == string("zchwetS"));
    CHECK(find(text, "strange") == string("ztrange"));
    CHECK(find(text, "Strange") == string("ztrange"));
    CHECK(find(text, "StrangE") == string("ztrange"));
    CHECK(find(text, "STRANGE") == string("ztrange"));
    CHECK(find(text, "sTRANGe") == string("ztrange"));
    CHECK(find(text, "ZtrANGE") == string("ztrange"));
    CHECK(find(text, "zTRange") == string("ztrange"));
}
// 13
TEST_CASE("Test the replacement of c, k and q") {
    string text = "The Korona virus raises many cuestions we do not yet qnow";
    CHECK(find(text, "Corona") == string("Korona"));
    CHECK(find(text, "corona") == string("Korona"));
    CHECK(find(text, "CORONA") == string("Korona"));
    CHECK(find(text, "QORONA") == string("Korona"));
    CHECK(find(text, "Qorona") == string("Korona"));
    CHECK(find(text, "QoroNA") == string("Korona"));
    CHECK(find(text, "KoRONA") == string("Korona"));
    CHECK(find(text, "korona") == string("Korona"));
    CHECK(find(text, "questions") == string("cuestions"));
    CHECK(find(text, "Questions") == string("cuestions"));
    CHECK(find(text, "know") == string("qnow"));
    CHECK(find(text, "Know") == string("qnow"));
    CHECK(find(text, "KNoW") == string("qnow"));
}
// 18
TEST_CASE("Test the replacement of b, f and p") {
    string text =
        "Many foys do not like chocolate pars and brefer futter buffs";
    CHECK(find(text, "boys") == string("foys"));
    CHECK(find(text, "Boys") == string("foys"));
    CHECK(find(text, "bars") == string("pars"));
    CHECK(find(text, "Bars") == string("pars"));
    CHECK(find(text, "Prefer") == string("brefer"));
    CHECK(find(text, "prefer") == string("brefer"));
    CHECK(find(text, "butter") == string("futter"));
    CHECK(find(text, "Butter") == string("futter"));
    CHECK(find(text, "puffs") == string("buffs"));
    CHECK(find(text, "Puffs") == string("buffs"));
    CHECK(find(text, "PuBBs") == string("buffs"));
    CHECK(find(text, "Pubbs") == string("buffs"));
    CHECK(find(text, "pubbs") == string("buffs"));
    CHECK(find(text, "bubbs") == string("buffs"));
    CHECK(find(text, "Bubbs") == string("buffs"));
    CHECK(find(text, "FUFFS") == string("buffs"));
    CHECK(find(text, "fuffs") == string("buffs"));
    CHECK(find(text, "fupps") == string("buffs"));
}