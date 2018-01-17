add_executable(${SUBPROJECT_NAME}_surface_edit_surface
        main.cpp
        CinderProjectApp.cpp
        ${CMAKE_SOURCE_DIR}/image_resources_surface/assets/dummy.png

        )
target_link_libraries(${SUBPROJECT_NAME}_surface_edit_surface PRIVATE cinder)
set_target_properties(${SUBPROJECT_NAME}_surface_edit_surface PROPERTIES
        CXX_STANDARD 14
        RESOURCE "${CMAKE_SOURCE_DIR}/image_resources_surface/assets/dummy.png"
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
        )
target_compile_definitions(${SUBPROJECT_NAME}_surface_edit_surface PRIVATE EDIT_SURFACE)

if (APPLE)
    set_property(TARGET ${SUBPROJECT_NAME}_surface_edit_surface PROPERTY MACOSX_BUNDLE YES)
endif ()
target_include_directories(${SUBPROJECT_NAME}_surface_edit_surface PRIVATE ${PROJECT_SOURCE_DIR}/resources)
##########################3

add_executable(${SUBPROJECT_NAME}_surface_edit_texture
        main.cpp
        CinderProjectApp.cpp
        ${CMAKE_SOURCE_DIR}/image_resources_surface/assets/dummy.png

        )
target_link_libraries(${SUBPROJECT_NAME}_surface_edit_texture PRIVATE cinder)
target_compile_definitions(${SUBPROJECT_NAME}_surface_edit_texture PRIVATE EDIT_TEXTURE)
set_target_properties(${SUBPROJECT_NAME}_surface_edit_texture PROPERTIES
        CXX_STANDARD 14
        RESOURCE "${CMAKE_SOURCE_DIR}/image_resources_surface/assets/dummy.png"
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
        )

if (APPLE)
    set_property(TARGET ${SUBPROJECT_NAME}_surface_edit_texture PROPERTY MACOSX_BUNDLE YES)
endif ()
target_include_directories(${SUBPROJECT_NAME}_surface_edit_texture PRIVATE ${PROJECT_SOURCE_DIR}/resources)

#
