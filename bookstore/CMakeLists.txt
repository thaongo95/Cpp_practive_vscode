cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(RUN)
file(GLOB SOURCE_FILE ${CMAKE_CURRENT_SOURCE_DIR}/book/book.cpp
                    ${CMAKE_CURRENT_SOURCE_DIR}/bookshop/bookshop.cpp)
add_executable(RUN main.cpp ${SOURCE_FILE})
target_link_directories(RUN PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/book
                      ${CMAKE_CURRENT_SOURCE_DIR}/bookshop)
