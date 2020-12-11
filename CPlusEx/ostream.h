#pragma once
#include <cstdio>
namespace IOStream {
    class OStream {
        public:
              OStream() {}
              ~OStream() {}
              OStream(const OStream& ref) {}
              void operator = (const OStream& ref) {}
              const OStream& operator << (const int num) const {
                  printf("%d", num);
                  return *this;
              }
              const OStream& operator << (const double num) const {
                  printf("%f", num);
                  return *this;
              }
              const OStream& operator << (const char ch) const {
                  printf("%c", ch);
                  return *this;
              }
              const OStream& operator << (const char* str) const {
                  printf("%s", str);
                  return *this;
              }
              const OStream& operator << (const OStream& (*fp)(const OStream&)) const {
                  return fp(*this);
              }
    };
    const OStream& EndL(const OStream& ref) {
        printf("\n");
        return ref;
    }
    OStream Print;
}