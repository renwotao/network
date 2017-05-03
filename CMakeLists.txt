cmake_minimum_required(VERSION 2.6) 

project(nework) 

ADD_SUBDIRECTORY(src bin) 

SET(CMAKE_INSTALL_PREFIX /usr/local)

INSTALL(PROGRAMS network.sh DESTINATION bin)

#INSTALL(FILES COPYRIGHT README DESTINATION share/doc/network) 

#INSTALL(DIRECTORY doc/ DESTINATION share/doc/network)


