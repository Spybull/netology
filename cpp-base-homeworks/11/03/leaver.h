#ifndef LEAVER_H_
#define LEAVER_H_

#if defined(_MSC_VER)
    #define EXPORT __declspec(dllexport)
    #define IMPORT __declspec(dllimport)
#elif defined(__GNUC__)
    #define EXPORT __attribute__((visibility("default")))
    #define IMPORT
#else
    #define EXPORT
    #define IMPORT
    #pragma warning Unknown dynamic link import/export semantics.
#endif

#ifdef LEAVER_DLL_
#define LEAVER_DLL EXPORT
#else
#define LEAVER_DLL IMPORT
#endif

#include <iostream>
#include <string>

class LEAVER_DLL Leaver {
    public:
        const std::string leave(const std::string &name) const;
};

#endif