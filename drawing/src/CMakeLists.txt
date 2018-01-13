add_executable(Drawing
#add_executable(${SUBPROJECT_NAME}
        CinderProjectApp.cpp
        )
target_link_libraries(Drawing PRIVATE cinder)
set_target_properties(Drawing PROPERTIES
        CXX_STANDARD 14
#        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/
#        OUTPUT_NAME Drawing
        )
if (APPLE)
    set_property(TARGET Drawing PROPERTY MACOSX_BUNDLE YES)
endif ()