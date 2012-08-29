/***************************************************************************
 *   Copyright (C) 2008-2012 by Andrzej Rybczak                            *
 *   electricityispower@gmail.com                                          *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.              *
 ***************************************************************************/

#ifndef _CONV_H
#define _CONV_H

#include <cstring>
#include <string>

#include "numeric_conversions.h"
#include "actions.h"
#include "window.h"
#include "mutable_song.h"
#include "song.h"

template <size_t N> inline size_t static_strlen(const char (&)[N])
{
	return N-1;
}

int StrToInt(const std::string &);
long StrToLong(const std::string &);

std::string IntoStr(mpd_tag_type);
std::string IntoStr(NCurses::Color);
std::string IntoStr(const Action::Key &key, bool *print_backspace = 0);

NCurses::Color IntoColor(const std::string &);

mpd_tag_type IntoTagItem(char);

MPD::Song::GetFunction toGetFunction(char c);

#ifdef HAVE_TAGLIB_H
MPD::MutableSong::SetFunction IntoSetFunction(mpd_tag_type);
#endif // HAVE_TAGLIB_H

std::string Shorten(const std::basic_string<my_char_t> &s, size_t max_length);

void EscapeUnallowedChars(std::string &);

#endif

