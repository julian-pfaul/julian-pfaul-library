#pragma once

#include <cstdint>

#define implicit /* implicit */

namespace julian_pfaul {
    using u8 = std::uint8_t;
    using u16 = std::uint16_t;
    using u32 = std::uint32_t;
    using u64 = std::uint64_t;

    using i8 = std::int8_t;
    using i16 = std::int16_t;
    using i32 = std::int32_t;
    using i64 = std::int64_t;

    using size = std::size_t;

    constexpr size bytes_in_f32 = 4;
    constexpr size bytes_in_f64 = 8;

    using f32 = float;
    static_assert(sizeof(f32) == bytes_in_f32, "unsupported f32 (float) type");

    using f64 = double;
    static_assert(sizeof(f64) == bytes_in_f64, "unsupported f64 (double) type");
}