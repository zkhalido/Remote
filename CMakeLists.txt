cmake_minimum_required(VERSION 3.26.3)

project(Remote)

set(CMAKE_CXX_STANDARD 20)

include_directories(./include ./src ./lib)

set(SOURCES ./src/main.cpp ./src/mainloop.cpp ./src/key_logging.cpp ./stransSpecialKey.cpp ./include/mainloop.h ./include/key_logging.h ./include/stransSpecialKey.h)

add_executable(${PROJECT_NAME} ./src/main.cpp ./src/mainloop.cpp ./src/transSpecialKey.cpp ./src/key_logging.cpp ./include/mainloop.h ./include/transSpecialKey.h ./include/key_logging.h)

#CPACK
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VENDOR "Khalidov")
install(TARGETS Remote RUNTIME DESTINATION bin)
include(CPack)