if(EXISTS "/home/vboxuser/lab05_timp/build/banking_tests[1]_tests.cmake")
  include("/home/vboxuser/lab05_timp/build/banking_tests[1]_tests.cmake")
else()
  add_test(banking_tests_NOT_BUILT banking_tests_NOT_BUILT)
endif()
