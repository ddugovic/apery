/*
  Apery, a USI shogi playing engine derived from Stockfish, a UCI chess playing engine.
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008-2015 Marco Costalba, Joona Kiiski, Tord Romstad
  Copyright (C) 2015-2016 Marco Costalba, Joona Kiiski, Gary Linscott, Tord Romstad
  Copyright (C) 2011-2016 Hiraoka Takuya

  Apery is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Apery is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef APERY_TIMEMANAGER_HPP
#define APERY_TIMEMANAGER_HPP

#include "evaluate.hpp"

struct LimitsType;

class TimeManager {
public:
	void init(LimitsType& limits, const Ply currentPly, const Color us, Searcher* s);
	void pvInstability(const int currChanges, const int prevChanges);
	int availableTime() const { return optimumSearchTime_ + unstablePVExtraTime_; }
	int maximumTime() const { return maximumSearchTime_; }
	int optimumSearchTime() const { return optimumSearchTime_; } // todo: 後で消す。
	int elapsed() const { return startTime.elapsed(); }

private:
	Timer startTime;
	int optimumSearchTime_;
	int maximumSearchTime_;
	int unstablePVExtraTime_;
};

#endif // #ifndef APERY_TIMEMANAGER_HPP
