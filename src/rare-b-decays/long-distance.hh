/* vim: set sw=4 sts=4 et foldmethod=syntax : */

#ifndef EOS_GUARD_SRC_RARE_B_DECAYS_LONG_DISTANCE_HH
#define EOS_GUARD_SRC_RARE_B_DECAYS_LONG_DISTANCE_HH 1

#include <complex>

namespace eos
{
    using std::complex;

    struct LongDistance
    {
        static complex<double> g_had_ccbar(const double & s, const double & m_c);
    };
}

#endif
