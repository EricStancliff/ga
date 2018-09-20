set (libname window)

set(windowinclude
    windowexport.h
    window.h
)

set(windowsource
    window.cpp
)

set(windowprivate
    microsoftwindow_gl_p.h
    unixwindow_gl_p.h
    windowimpl_p.h
    window_interface.h
)

add_library(${libname} SHARED ${windowheaders} ${windowsource} ${windowprivate})

add_definitions(-DWINDOW)

include_directories( ${libname}
    ${GA_INCLUDE_DIR}
)

if(UNIX)
target_link_libraries( ${libname}
    core
    X11 
    GL 
    GLU
)
elseif(WIN32)
target_link_libraries( ${libname}
    core
)
else()
#bad
endif()

install (TARGETS ${libname} DESTINATION lib)
install (FILES ${windowinclude} DESTINATION include)