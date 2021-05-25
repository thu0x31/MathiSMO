#pragma once

#include <algorithm>
#include <utility>

namespace MathiSMO {
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
    concept Numeric = std::is_floating_point_v<Type> || std::is_integral_v<Type>;

    template<Numeric ...Num>
    Vec(Num&& ...nums) -> Vec<sizeof...(Num)>;
}

template<std::size_t Dimension>
class MathiSMO::Vec {
    static_assert(Dimension < 5);
    static_assert(Dimension > 1);
};

// Vec2 ------------------------------------------------------------------------------------------
template<>
class MathiSMO::Vec<2> {
public:
    constexpr static int Dimension = 2;

    union {
        struct { float x, y; };
        struct { float r, g; };
    };

    [[nodiscard]] const float* data() const {
        const float data[Dimension] {this->x, this->y};
        return std::move(data);
    }

    template<VecConcept Vec>
    [[nodiscard]] constexpr auto operator+(Vec&& vec) const {
        return MathiSMO::Vec<Dimension>{
            .x = this->x + vec.x,
            .y = this->y + vec.y
        };
    }

    template<Numeric Num>
    [[nodiscard]] constexpr auto operator+(Num&& value) const {
        return MathiSMO::Vec<Dimension>{
            .x = this->x + value,
            .y = this->y + value
        };
    }
};

// Vec3 ------------------------------------------------------------------------------------------
template<>
class MathiSMO::Vec<3> {
public:
    constexpr static int Dimension = 3;

    union {
        struct { float x, y, z; };
        struct { float r, g, b; };
    };

    [[nodiscard]] const float* data() const {
        const float data[Dimension] {this->x, this->y, this->z};
        return std::move(data);
    }

    template<VecConcept Vec>
    [[nodiscard]] constexpr auto operator+(Vec&& vec) const {
        
        return MathiSMO::Vec<Dimension>{
            .x = this->x + vec.x,
            .y = this->y + vec.y,
            .z = this->z + vec.z
        };
    }

    template<Numeric Num>
    [[nodiscard]] constexpr auto operator+(Num&& value) const {
        return MathiSMO::Vec<Dimension>{
            .x = this->x + value,
            .y = this->y + value, 
            .z = this->z + value
        };
    }
};

// Vec4 ------------------------------------------------------------------------------------------
template<>
class MathiSMO::Vec<4> {
public:
    constexpr static int Dimension = 4;

    union {
        struct { float x, y, z, w; };
        struct { float r, g, b, a; };
    };

    [[nodiscard]] const float* data() const {
        const float data[Dimension] {this->x, this->y, this->z, this->w};
        return std::move(data);
    }

    template<VecConcept Vec>
    [[nodiscard]] constexpr auto operator+(Vec&& vec) const {
        return MathiSMO::Vec<Dimension>{
            .x = this->x + vec.x,
            .y = this->y + vec.y,
            .z = this->z + vec.z,
            .w = this->w + vec.w
        };
    }

    template<Numeric Num>
    [[nodiscard]] constexpr auto operator+(Num&& value) const {
        return MathiSMO::Vec<Dimension>{
            .x = this->x + value,
            .y = this->y + value, 
            .z = this->z + value,
            .w = this->w + value
        };
    }
};