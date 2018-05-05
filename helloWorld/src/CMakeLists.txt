add_executable(${SUBPROJECT_NAME}
        CinderProjectApp.cpp
        )

target_link_libraries(${SUBPROJECT_NAME} PRIVATE cinder)
set_target_properties(${SUBPROJECT_NAME} PROPERTIES
        CXX_STANDARD 14
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})