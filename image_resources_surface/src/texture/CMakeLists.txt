add_executable(${SUBPROJECT_NAME}_assets
        main.cpp
        "${CMAKE_SOURCE_DIR}/image_resources_surface/assets/dummy.png"
        CinderProjectApp.cpp

        )
target_link_libraries(${SUBPROJECT_NAME}_assets PRIVATE cinder)
set_target_properties(${SUBPROJECT_NAME}_assets PROPERTIES
        CXX_STANDARD 14
        RESOURCE "${CMAKE_SOURCE_DIR}/image_resources_surface/assets/dummy.png"
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
        )

target_compile_definitions(${SUBPROJECT_NAME}_assets PRIVATE assets)

if (APPLE)
    set_property(TARGET ${SUBPROJECT_NAME}_assets PROPERTY MACOSX_BUNDLE YES)
endif ()

##############################################################

add_executable(${SUBPROJECT_NAME}_resources
        main.cpp
        ${PROJECT_SOURCE_DIR}/resources/Resources.h
        ${CMAKE_SOURCE_DIR}/image_resources_surface/assets/dummy.png
#        ${CMAKE_SOURCE_DIR}/image_resources_surface/resources/Resources.h
        CinderProjectApp.cpp)

target_link_libraries(${SUBPROJECT_NAME}_resources PRIVATE cinder)
set_target_properties(${SUBPROJECT_NAME}_resources PROPERTIES
        CXX_STANDARD 14
        RESOURCE "${CMAKE_SOURCE_DIR}/image_resources_surface/assets/dummy.png"
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
        )
target_include_directories(${SUBPROJECT_NAME}_resources PRIVATE ${PROJECT_SOURCE_DIR}/resources)
target_compile_definitions(${SUBPROJECT_NAME}_resources PRIVATE resources)
if (APPLE)
    set_property(TARGET ${SUBPROJECT_NAME}_resources PROPERTY MACOSX_BUNDLE YES)
endif ()

