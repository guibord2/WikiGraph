add_test( error [==[/workspaces/CS 225/WikiGraph/build/test]==] error  )
set_tests_properties( error PROPERTIES WORKING_DIRECTORY [==[/workspaces/CS 225/WikiGraph/build]==])
add_test( error [==[/workspaces/CS 225/WikiGraph/build/test]==] error  )
set_tests_properties( error PROPERTIES WORKING_DIRECTORY [==[/workspaces/CS 225/WikiGraph/build]==])
add_test( [==['==' operator test1 passed]==] [==[/workspaces/CS 225/WikiGraph/build/test]==] [==['==' operator test1 passed]==]  )
set_tests_properties( [==['==' operator test1 passed]==] PROPERTIES WORKING_DIRECTORY [==[/workspaces/CS 225/WikiGraph/build]==])
add_test( error [==[/workspaces/CS 225/WikiGraph/build/test]==] error  )
set_tests_properties( error PROPERTIES WORKING_DIRECTORY [==[/workspaces/CS 225/WikiGraph/build]==])
add_test( error [==[/workspaces/CS 225/WikiGraph/build/test]==] error  )
set_tests_properties( error PROPERTIES WORKING_DIRECTORY [==[/workspaces/CS 225/WikiGraph/build]==])
add_test( [==['==' operator test2 failed]==] [==[/workspaces/CS 225/WikiGraph/build/test]==] [==['==' operator test2 failed]==]  )
set_tests_properties( [==['==' operator test2 failed]==] PROPERTIES WORKING_DIRECTORY [==[/workspaces/CS 225/WikiGraph/build]==])
set( test_TESTS error error [==['==' operator test1 passed]==] error error [==['==' operator test2 failed]==])