add_executable(${PROJECT_NAME}
        main.cpp
        CinderProjectApp.cpp
        "${PROJECT_SOURCE_DIR}/resources/dummy.png"
        )
target_link_libraries(${PROJECT_NAME} PRIVATE cinder)
set_target_properties(${PROJECT_NAME} PROPERTIES
        CXX_STANDARD 14
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
        RESOURCE "${PROJECT_SOURCE_DIR}/resources/dummy.png"
        )
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/resources)
if (APPLE)
    set_property(TARGET ${PROJECT_NAME} PROPERTY MACOSX_BUNDLE YES)
endif ()