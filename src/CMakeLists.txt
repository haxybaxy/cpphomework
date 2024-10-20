set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

add_library(main13 STATIC main13.cpp)
add_library(main14 STATIC main14.cpp)
add_library(main15 STATIC main15.cpp)

target_include_directories(main13 PUBLIC ${INCLUDE_DIR})
target_include_directories(main14 PUBLIC ${INCLUDE_DIR})
target_include_directories(main15 PUBLIC ${INCLUDE_DIR})

add_executable(main13exec main13.cpp)
target_link_libraries(main13exec main13)
add_executable(main14exec main14.cpp)
target_link_libraries(main14exec main14)
add_executable(main15exec main15.cpp)
target_link_libraries(main15exec main15)


