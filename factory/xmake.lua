set_languages("c++17")

add_rules("mode.debug", "mode.release")
target("factory")
    set_kind("binary")
    add_includedirs("$(buildir)")
    add_files("test.cc")