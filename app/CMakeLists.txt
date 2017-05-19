file(GLOB CPPS *.cpp)
file(GLOB HPPS ../include/*.h ../include/*.hpp)

find_package( OpenCV REQUIRED )


#include_directories(../include)
#add_executable(app ${CPPS} ${HPPS})
#target_link_libraries(app code_lib)
add_executable( app main.cpp ${CPPS} ${HPPS})
target_link_libraries( app code_lib ${OpenCV_LIBS} /usr/lib/)