add_library (Main 
  main.cpp)

install (TARGETS Main DESTINATION bin)
#install (FILES Speaker.h DESTINATION include) # for headers
