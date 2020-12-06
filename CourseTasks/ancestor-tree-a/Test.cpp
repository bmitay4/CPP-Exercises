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
#include <string>

#include "FamilyTree.hpp"
#include "doctest.h"
using namespace std;

//
TEST_CASE("Test relation by name") {
    family::Tree T("Yosef");
    T.addFather("Yosef", "Yaakov").addMother("Yosef", "Rachel").addFather("Yaakov", "Isaac").addMother("Yaakov", "Rivka").addFather("Isaac", "Avraham").addFather("Avraham", "Terah");
    CHECK(T.relation("Yaakov") == string("father"));
    CHECK(T.relation("Rachel") == string("mother"));
    CHECK(T.relation("Rivka") == string("grandmother"));
    CHECK(T.relation("Avraham") == string("great-grandfather"));
    CHECK(T.relation("Terah") == string("great-great-grandfather"));
    CHECK(T.relation("xyz") == string("unrelated"));
    CHECK(T.relation("Yosef") == string("me"));

    CHECK(T.relation("YOSEF") == string("unrelated"));
    CHECK(T.relation("YoseF") == string("unrelated"));
    CHECK(T.relation("YoSeF") == string("unrelated"));
    CHECK(T.relation("RIVKA") == string("unrelated"));
    CHECK(T.relation("rivka") == string("unrelated"));
    CHECK(T.relation("rivkA") == string("unrelated"));
    CHECK(T.relation("YAAKOV") == string("unrelated"));
    CHECK(T.relation("YaakoV") == string("unrelated"));
    CHECK(T.relation("yaakoV") == string("unrelated"));
}
TEST_CASE("Test find by name, catch exceptions") {
    family::Tree T("Yosef");
    T.addFather("Yosef", "Yaakov").addMother("Yosef", "Rachel").addFather("Yaakov", "Isaac").addMother("Yaakov", "Rivka").addFather("Isaac", "Avraham").addFather("Avraham", "Terah");

    CHECK(T.find("father") == string("Yaakov"));
    CHECK(T.find("mother") == string("Rachel"));
    CHECK(T.find("me") == string("Yosef"));
    CHECK(T.find("grandmother") == string("Rivka"));
    CHECK(T.find("great-grandfather") == string("Avraham"));
    CHECK(T.find("great-great-grandfather") == string("Terah"));

    CHECK_THROWS(T.find("unrelated"));
    CHECK_THROWS(T.find("ME"));
    CHECK_THROWS(T.find("Me"));
    CHECK_THROWS(T.find("mE"));
    CHECK_THROWS(T.find("great-great-great-grandfather"));
    CHECK_THROWS(T.find("uncle"));
    CHECK_THROWS(T.find("Mother"));
    CHECK_THROWS(T.find("motheR"));
    CHECK_THROWS(T.find("Father"));
    CHECK_THROWS(T.find("fatheR"));
}
TEST_CASE("Test adding parents to a child who does not exist") {
    family::Tree T("Yosef");
    T.addFather("Yosef", "Yaakov").addMother("Yosef", "Rachel").addFather("Yaakov", "Isaac").addMother("Yaakov", "Rivka").addFather("Isaac", "Avraham").addFather("Avraham", "Terah");
    CHECK_THROWS(T.addFather("Ofer", "Tikva"));
    CHECK_THROWS(T.addMother("Shalom", "Tikva"));
    CHECK_THROWS(T.addFather("Yosefi", "Yaakov"));
    CHECK_THROWS(T.addMother("yosef", "Rachel"));
    CHECK_THROWS(T.addFather("Riki", "Bethuel"));
    CHECK_THROWS(T.addFather("rivka", "Bethuel"));
    CHECK_THROWS(T.addFather("Lea", "Lavan"));
    CHECK_THROWS(T.addFather("me", "Avi"));
    CHECK_THROWS(T.addMother("Yakov", "Isaac"));
    CHECK_THROWS(T.addMother("mother", "Rachel"));
    CHECK_THROWS(T.addMother("father", "Yaakov"));
}
TEST_CASE("Test adding parents to a child who has already has parents") {
    family::Tree T("Yosef");
    T.addFather("Yosef", "Yaakov").addMother("Yosef", "Rachel").addFather("Yaakov", "Isaac").addMother("Yaakov", "Rivka").addFather("Isaac", "Avraham").addMother("Isaac", "Sarah").addFather("Avraham", "Terah");
    CHECK_THROWS(T.addFather("Yosef", "Yaakov"));
    CHECK_THROWS(T.addMother("Yosef", "Rachel"));
    CHECK_THROWS(T.addFather("Yaakov", "Isaac"));
    CHECK_THROWS(T.addMother("Yaakov", "Rivka"));
    CHECK_THROWS(T.addFather("Isaac", "Avraham"));
    CHECK_THROWS(T.addMother("Isaac", "Sarah"));
    CHECK_THROWS(T.addFather("Avraham", "Terah"));
}
TEST_CASE("Test remove root") {
    family::Tree T("Yosef"), B("SpongeBob");
    T.addFather("Yosef", "Yaakov").addMother("Yosef", "Rachel");
    B.addFather("SpongeBob", "Patrick").addMother("SpongeBob", "Squidward");

    CHECK_THROWS(T.remove("Yosef"));
    CHECK_THROWS(B.remove("SpongeBob"));
}
TEST_CASE("Mix tests") {
    family::Tree T("Dan"), B("Bob");
    T.addFather("Dan", "Avi").addMother("Dan", "Riki").addFather("Avi", "Shalom").addMother("Avi", "Tikva").addFather("Shalom", "Gabi").addMother("Shalom", "Neta");
    B.addFather("Bob", "Patrick").addMother("Bob", "Squidward").addFather("Patrick", "Eugene").addMother("Patrick", "Sandy").addFather("Eugene", "Pearl").addMother("Eugene", "Karen");

    CHECK_THROWS(T.remove("Dan"));
    CHECK_THROWS(B.remove("Bob"));

    CHECK(T.relation("Dan") == string("me"));
    CHECK(B.relation("Bob") == string("me"));
    CHECK(T.relation("Avi") == string("father"));
    CHECK(B.relation("Patrick") == string("father"));
    CHECK(T.relation("Riki") == string("mother"));
    CHECK(B.relation("Squidward") == string("mother"));
    CHECK(T.relation("Shalom") == string("grandfather"));
    CHECK(B.relation("Eugene") == string("grandfather"));
    CHECK(T.relation("Tikva") == string("grandmother"));
    CHECK(B.relation("Sandy") == string("grandmother"));

    CHECK(T.relation("dan") == string("unrelated"));
    CHECK(B.relation("bob") == string("unrelated"));
    CHECK(T.relation("AvI") == string("unrelated"));
    CHECK(B.relation("PatriCk") == string("unrelated"));
    CHECK(T.relation("RikI") == string("unrelated"));
    CHECK(B.relation("SquIdward") == string("unrelated"));
    CHECK(T.relation("shalom") == string("unrelated"));
    CHECK(B.relation("eugene") == string("unrelated"));
    CHECK(T.relation("tikva") == string("unrelated"));
    CHECK(B.relation("sandy") == string("unrelated"));
    CHECK(T.relation("someone") == string("unrelated"));
    CHECK(B.relation("else") == string("unrelated"));

    CHECK(T.find("father") == string("Avi"));
    CHECK(T.find("mother") == string("Riki"));
    CHECK(T.find("me") == string("Dan"));
    CHECK(T.find("grandmother") == string("Tikva"));
    CHECK(T.find("great-grandfather") == string("Gabi"));
    CHECK(T.find("great-grandmother") == string("Neta"));

    CHECK(B.find("father") == string("Patrick"));
    CHECK(B.find("mother") == string("Squidward"));
    CHECK(B.find("me") == string("Bob"));
    CHECK(B.find("grandmother") == string("Sandy"));
    CHECK(B.find("great-grandfather") == string("Pearl"));
    CHECK(B.find("great-grandmother") == string("Karen"));

    CHECK_THROWS(T.find("unrelated"));
    CHECK_THROWS(T.find("ME"));
    CHECK_THROWS(T.find("Me"));
    CHECK_THROWS(T.find("mE"));
    CHECK_THROWS(T.find("great-great-great-grandfather"));
    CHECK_THROWS(T.find("uncle"));
    CHECK_THROWS(T.find("Mother"));
    CHECK_THROWS(T.find("motheR"));
    CHECK_THROWS(T.find("Father"));
    CHECK_THROWS(T.find("fatheR"));

    CHECK_THROWS(B.find("unrelated"));
    CHECK_THROWS(B.find("ME"));
    CHECK_THROWS(B.find("Me"));
    CHECK_THROWS(B.find("mE"));
    CHECK_THROWS(B.find("great-great-great-grandfather"));
    CHECK_THROWS(B.find("uncle"));
    CHECK_THROWS(B.find("Mother"));
    CHECK_THROWS(B.find("motheR"));
    CHECK_THROWS(B.find("Father"));
    CHECK_THROWS(B.find("fatheR"));
}