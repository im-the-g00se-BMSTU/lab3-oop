#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <cstddef>

namespace Constants {
inline constexpr double Epsilon = 1e-12;
inline constexpr std::size_t MaxNumberLength = 16;
inline constexpr std::size_t BinaryOperandCount = 2;
inline constexpr int NumberFormatPrecision = 12;

inline constexpr int MonkeyVisibleMinWidth = 800;
}

#endif // CONSTANTS_H
