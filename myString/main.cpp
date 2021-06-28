// myString_homework.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "myString.h"
/*#include "doctest.h"

TEST_CASE("Addition") {
    myString str1 = "my";
    myString str2 = "string";
    myString str3;
    str3 += "my_string";
    CHECK(str1 + ' ' + str2 == "my string");
    CHECK(str3 == "my_string");
}

TEST_CASE("operator[]") {
    myString str1 = "my";
    CHECK(str1[0] == 'm');
    str1[0] = 'y';
    CHECK(str1[0] == 'y');
    CHECK(str1 == "yy");
}

TEST_CASE("Multiplication") {
    myString str1 = "my";
    str1 *= 3;
    CHECK(str1 == "mymymy");
}*/


int main()
{
    //doctest::Context().run();
    myString str1 = "string";
    std::cin >> str1;
    std::cin >> str1;
    std::cout << str1 << std::endl;
    return 0;
}
