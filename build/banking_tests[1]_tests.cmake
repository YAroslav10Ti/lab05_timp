add_test([=[AccountTest.BasicFunctionality]=]  /home/vboxuser/lab05_timp/build/banking_tests [==[--gtest_filter=AccountTest.BasicFunctionality]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[AccountTest.BasicFunctionality]=]  PROPERTIES WORKING_DIRECTORY /home/vboxuser/lab05_timp/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  banking_tests_TESTS AccountTest.BasicFunctionality)
