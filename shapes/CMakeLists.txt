
set(libname shapes)

set(shapessource
    quad.cpp
    triangle.cpp
)

set(shapesinclude
    shapesexport.h
    quad.h
    triangle.h
)

set(shapesprivate
    quad_gl_p.h
    quad_interface.h
    quadimpl_p.h
    triangle_gl_p.h
    triangle_interface.h
    triangleimpl_p.h
)


add_library(${libname} SHARED ${shapessource} ${shapesinclude} ${shapesprivate})

add_definitions(
    -DSHAPES
)

include_directories( ${libname}
    ${GA_INCLUDE_DIR}
)

target_link_libraries( ${libname}
    core
)

install (TARGETS ${libname} DESTINATION lib)
install (FILES ${shapesinclude} DESTINATION include)