#if defined(_MSC_VER)
    //  Microsoft 
    #if defined(CORE)
    #define CORE_EXPORT __declspec(dllexport)
    #else
    #define CORE_EXPORT __declspec(dllimport)
    #endif
#elif defined(__GNUC__)
    //  GCC
    #if defined(CORE)
    #define CORE_EXPORT __attribute__((visibility("default")))
    #else
    #define CORE_EXPORT
    #endif
#else
    //  do nothing and hope for the best?
    #define EXPORT
    #define IMPORT
    #pragma warning Unknown dynamic link import/export semantics.
#endif