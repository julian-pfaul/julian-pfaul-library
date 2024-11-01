//
// Created by julian_pfaul on 11/1/24.
//

#pragma once

#include <cstdint>

inline namespace julian_pfaul {
    using u8 = std::uint8_t;
    using u16 = std::uint16_t;
    using u32 = std::uint32_t;
    using u64 = std::uint64_t;

    using i8 = std::int8_t;
    using i16 = std::int16_t;
    using i32 = std::int32_t;
    using i64 = std::int64_t;

    using f32 = float;
    static_assert(sizeof(f32) == 4, "unsupported f32 (float) type");

    using f64 = double;
    static_assert(sizeof(f64) == 8, "unsupported f64 (double) type");
}