set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)


include_directories(${CMAKE_SOURCE_DIR}/inc)

set(SOURCES
  ${SOURCE_DIR}/utilities.cpp
  ${SOURCE_DIR}/main.cpp
)

add_executable(ekon ${SOURCES}) 

# target_link_libraries(ekon)
