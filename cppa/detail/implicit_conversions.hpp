/******************************************************************************\
 *           ___        __                                                    *
 *          /\_ \    __/\ \                                                   *
 *          \//\ \  /\_\ \ \____    ___   _____   _____      __               *
 *            \ \ \ \/\ \ \ '__`\  /'___\/\ '__`\/\ '__`\  /'__`\             *
 *             \_\ \_\ \ \ \ \L\ \/\ \__/\ \ \L\ \ \ \L\ \/\ \L\.\_           *
 *             /\____\\ \_\ \_,__/\ \____\\ \ ,__/\ \ ,__/\ \__/.\_\          *
 *             \/____/ \/_/\/___/  \/____/ \ \ \/  \ \ \/  \/__/\/_/          *
 *                                          \ \_\   \ \_\                     *
 *                                           \/_/    \/_/                     *
 *                                                                            *
 * Copyright (C) 2011, 2012                                                   *
 * Dominik Charousset <dominik.charousset@haw-hamburg.de>                     *
 *                                                                            *
 * This file is part of libcppa.                                              *
 * libcppa is free software: you can redistribute it and/or modify it under   *
 * the terms of the GNU Lesser General Public License as published by the     *
 * Free Software Foundation, either version 3 of the License                  *
 * or (at your option) any later version.                                     *
 *                                                                            *
 * libcppa is distributed in the hope that it will be useful,                 *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.                       *
 * See the GNU Lesser General Public License for more details.                *
 *                                                                            *
 * You should have received a copy of the GNU Lesser General Public License   *
 * along with libcppa. If not, see <http://www.gnu.org/licenses/>.            *
\******************************************************************************/


#ifndef IMPLICIT_CONVERSIONS_HPP
#define IMPLICIT_CONVERSIONS_HPP

#include <string>
#include <type_traits>

#include "cppa/self.hpp"
#include "cppa/actor.hpp"

#include "cppa/util/is_array_of.hpp"
#include "cppa/util/replace_type.hpp"

namespace cppa { class local_actor; }

namespace cppa { namespace detail {

template<typename T>
struct implicit_conversions
{
    typedef typename util::replace_type<T, std::string,
                                        std::is_same<T, char const*>,
                                        std::is_same<T, char*>,
                                        util::is_array_of<T, char>,
                                        util::is_array_of<T, const char> >::type
            subtype1;

    typedef typename util::replace_type<subtype1, std::u16string,
                                        std::is_same<subtype1, char16_t const*>,
                                        std::is_same<subtype1, char16_t*>,
                                        util::is_array_of<subtype1, char16_t>>::type
            subtype2;

    typedef typename util::replace_type<subtype2, std::u32string,
                                        std::is_same<subtype2, char32_t const*>,
                                        std::is_same<subtype2, char32_t*>,
                                        util::is_array_of<subtype2, char32_t>>::type
            subtype3;

    typedef typename util::replace_type<subtype3, actor_ptr,
                                        std::is_same<actor*,T>,
                                        std::is_same<local_actor*,T>,
                                        std::is_same<self_type,T>,
                                        std::is_same<self_type,T>>::type
            type;

};

} } // namespace cppa::detail

#endif // IMPLICIT_CONVERSIONS_HPP
