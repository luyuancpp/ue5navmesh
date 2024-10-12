#pragma  once
#include <algorithm>
#include <cfloat>
#include <cstring>
#include <cstdint>
#include <functional>
#include <math.h>
#include <memory>
#include <stdarg.h>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#define NAVMESH_API

#define CA_ASSUME(x)
#define CA_SUPPRESS(x)
inline void check(bool) {}
#define DECLARE_LOG_CATEGORY_EXTERN(...)
#define DEFINE_LOG_CATEGORY(...) 
#define DEFINE_LOG_CATEGORY_STATIC(...)
#define UE_CLOG(...)
#define UE_LOG(...)
#define LogRecast 1
#define LogDetour 1
#define LogDebugRaycastCrash 1
#define KINDA_SMALL_NUMBER	(1.e-4f)
       
#ifndef TEXT
#ifdef WIN32
#include <WS2tcpip.h>
#include <Windows.h>
#else // Not WIN32
    #ifdef __linux__
        #define TEXT(quote) L##quote  
    #endif
#endif
#endif // !TEXT


#ifndef _TCHAR_DEFINED
#define _TCHAR_DEFINED
#endif /* !_TCHAR_DEFINED */

enum LOG_VERBOSITY { NoLogging, Fatal, Error, Warning, Display, Log, Verbose, VeryVerbose, All, BreakOnLog };

using dtReal = double;
using uint8 = uint8_t;
using int32 = int32_t;
using uint32 = uint32_t;
using FString = std::string;
using TCHAR = wchar_t;

namespace FMath
{
	template <typename _Ty>
    [[nodiscard]] constexpr _Ty Min(const _Ty& _Left, const _Ty& _Right)
    {
        return _Right <  _Left ? _Right : _Left;
    }
}

template <typename _Ty>
class TSparseArray : public  std::vector<_Ty>
{
public:
    auto Num() const { return this->size(); }
    auto Add(const _Ty&& v) { this->emplace_back(v);  return this->size(); }
    int32_t Add(const _Ty& v) { this->emplace_back(v);  return (int32_t)this->size(); }
    auto GetMaxIndex() const { return this->size(); }
    bool IsAllocated(int) const { return true; }
};

template <typename _Ty>
class TArray : public std::vector<_Ty>
{
public:
    auto Num() const { return this->size(); }
    void Add(const _Ty&& v) { this->emplace_back(v); }
    void Add(const _Ty& v) { this->emplace_back(v); }
};

template <typename _Ty>
class TSet : public std::unordered_set<_Ty>
{
public:
    auto Num() const { return this->size(); }
    void Add(const _Ty&& v) { this->emplace(v); }
    void Add(const _Ty& v) { this->emplace(v); }
    bool Contains(const _Ty& v) const { return this->find(v) != this->end(); }
    void Reserve(int) { return; }
};

template <typename _Ty>
class TSharedPtr : std::shared_ptr<_Ty>
{
public:
    using _Mybase = std::shared_ptr<_Ty>;
    auto Get() const { return _Mybase::get(); }
};


template <typename _TKy, typename _TVy>
class TMap : public std::unordered_map<_TKy, _TVy>
{
};