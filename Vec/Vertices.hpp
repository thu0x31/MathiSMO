#pragma once

#include "Vec.hpp"
#include <algorithm>
#include <array>
#include <cstddef>
#include <functional>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <locale>
#include <ostream>
#include <tuple>
#include <type_traits>
#include <vector>
#include <string>


namespace MathiSMO {
    template<class Vertices>
    concept VerticesClass = requires {
        Vertices::dimension;
        Vertices::size;
    };

    template<size_t Size, size_t D>
    class Vertices;

    // Vertices< Type{int, float, double}, ListSize{3, 3, 3, 3}>
    template<Numeric ...Type, size_t ...ListSize>
    Vertices(const Type (&...list)[ListSize]) 
    -> Vertices<sizeof...(ListSize), (ListSize + ...) / sizeof...(ListSize)>;
}

template<size_t Size, size_t D>
class MathiSMO::Vertices {
public:
    using Type = float;

    static constexpr std::size_t dimension = D;
    static constexpr std::size_t size = Size;

    using VecArray = std::array<Type, dimension>;
    std::array<VecArray, size> vertices;

    // TODO: Vertices(Vex...)

    template<size_t ...ListSize>
    constexpr Vertices(const Type (&...list)[ListSize]) : vertices({std::to_array(list)...}) {}

    constexpr auto data() const {
        return this->vertices.data();
    }

    constexpr MathiSMO::Vec<dimension> operator[](const std::size_t index) const {
        return vertices[index];
    }
};