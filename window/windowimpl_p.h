#pragma once
#if defined(_MSC_VER)
    //  Microsoft 
    #if defined(GA_GL)
    #include "microsoftwindow_gl_p.h"
    #elif defined(GA_VULKAN)
    #include "microsoftwindow_v_p.h"
    #endif
#elif defined(__GNUC__)
    //  GCC
    #if defined(GA_GL)
    #include "unixwindow_gl_p.h"
    #elif defined(GA_VULKAN)
    #include "unixwindow_v_p.h"
    #endif
#else
    //not supported
    static_assert(false, "Unsupported Platform");
#endif