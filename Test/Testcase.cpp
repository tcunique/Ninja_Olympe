#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "../header/window.hpp"

TEST_SUITE("Window")
{
    TEST_CASE("Window")
    {
        Interface interface;
        CHECK(interface.isOpen() == true);
    }
}