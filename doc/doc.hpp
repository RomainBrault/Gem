/*!

@mainpage User Manual

@tableofcontents

@section tutorial-installation Prerequisites and installation

------------------------------------------------------------------------------
Gem is a header-only library using in your project doesn't require to go through
a heavy intallation set. Basically, just add the `include/` directory to your
compiler's header search path and you are done.If you want to cleanly install
Gem on your system, you can download the code from the official GitHub
[repository][Gem.repository] and install the library manually by issuing the
following commands from the root of the project
(requires [CMake][]):

@code{.sh}
mkdir build && cd build
cmake ..
cmake --build . --target install
@endcode

This will install Gem to the default install-directory for your platform
(`/usr/local` for Unix, `C:/Program Files` for Windows). If you want to
install Gem in a custom location, you can use

@code{.sh}
cmake .. -DCMAKE_INSTALL_PREFIX=/custom/install/prefix
@endcode

@note
- The manual installation will also install a `gem.pc` file for use
with [pkg-config][].

@subsection tutorial-installation-requirements Compiler requirements

The library relies on a C++17 compiler and standard library. Here is a table of
the current C++17 compilers/toolchains with comments regarding support for
Gem:

Compiler/Toolchain | Status
------------------ | ------
GCC >= 7.0.0       | Tested on each push to GitHub

More specifically, Hana requires a compiler/standard library supporting the
following C++17 features (non-exhaustively):
- generic lambdas,
- `constexpr` lambdas,
- generalized `constexpr`,
- variable templates,
- automatically deduced return type,
- all the C++17 type traits from the `<type_traits>` header.

<!-- Links -->
[Gem.repository]: https://github.com/RomainBrault/Gem
[Boost.Devel]: http://news.gmane.org/gmane.comp.lib.boost.devel
[Boost.Fusion]: http://www.boost.org/doc/libs/release/libs/fusion/doc/html/index.html
[Boost.MPL]: http://www.boost.org/doc/libs/release/libs/mpl/doc/index.html
[Boost.Steering]: https://sites.google.com/a/boost.org/steering/home
[Brigand]: https://github.com/edouarda/brigand
[C++14.auto_rt]: http://en.wikipedia.org/wiki/C%2B%2B14#Function_return_type_deduction
[C++14.gconstexpr]: http://en.wikipedia.org/wiki/C%2B%2B11#constexpr_.E2.80.93_Generalized_constant_expressions
[C++14.glambda]: http://en.wikipedia.org/wiki/C%2B%2B14#Generic_lambdas
[C++14.ice]: http://en.cppreference.com/w/cpp/types/integral_constant
[C++14.udl]: http://en.wikipedia.org/wiki/C%2B%2B11#User-defined_literals
[C++14.vtemplate]: http://en.wikipedia.org/wiki/C%2B%2B14#Variable_templates
[C++14]: http://en.wikipedia.org/wiki/C%2B%2B14
[C++17.clite]: http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3580.pdf
[C++Now]: http://cppnow.org
[Chandler.MeetingC++]: https://youtu.be/qkzaZumt_uk?t=4478
[CMake]: http://www.cmake.org
[constexpr_throw]: http://stackoverflow.com/a/8626450/627587
[CopyConstructible]: http://en.cppreference.com/w/cpp/concept/CopyConstructible
[GOTW]: http://www.gotw.ca/gotw/index.htm
[GSoC]: http://www.google-melange.com/gsoc/homepage/google/gsoc2014
[Hana.chat]: https://gitter.im/boostorg/hana
[Hana.contributing]: https://github.com/boostorg/hana/blob/master/CONTRIBUTING.md#how-to-contribute
[Hana.findmodule]: https://github.com/boostorg/hana/blob/master/cmake/FindHana.cmake
[Hana.hacking]: https://github.com/boostorg/hana/blob/master/README.md#hacking-on-hana
[Hana.issues]: https://github.com/boostorg/hana/issues
[Hana.repository]: https://github.com/boostorg/hana
[Hana.StackOverflow]: http://stackoverflow.com/questions/tagged/boost-hana
[Hana.wiki]: https://github.com/boostorg/hana/wiki
[Homebrew]: http://brew.sh
[lie-to-children]: http://en.wikipedia.org/wiki/Lie-to-children
[Metabench]: https://ldionne.github.io/metabench
[MPL.arithmetic]: http://www.boost.org/doc/libs/release/libs/mpl/doc/refmanual/arithmetic-operations.html
[MPL.metafunction]: http://www.boost.org/doc/libs/release/libs/mpl/doc/refmanual/metafunction.html
[MPL.mfc]: http://www.boost.org/doc/libs/release/libs/mpl/doc/refmanual/metafunction-class.html
[MPL11]: http://github.com/ldionne/mpl11
[N4461]: http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4461.html
[N4487]: https://isocpp.org/files/papers/N4487.pdf
[pkg-config]: http://www.freedesktop.org/wiki/Software/pkg-config/
[POD]: http://en.cppreference.com/w/cpp/concept/PODType
[SFINAE]: http://en.cppreference.com/w/cpp/language/sfinae
[slides.inst_must_go1]: https://github.com/boostcon/2010_presentations/raw/master/mon/instantiations_must_go.pdf
[slides.inst_must_go2]: https://github.com/boostcon/2010_presentations/raw/master/mon/instantiations_must_go_2.pdf
[SO.sfinae]: http://stackoverflow.com/a/257382/627587
[Sprout]: https://github.com/bolero-MURAKAMI/Sprout
[StackOverflow]: http://stackoverflow.com
[video.inst_must_go]: https://www.youtube.com/watch?v=x7UmrRzKAXU

*/