

set(
    CHORUS_INCLUDE_FILE
    ${PROJECT_SOURCE_DIR}/include/chorus/client.h
    ${PROJECT_SOURCE_DIR}/include/chorus/server.h
    ${PROJECT_SOURCE_DIR}/include/chorus/serialization/sobject.h
    ${PROJECT_SOURCE_DIR}/include/chorus/serialization/serializer.h
    ${PROJECT_SOURCE_DIR}/include/chorus/serialization/copy_context.h
    ${PROJECT_SOURCE_DIR}/include/chorus/serialization/deserialization_context.h
    ${PROJECT_SOURCE_DIR}/include/chorus/serialization/serialization_context.h
    ${PROJECT_SOURCE_DIR}/include/chorus/serialization/serialization_manager.h
    ${PROJECT_SOURCE_DIR}/include/chorus/io/Stream.h
    ${PROJECT_SOURCE_DIR}/include/chorus/net/TcpClient.h
    ${PROJECT_SOURCE_DIR}/include/chorus/net/TcpListener.h
    ${PROJECT_SOURCE_DIR}/include/chorus/net/NetworkStream.h
)

set(
    CHORUS_SOURCE_FILE
    ${PROJECT_SOURCE_DIR}/source/client.cpp
    ${PROJECT_SOURCE_DIR}/source/server.cpp
)

include_directories(${PROJECT_SOURCE_DIR}/include)
add_library(chorus ${CHORUS_INCLUDE_FILE} ${CHORUS_SOURCE_FILE})
target_link_libraries(chorus ${CONAN_LIBS})