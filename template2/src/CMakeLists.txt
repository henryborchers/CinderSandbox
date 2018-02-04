add_executable(${PROJECT_NAME}
        main.cpp
        CinderProjectApp.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE cinder)
set_target_properties(${PROJECT_NAME} PROPERTIES
        CXX_STANDARD 14
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
        )
if (APPLE)
    set_property(TARGET ${PROJECT_NAME} PROPERTY MACOSX_BUNDLE YES)
endif ()