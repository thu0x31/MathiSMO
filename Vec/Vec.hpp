#pragma once

#include <algorithm>
#include <utility>

namespace MathiSMO {
    namespace Concepts {
        template<class V>
        concept Vec = requires(V vec) {
            vec.x;
            vec.y;
        };

        template<typename Type>
        concept Numeric = std::is_floating_point_v<Type> || std::is_integral_v<Type>;
    }

    template<typename Type, std::size_t Dimension>
    class Vec;

    using Vec2 = Vec<float, 2>;
    using Vec3 = Vec<float, 3>;
    using Vec4 = Vec<float, 4>;

    using Vec2f = Vec<float, 2>;
    using Vec3f = Vec<float, 3>;
    using Vec4f = Vec<float, 4>;

    using Vec2d = Vec<double, 2>;
    using Vec3d = Vec<double, 3>;
    using Vec4d = Vec<double, 4>;

    using Vec2i = Vec<int, 2>;
    using Vec3i = Vec<int, 3>;
    using Vec4i = Vec<int, 4>;

    template<Concepts::Numeric ...Num>
    Vec(Num&& ...nums) -> Vec<std::common_type_t<Num...>, sizeof...(Num)>;
}

template<typename Type, std::size_t Dimension>
class MathiSMO::Vec {
    static_assert(Dimension < 5);
    static_assert(Dimension > 1);
};

// Vec2 ------------------------------------------------------------------------------------------
template<typename Type>
class MathiSMO::Vec<Type, 2> {
public:
    constexpr static int Dimension = 2;

    union {
        struct { Type x, y; };
        struct { Type r, g; };
    };

    [[nodiscard]] const Type* data() const {
        const Type data[Dimension] {this->x, this->y};
        return std::move(data);
    }

    template<Concepts::Vec Vec>
    [[nodiscard]] constexpr auto operator+(Vec&& vec) const {
        return MathiSMO::Vec<Type, Dimension>{
            .x = this->x + vec.x,
            .y = this->y + vec.y
        };
    }

    template<Concepts::Numeric Num>
    [[nodiscard]] constexpr auto operator+(Num&& value) const {
        return MathiSMO::Vec<Type, Dimension>{
            .x = this->x + value,
            .y = this->y + value
        };
    }
};

// Vec3 ------------------------------------------------------------------------------------------
template<typename Type>
class MathiSMO::Vec<Type, 3> {
public:
    constexpr static int Dimension = 3;

    union {
        struct { Type x, y, z; };
        struct { Type r, g, b; };
    };

    [[nodiscard]] const Type* data() const {
        const Type data[Dimension] {this->x, this->y, this->z};
        return std::move(data);
    }

    template<Concepts::Vec Vec>
    [[nodiscard]] constexpr auto operator+(Vec&& vec) const {
        return MathiSMO::Vec<Type, Dimension>{
            .x = this->x + vec.x,
            .y = this->y + vec.y,
            .z = this->z + vec.z
        };
    }

    template<Concepts::Numeric Num>
    [[nodiscard]] constexpr auto operator+(Num&& value) const {
        return MathiSMO::Vec<Type, Dimension>{
            .x = this->x + value,
            .y = this->y + value, 
            .z = this->z + value
        };
    }
};

// Vec4 ------------------------------------------------------------------------------------------
template<typename Type>
class MathiSMO::Vec<Type, 4> {
public:
    constexpr static int Dimension = 4;

    union {
        struct { Type x, y, z, w; };
        struct { Type r, g, b, a; };
    };

    [[nodiscard]] const Type* data() const {
        const Type data[Dimension] {this->x, this->y, this->z, this->w};
        return std::move(data);
    }

    template<Concepts::Vec Vec>
    [[nodiscard]] constexpr auto operator+(Vec&& vec) const {
        return MathiSMO::Vec<Type, Dimension>{
            .x = this->x + vec.x,
            .y = this->y + vec.y,
            .z = this->z + vec.z,
            .w = this->w + vec.w
        };
    }

    template<Concepts::Numeric Num>
    [[nodiscard]] constexpr auto operator+(Num&& value) const {
        return MathiSMO::Vec<Type, Dimension>{
            .x = this->x + value,
            .y = this->y + value, 
            .z = this->z + value,
            .w = this->w + value
        };
    }
};