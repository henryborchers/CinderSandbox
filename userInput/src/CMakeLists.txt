add_executable(${SUBPROJECT_NAME}
        CinderProjectApp.cpp
        Circle.cpp Circle.h)
target_link_libraries(${SUBPROJECT_NAME} PRIVATE cinder)
set_target_properties(${SUBPROJECT_NAME} PROPERTIES
        CXX_STANDARD 14
        )
if (APPLE)
    set_property(TARGET ${SUBPROJECT_NAME} PROPERTY MACOSX_BUNDLE YES)
endif ()