#pragma once
#include "Units.hpp"
// -------------------------------------------------------------------------------------
class LZ4 {
public:
   static u32 getCompressedSize(u8 *src, SIZE size);
};
// -------------------------------------------------------------------------------------