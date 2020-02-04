

set(
    CHORUS_INCLUDE_FILE
    ${PROJECT_SOURCE_DIR}/include/chorus/client.h
    ${PROJECT_SOURCE_DIR}/include/chorus/server.h
)

set(
    CHORUS_SOURCE_FILE
    ${PROJECT_SOURCE_DIR}/source/client.cpp
    ${PROJECT_SOURCE_DIR}/source/server.cpp
)

include_directories(${PROJECT_SOURCE_DIR}/include)
add_library(chorus ${CHORUS_INCLUDE_FILE} ${CHORUS_SOURCE_FILE})
target_link_libraries(chorus ${CONAN_LIBS})