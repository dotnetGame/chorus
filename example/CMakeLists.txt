
include_directories(${PROJECT_SOURCE_DIR}/include)
add_executable(chorus_client ${PROJECT_SOURCE_DIR}/example/client_example.cpp)
target_link_libraries(chorus_client chorus)

add_executable(chorus_server ${PROJECT_SOURCE_DIR}/example/server_example.cpp)
target_link_libraries(chorus_server chorus)