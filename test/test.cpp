#include <type_traits>
#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include "../Vec/Vec.hpp"
#include "../Vec/Vertices.hpp"

TEST_CASE("init", "[Vec]") {
    // basic
    MathiSMO::Vec v2{1.f, 2.f}; 
    MathiSMO::Vec v3{1.f, 2.f, 3.f};
    MathiSMO::Vec v4{1.f, 2.f, 3.f, 4.f};

    REQUIRE(std::is_same<MathiSMO::Vec2, decltype(v2)>::value);
    REQUIRE(v2.Dimension == 2);
    REQUIRE(v2.x == 1.f); REQUIRE(v2.y == 2.f);
    REQUIRE(v2.r == 1.f); REQUIRE(v2.g == 2.f);
    REQUIRE(std::is_same<MathiSMO::Vec3, decltype(v3)>::value);
    REQUIRE(v3.Dimension == 3);
    REQUIRE(v3.x == 1.f); REQUIRE(v3.y == 2.f); REQUIRE(v3.z == 3.f);
    REQUIRE(v3.r == 1.f); REQUIRE(v3.g == 2.f); REQUIRE(v3.b == 3.f);
    REQUIRE(std::is_same<MathiSMO::Vec4, decltype(v4)>::value);
    REQUIRE(v4.Dimension == 4);
    REQUIRE(v4.x == 1.f); REQUIRE(v4.y == 2.f); REQUIRE(v4.z == 3.f); REQUIRE(v4.w == 4.f);
    REQUIRE(v4.r == 1.f); REQUIRE(v4.g == 2.f); REQUIRE(v4.b == 3.f); REQUIRE(v4.a == 4.f);

    // const
    const MathiSMO::Vec v2_const{1.f, 2.f};
    const MathiSMO::Vec v3_const{1.f, 2.f, 3.f};
    const MathiSMO::Vec v4_const{1.f, 2.f, 3.f, 4.f};

    REQUIRE(v2_const.Dimension == 2);
    REQUIRE(v2_const.x == 1.f); REQUIRE(v2_const.y == 2.f);
    REQUIRE(v2_const.r == 1.f); REQUIRE(v2_const.g == 2.f);
    REQUIRE(v3_const.Dimension == 3);
    REQUIRE(v3_const.x == 1.f); REQUIRE(v3_const.y == 2.f); REQUIRE(v3_const.z == 3.f);
    REQUIRE(v3_const.r == 1.f); REQUIRE(v3_const.g == 2.f); REQUIRE(v3_const.b == 3.f);
    REQUIRE(v4_const.Dimension == 4);
    REQUIRE(v4_const.x == 1.f); REQUIRE(v4_const.y == 2.f); REQUIRE(v4_const.z == 3.f); REQUIRE(v4_const.w == 4.f);
    REQUIRE(v4_const.r == 1.f); REQUIRE(v4_const.g == 2.f); REQUIRE(v4_const.b == 3.f); REQUIRE(v4_const.a == 4.f);

    // constexpr
    constexpr MathiSMO::Vec v2_constexpr{1.f, 2.f};
    constexpr MathiSMO::Vec v3_constexpr{1.f, 2.f, 3.f};
    constexpr MathiSMO::Vec v4_constexpr{1.f, 2.f, 3.f, 4.f};

    REQUIRE(v2_constexpr.Dimension == 2);
    REQUIRE(v2_constexpr.x == 1.f); REQUIRE(v2_constexpr.y == 2.f);
    REQUIRE(v2_constexpr.r == 1.f); REQUIRE(v2_constexpr.g == 2.f);
    REQUIRE(v3_constexpr.Dimension == 3);
    REQUIRE(v3_constexpr.x == 1.f); REQUIRE(v3_constexpr.y == 2.f); REQUIRE(v3_constexpr.z == 3.f);
    REQUIRE(v3_constexpr.r == 1.f); REQUIRE(v3_constexpr.g == 2.f); REQUIRE(v3_constexpr.b == 3.f);
    REQUIRE(v4_constexpr.Dimension == 4);
    REQUIRE(v4_constexpr.x == 1.f); REQUIRE(v4_constexpr.y == 2.f); REQUIRE(v4_constexpr.z == 3.f); REQUIRE(v4_constexpr.w == 4.f);
    REQUIRE(v4_constexpr.r == 1.f); REQUIRE(v4_constexpr.g == 2.f); REQUIRE(v4_constexpr.b == 3.f); REQUIRE(v4_constexpr.a == 4.f);
}

TEST_CASE("copy", "[Vec]") {
    MathiSMO::Vec v2{1.f, 2.f}; 
    MathiSMO::Vec v3{1.f, 2.f, 3.f};
    MathiSMO::Vec v4{1.f, 2.f, 3.f, 4.f};

    MathiSMO::Vec<float,2> v2_copy; 
    v2_copy = v2;
    MathiSMO::Vec<float,3> v3_copy; 
    v3_copy = v3;
    MathiSMO::Vec<float,4> v4_copy; 
    v4_copy = v4;

    REQUIRE(v2_copy.Dimension == 2);
    REQUIRE(v2_copy.x == 1.f); REQUIRE(v2_copy.y == 2.f);
    REQUIRE(v2_copy.r == 1.f); REQUIRE(v2_copy.g == 2.f);
    REQUIRE(v3_copy.Dimension == 3);
    REQUIRE(v3_copy.x == 1.f); REQUIRE(v3_copy.y == 2.f); REQUIRE(v3_copy.z == 3.f);
    REQUIRE(v3_copy.r == 1.f); REQUIRE(v3_copy.g == 2.f); REQUIRE(v3_copy.b == 3.f);
    REQUIRE(v4_copy.Dimension == 4);
    REQUIRE(v4_copy.x == 1.f); REQUIRE(v4_copy.y == 2.f); REQUIRE(v4_copy.z == 3.f); REQUIRE(v4_copy.w == 4.f);
    REQUIRE(v4_copy.r == 1.f); REQUIRE(v4_copy.g == 2.f); REQUIRE(v4_copy.b == 3.f); REQUIRE(v4_copy.a == 4.f);
}