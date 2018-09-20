set(libname core)

set(coreinclude
    coreexport.h
    event.h
    objectid.h
    outputstream.h
    renderobject.h
)

set(coresource
    event.cpp
    objectid.cpp
    outputstream.cpp
    renderobject.cpp
)

add_library(${libname} SHARED ${coresource} ${coreinclude})

add_definitions(
    -DCORE
)

install (TARGETS ${libname} DESTINATION lib)
install (FILES ${coreinclude} DESTINATION include)