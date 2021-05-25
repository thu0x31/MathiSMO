#pragma once

#include <algorithm>
#include <utility>

namespace thuw {
    template<class VecClass>
    concept VecConcept = requires(VecClass vec) {
        vec.x;
        vec.y;
    };

    template<std::size_t Dimension>
    class Vec;

    using Vec2 = Vec<2>;
    using Vec3 = Vec<3>;
    using Vec4 = Vec<4>;

    template<typename Type>
    concept Number = std::is_floating_point_v<Type> || std::is_integral_v<Type>;

    template<Number ...Num>
    Vec(Num&& ...nums) -> Vec<sizeof...(Num)>;
}

template<std::size_t Dimension>
class thuw::Vec {
    static_assert(Dimension < 5);
    static_assert(Dimension > 1);
};

template<>
class thuw::Vec<2> {
public:
    constexpr static int Dimension = 2;

    float x = 0;
    float y = 0;

    [[nodiscard]] const float* data() const {
        const float data[Dimension] {this->x, this->y};
        return std::move(data);
    }

    template<VecConcept Vec>
    [[nodiscard]] constexpr auto operator+(Vec&& vec) const {
        return thuw::Vec<Dimension>{
            .x = this->x + vec.x,
            .y = this->y + vec.y
        };
    }

    template<Number Num>
    [[nodiscard]] constexpr auto operator+(Num&& value) const {
        return thuw::Vec<Dimension>{
            .x = this->x + value,
            .y = this->y + value
        };
    }
};

template<>
class thuw::Vec<3> {
public:
    constexpr static int Dimension = 3;

    float x = 0;
    float y = 0;
    float z = 0;

    [[nodiscard]] const float* data() const {
        const float data[Dimension] {this->x, this->y, this->z};
        return std::move(data);
    }

    template<VecConcept Vec>
    [[nodiscard]] constexpr auto operator+(Vec&& vec) const {
        
        return thuw::Vec<Dimension>{
            .x = this->x + vec.x,
            .y = this->y + vec.y,
            .z = this->z + vec.z
        };
    }

    template<Number Num>
    [[nodiscard]] constexpr auto operator+(Num&& value) const {
        return thuw::Vec<Dimension>{
            .x = this->x + value,
            .y = this->y + value, 
            .z = this->z + value
        };
    }
};

template<>
class thuw::Vec<4> {
public:
    constexpr static int Dimension = 4;

    float x = 0;
    float y = 0;
    float z = 0;
    float w = 1;

    [[nodiscard]] const float* data() const {
        const float data[Dimension] {this->x, this->y, this->z, this->w};
        return std::move(data);
    }

    template<VecConcept Vec>
    [[nodiscard]] constexpr auto operator+(Vec&& vec) const {
        return thuw::Vec<Dimension>{
            .x = this->x + vec.x,
            .y = this->y + vec.y,
            .z = this->z + vec.z,
            .w = this->w + vec.w
        };
    }

    template<Number Num>
    [[nodiscard]] constexpr auto operator+(Num&& value) const {
        return thuw::Vec<Dimension>{
            .x = this->x + value,
            .y = this->y + value, 
            .z = this->z + value,
            .w = this->w + value
        };
    }
};