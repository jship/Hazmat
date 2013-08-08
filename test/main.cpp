#include <tut/tut.hpp>
#include <tut/tut_reporter.hpp>

#include <iostream>

using tut::reporter;
using tut::groupnames;

namespace tut
{
    test_runner_singleton runner;
}

int main(int argc, const char* argv[])
{
    reporter visi;

    if (argc < 2 || argc > 3)
    {
        std::cout << "Hazmat testing application." << std::endl;
        std::cout << "Usage: test_hazmat [regression] | [list] | [group] [test]" << std::endl;
        std::cout << "       List all groups: test_hazmat list" << std::endl;
        std::cout << "       Run all tests: test_hazmat regression" << std::endl;
        std::cout << "       Run one group: test_hazmat <group>" << std::endl;
        std::cout << "       Run one test: test_hazmat <group> <test_num>" << std::endl;
    }

    tut::runner.get().set_callback(&visi);

    try
    {
        if (argc == 1 || (argc == 2 && std::string(argv[1]) == "regression"))
        {
            tut::runner.get().run_tests();
        }
        else if (argc == 2 && std::string(argv[1]) == "list")
        {
            std::cout << "registered test groups:" << std::endl;
            groupnames gl = tut::runner.get().list_groups();
            groupnames::const_iterator i = gl.begin();
            groupnames::const_iterator e = gl.end();
            while(i != e)
            {
                std::cout << "  " << *i << std::endl;
                ++i;
            }
        }
        else if (argc == 2 && std::string(argv[1]) != "regression")
        {
            tut::runner.get().run_tests(argv[1]);
        }
        else if (argc == 3)
        {
            tut::test_result result;
            tut::runner.get().run_test(argv[1],::atoi(argv[2]), result);
        }
    }
    catch (const std::exception& ex)
    {
        std::cerr << "tut raised ex: " << ex.what() << std::endl;
    }

    return 0;
}
