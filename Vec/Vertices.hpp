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
    namespace Concepts {
        template<class Vert>
        concept Vertices = requires {
            Vert::dimension;
            Vert::size;
        };
    }

    template<typename Type, size_t Size, size_t D>
    class Vertices;

    // Vertices< Type{int, float, double}, ListSize{3, 3, 3, 3}>
    template<Concepts::Numeric ...Type, size_t ...ListSize>
    Vertices(const Type (&...list)[ListSize]) 
    -> Vertices<std::common_type_t<Type...>, sizeof...(ListSize), (ListSize + ...) / sizeof...(ListSize)>;
}

template<typename Type, size_t Size, size_t D>
class MathiSMO::Vertices {
public:

    static constexpr std::size_t Dimension = D;
    static constexpr std::size_t size = Size;

    using VecArray = std::array<Type, Dimension>;
    std::array<VecArray, size> vertices;

    // TODO: Vertices(Vex...)

    template<size_t ...ListSize>
    constexpr Vertices(const Type (&...list)[ListSize]) : vertices({std::to_array(list)...}) {}

    constexpr auto data() const {
        return this->vertices.data();
    }

    constexpr MathiSMO::Vec<Type, Dimension> operator[](const std::size_t index) const {
        return vertices[index];
    }
};