/* vim: set sw=4 sts=4 et foldmethod=syntax : */

/*
 * Copyright (c) 2022 Danny van Dyk
 * Copyright (c) 2022 Philip Lüghausen
 *
 * This file is part of the EOS project. EOS is free software;
 * you can redistribute it and/or modify it under the terms of the GNU General
 * Public License version 2, as published by the Free Software Foundation.
 *
 * EOS is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc., 59 Temple
 * Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef EOS_GUARD_EOS_FORM_FACTORS_B_LCDAS_FLVD2022_HH
#define EOS_GUARD_EOS_FORM_FACTORS_B_LCDAS_FLVD2022_HH 1

#include <eos/form-factors/b-lcdas.hh>
#include <eos/utils/diagnostics.hh>
#include <eos/utils/parameters.hh>
#include <eos/utils/options.hh>
#include <eos/utils/options-impl.hh>

#include <array>
#include <string>
#include <tuple>

namespace eos
{
    namespace b_lcdas
    {
        /*!
         * Parametrization of the B-meson LCDAs according to Ref. [FLvD:2022A]
         */
        class FLvD2022:
            public BMesonLCDAs
        {
            private:
                SwitchOption opt_q;
                SwitchOption opt_gminus;
                double switch_gminus;

                UsedParameter mu_0;
                UsedParameter omega_0;
                std::array<UsedParameter, 9> a; // at the scale mu_0

                std::string parameter(const char * _name) const;

            public:
                FLvD2022(const Parameters & parameters, const Options & options);
                virtual ~FLvD2022() = default;

                static BMesonLCDAs * make(const Parameters & parameters, const Options & options);

                /*!
                 * Parmeters of the B-Meson LCDA phi+ as defined in Ref. [FLvD:2022A]
                 *
                 * mu: the renormalization scale
                 */
                virtual std::tuple<BMesonLCDAs::CoefficientIterator, BMesonLCDAs::CoefficientIterator> coefficient_range(const double & mu) const final override;

                /*!
                 * Leading twist two-particle LCDAs
                 *
                 * omega: plus-component of the spectator momentum
                 */
                virtual double phi_plus(const double & omega) const final override;
                virtual double phi_minus(const double & omega) const final override;
                virtual double phi_bar(const double & omega) const final override;
                virtual double phi_bar_d1(const double & omega) const final override;

                /*!
                 * Next-to-leading twist two-particle LCDAs
                 *
                 * omega: plus-component of the spectator momentum
                 */
                virtual double g_plus(const double & omega) const final override;
                virtual double g_plus_d1(const double & omega) const final override;
                virtual double g_plus_d2(const double & omega) const final override;

                virtual double g_minusWW(const double & omega) const final override;
                virtual double g_minusWW_d1(const double & omega) const final override;
                virtual double g_minusWW_d2(const double & omega) const final override;

                virtual double g_bar(const double & omega) const final override;
                virtual double g_bar_d1(const double & omega) const final override;
                virtual double g_bar_d2(const double & omega) const final override;
                virtual double g_bar_d3(const double & omega) const final override;

                /*!
                 * Leading power three-particle LCDAs
                 *
                 * omega_1: plus-component of the spectator momentum
                 * omega_2: plus-component of the gluon momentum
                 */
                virtual double phi_3(const double & omega_1, const double & omega_2) const final override;
                virtual double phi_4(const double & omega_1, const double & omega_2) const final override;

                virtual double phi_bar_3(const double & omega_1, const double & omega_2) const final override;
                virtual double phi_bar_4(const double & omega_1, const double & omega_2) const final override;

                virtual double phi_bar2_3(const double & omega_1, const double & omega_2) const final override;
                virtual double phi_bar2_4(const double & omega_1, const double & omega_2) const final override;

                virtual double phi_bar_bar_3(const double & omega_1, const double & omega_2) const final override;
                virtual double phi_bar_bar_4(const double & omega_1, const double & omega_2) const final override;

                virtual double psi_bar_4(const double & omega_1, const double & omega_2) const final override;
                virtual double chi_bar_4(const double & omega_1, const double & omega_2) const final override;

                virtual double psi_bar_bar_4(const double & omega_1, const double & omega_2) const final override;
                virtual double chi_bar_bar_4(const double & omega_1, const double & omega_2) const final override;
                /*!
                * Pseudo observables for the two-particle LCDAs
                */
                virtual double inverse_lambda_plus() const final override;

                /*!
                 * Leading power three-particle LCDAs
                 *
                 * omega: plus-component of the spectator momentum
                 * xi:    plus-component of the gluon momentum
                 */
                virtual double psi_A(const double & omega, const double & xi) const final override;
                virtual double psi_V(const double & omega, const double & xi) const final override;
                virtual double X_A(const double & omega, const double & xi) const final override;
                virtual double Y_A(const double & omega, const double & xi) const final override;

                /*!
                * Auxiliary functions for the three-particle LCDAs
                *
                * See [KMO2006], below eq. (72), p. 28 for their definition.
                */
                virtual double Xbar_A(const double & omega, const double & xi) const final override;
                virtual double Ybar_A(const double & omega, const double & xi) const final override;

                /* Internal diagnostics */
                virtual Diagnostics diagnostics() const final override;
        };
    }
}

#endif
