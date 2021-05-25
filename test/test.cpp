#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include "../Vec/Vec.hpp"

TEST_CASE("init", "[Vec]") {
    // basic
    thuw::Vec v2{1.f, 2.f};
    thuw::Vec v3{1.f, 2.f, 3.f};
    thuw::Vec v4{1.f, 2.f, 3.f, 4.f};

    // const
    const thuw::Vec v2_const{1.f, 2.f};
    const thuw::Vec v3_const{1.f, 2.f, 3.f};
    const thuw::Vec v4_const{1.f, 2.f, 3.f, 4.f};

    // constexpr
    constexpr thuw::Vec v2_constexpr{1.f, 2.f};
    constexpr thuw::Vec v3_constexpr{1.f, 2.f, 3.f};
    constexpr thuw::Vec v4_constexpr{1.f, 2.f, 3.f, 4.f};
}

TEST_CASE("init auto", "[auto Vec]") {
    // auto 
    auto v2 = thuw::Vec{1.f, 2.f};
    auto v3 = thuw::Vec{1.f, 2.f, 3.f};
    auto v4 = thuw::Vec{1.f, 2.f, 3.f, 4.f};

    // auto const
    const auto v2_const = thuw::Vec{1.f, 2.f};
    const auto v3_const = thuw::Vec{1.f, 2.f, 3.f};
    const auto v4_const = thuw::Vec{1.f, 2.f, 3.f, 4.f};

    // auto constexpr
    constexpr auto v2_constexpr = thuw::Vec{1.f, 2.f};
    constexpr auto v3_constexpr = thuw::Vec{1.f, 2.f, 3.f};
    constexpr auto v4_constexpr = thuw::Vec{1.f, 2.f, 3.f, 4.f};

    // auto universal reference
    auto&& v2_ref = thuw::Vec{1.f, 2.f};
    auto&& v3_ref = thuw::Vec{1.f, 2.f, 3.f};
    auto&& v4_ref = thuw::Vec{1.f, 2.f, 3.f, 4.f};

    // auto const ref
    const auto& v2_const_ref = thuw::Vec{1.f, 2.f};
    const auto& v3_const_ref = thuw::Vec{1.f, 2.f, 3.f};
    const auto& v4_const_ref = thuw::Vec{1.f, 2.f, 3.f, 4.f};

    // universal reference
    const auto&& v2_U_ref = thuw::Vec{1.f, 2.f};
    const auto&& v3_U_ref = thuw::Vec{1.f, 2.f, 3.f};
    const auto&& v4_U_ref = thuw::Vec{1.f, 2.f, 3.f, 4.f};
}

TEST_CASE("init alias", "[VecN]") {
    // alias
    thuw::Vec2 v2_alias{1.f, 2.f};
    thuw::Vec3 v3_alias{1.f, 2.f, 3.f};
    thuw::Vec4 v4_alias{1.f, 2.f, 3.f, 4.f};

    // const alias
    const thuw::Vec2 v2_alias_const{1.f, 2.f};
    const thuw::Vec3 v3_alias_const{1.f, 2.f, 3.f};
    const thuw::Vec4 v4_alias_const{1.f, 2.f, 3.f, 4.f};

    // constexpr alias
    constexpr thuw::Vec2 v2_alias_constexpr{1.f, 2.f};
    constexpr thuw::Vec3 v3_alias_constexpr{1.f, 2.f, 3.f};
    constexpr thuw::Vec4 v4_alias_constexpr{1.f, 2.f, 3.f, 4.f};
}

TEST_CASE("init template value", "[Vec<N>]") {
    // alias
    thuw::Vec<2> v2{1.f, 2.f};
    thuw::Vec<3> v3{1.f, 2.f, 3.f};
    thuw::Vec<4> v4{1.f, 2.f, 3.f, 4.f};

    // const alias
    const thuw::Vec<2> v2_const{1.f, 2.f};
    const thuw::Vec<3> v3_const{1.f, 2.f, 3.f};
    const thuw::Vec<4> v4_const{1.f, 2.f, 3.f, 4.f};

    // constexpr alias
    constexpr thuw::Vec<2> v2_constexpr{1.f, 2.f};
    constexpr thuw::Vec<3> v3_constexpr{1.f, 2.f, 3.f};
    constexpr thuw::Vec<4> v4_constexpr{1.f, 2.f, 3.f, 4.f};
}