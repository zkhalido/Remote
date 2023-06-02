cmake_minimum_required(VERSION 3.26.3)

project(Remote)

set(CMAKE_CXX_STANDARD 20)

include_directories(./include ./src ./lib)

set(SOURCES 
./src/main.cpp 
./src/mainloop.cpp 
./include/mainloop.h 
./src/key_save.cpp 
./include/key_save.h 
./transSpecialKey.cpp 
./include/transSpecialKey.h 
./src/encrypt.cpp 
./include/encrypt.h)

add_executable(${PROJECT_NAME} 
./src/main.cpp 
./src/mainloop.cpp 
./include/mainloop.h 
./src/transSpecialKey.cpp 
./include/transSpecialKey.h 
./src/key_save.cpp 
./include/key_save.h 
./src/encrypt.cpp 
./include/encrypt.h)

#CPACK
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VENDOR "Khalidov")
install(TARGETS Remote RUNTIME DESTINATION bin)
include(CPack)